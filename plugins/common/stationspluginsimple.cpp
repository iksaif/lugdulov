/*
 * Copyright (C) 2010 Corentin Chary <corentin.chary@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <QtNetwork/QNetworkReply>
#include <QtGui/QDesktopServices>
#include <QtCore/QMap>
#include <QtCore/QVariant>
#include <QtCore/QFile>
#include <QtCore/QtPlugin>
#include <QtCore/QStringList>
#include <QtXml/QDomNode>

#include <QtCore/QDebug>

#include "station.h"
#include "tools.h"
#include "stationspluginsimple.h"
#include "stationspluginsimple_p.h"

StationsPluginSimple::StationsPluginSimple(QObject *parent)
  : StationsPlugin(parent)
{
  nm = new QNetworkAccessManager(this);
  count = 0;
  step = 0;
  d = NULL;
  connect(nm, SIGNAL(sslErrors(QNetworkReply *, const QList<QSslError> &)),
	  this, SLOT(ignoreSslErros(QNetworkReply *, const QList<QSslError> &)));
}

StationsPluginSimple::~StationsPluginSimple()
{
  qDeleteAll(stations);
}

QRectF
StationsPluginSimple::rect() const
{
  return d->rect;
}


QPointF
StationsPluginSimple::center() const
{
  return d->center;
}

void
StationsPluginSimple::fetchFromFile(const QString &filename)
{
  QFile fp(filename);

  fp.open(QIODevice::ReadOnly);
  handleInfos(fp.readAll());
  fp.close();
}

void
StationsPluginSimple::fetchAll()
{
  QList < Station * > list = d->fetchAll(this);

  foreach (Station *station, list) {
    if (stations.find(station->id()) == stations.end())
      stations.insert(station->id(), station);
    else
      delete station;
  }

  emit stationsCreated(stations.values());
}

void
StationsPluginSimple::fetchFromUrl(const QUrl &url)
{
  request(url, -1);
}

void
StationsPluginSimple::fetchOnline()
{
  request(infosUrl(), -1);
}

void
StationsPluginSimple::update(Station *station)
{
  request(statusUrl(station->id()), station->id());
}

void
StationsPluginSimple::update(const QList < Station * > & stations)
{
  foreach (Station *station, stations)
    update(station);
}

void
StationsPluginSimple::ignoreSslErros(QNetworkReply *rep, const QList<QSslError> &errors)
{
  Q_UNUSED(errors);
  rep->ignoreSslErrors();
}

void
StationsPluginSimple::networkError(QNetworkReply::NetworkError code)
{
  QNetworkReply *rep = dynamic_cast<QNetworkReply *>(sender());

  if (rep) {
    if (Tools::isOnline())
        emit error(tr("Network Error"), rep->errorString());
    step++;
    replies.remove(rep);
    rep->deleteLater();
  }
}

void
StationsPluginSimple::finished()
{
  QNetworkReply *rep = dynamic_cast<QNetworkReply *>(sender());
  int id = replies[rep];

  if (rep)
    rep->deleteLater();

  if (!rep) {
    step++;
    replies.remove(rep);
    return ;
  }

  if (id >= 0)
    handleStatus(rep->readAll(), id);
  else
    handleInfos(rep->readAll());

  step++;
  emit progress(step, count);

  replies.remove(rep);

  if (step == count) {
    step = 0;
    count = 0;
    emit done();
  }
}

void
StationsPluginSimple::request(const QUrl & url, int id)
{
  QNetworkReply *rep;
  QNetworkRequest req(url);

  Tools::fixupRequest(&req);
  rep = nm->get(req);

  connect(rep, SIGNAL(error(QNetworkReply::NetworkError)),
          this, SLOT(networkError(QNetworkReply::NetworkError)));
  connect(rep, SIGNAL(finished()), this, SLOT(finished()));

  if (count == 0) {
    emit started();
    step = 0;
  }
  replies[rep] = id;
  count++;
}

QUrl
StationsPluginSimple::statusUrl(int id)
{
  return d->statusUrl.arg(id);
}

QUrl
StationsPluginSimple::infosUrl()
{
  return d->infosUrl;
}

QUrl
StationsPluginSimple::imageUrl(int id)
{
  return QUrl();
}

QStringList
StationsPluginSimple::regions()
{
  return d->regions();
}

QList < QAction * >
StationsPluginSimple::actions()
{
  QList < QAction * > ret;

  return ret;
}

void
StationsPluginSimple::actionTriggered(QAction *action, Station *station, QWidget *parent)
{
}

