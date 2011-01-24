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
#include <QtCore/QDir>
#include <QtXml/QDomNode>

#include <QtCore/QDebug>

#include "station.h"
#include "tools.h"
#include "stationspluginsimple.h"
#include "stationspluginsimple_p.h"

StationsPluginSimple::StationsPluginSimple(QObject *parent)
  : StationsPlugin(parent)
{
  count = 0;
  step = 0;
  d = NULL;
  nm = false;
  cacheLoaded = false;
}

StationsPluginSimple::~StationsPluginSimple()
{
  if (!stations.isEmpty())
    saveDiskCache();
  qDeleteAll(stations);
}

void
StationsPluginSimple::initNetwork(void)
{
  if (nm)
    return ;

  nm = new QNetworkAccessManager(this);
  connect(nm, SIGNAL(sslErrors(QNetworkReply *, const QList<QSslError> &)),
	  this, SLOT(ignoreSslErrors(QNetworkReply *, const QList<QSslError> &)));
  connect(nm, SIGNAL(finished(QNetworkReply *)), this, SLOT(finished(QNetworkReply *)));
}

QRectF
StationsPluginSimple::rect() const
{
  Q_ASSERT(d);
  return d->rect;
}


QPointF
StationsPluginSimple::center() const
{
  Q_ASSERT(d);
  return d->center;
}

QString
StationsPluginSimple::id() const
{
  Q_ASSERT(d);
  return d->id;
}

QString
StationsPluginSimple::name() const
{
  Q_ASSERT(d);
  return d->name;
}

QString
StationsPluginSimple::bikeName() const
{
  Q_ASSERT(d);
  return d->bikeName;
}

QIcon
StationsPluginSimple::bikeIcon() const
{
  Q_ASSERT(d);
  return d->bikeIcon;
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
  if (!cacheLoaded) {
    QFile file(diskCache());

    if (file.exists()) {
	  qDebug() << "Loading cache" << file.fileName();
      loadDiskCache(file.fileName());
	  if (stations.isEmpty())
	    fetchOnline();
	  else
        emit stationsCreated(stations.values());
    } else
      fetchOnline();

    cacheLoaded = true;
  } else {
    emit stationsCreated(stations.values());
  }
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
StationsPluginSimple::ignoreSslErrors(QNetworkReply *rep, const QList<QSslError> &errors)
{
  Q_UNUSED(errors);
  rep->ignoreSslErrors();
}

void
StationsPluginSimple::networkError(QNetworkReply::NetworkError code)
{
  QNetworkReply *rep = qobject_cast<QNetworkReply *>(sender());

  if (rep) {
    qDebug() << "Network Error" << rep->errorString();
    if (Tools::isOnline())
        emit error(tr("Network Error"), rep->errorString());
    step++;
    replies.remove(rep);
    rep->deleteLater();
  }
}

void
StationsPluginSimple::finished(QNetworkReply *rep)
{
  int id;

  qDebug() << "Url loaded" << rep->url().toString();

  if (!replies.contains(rep))
    return ;

  rep->deleteLater();
  id = replies[rep];

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
  if (url.isEmpty())
    return ;

  qDebug() << "Loading url" << url.toString()
           << "( online:" << Tools::isOnline() << ")";

  QNetworkReply *rep;
  QNetworkRequest req(url);

  initNetwork();

  Tools::fixupRequest(&req);
  rep = nm->get(req);

  connect(rep, SIGNAL(error(QNetworkReply::NetworkError)),
          this, SLOT(networkError(QNetworkReply::NetworkError)));

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

Station *
StationsPluginSimple::getOrCreateStation(int id)
{
  Station *station;

  if (stations.contains(id))
    station = stations[id];
  else {
    station = new Station(this);
    station->setId(id);
  }

  return station;
}

void
StationsPluginSimple::storeOrDropStation(Station *station)
{
  if (!station || station->id() < 0)
    goto drop;

  if (stations.contains(station->id()))
    goto store;

  if (!station->pos().isNull() && !rect().contains(station->pos()))
    goto drop;

  if (station->name().isEmpty())
    goto drop;

 store:
  if (station->name().isEmpty())
    station->setName(QString(tr("Station %1").arg(station->id())));

  stations[station->id()] = station;
  return ;

 drop:
  delete station;
}

QString
StationsPluginSimple::diskCache()
{
  QString cache = QDesktopServices::storageLocation(QDesktopServices::CacheLocation);
  QDir dir;

  dir.mkpath(cache);
  return cache + "/" + id() + ".xml";
}

void
StationsPluginSimple::saveDiskCache()
{
  QFile file(diskCache());

  file.open(QIODevice::WriteOnly);

  file.write("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
  file.write("<stations>\n");

  foreach (Station *station, stations) {
    QString data =
      "  <station id=\"%1\">\n"
      "   <name>%2</name>\n"
      "   <description>%3</description>\n"
      "   <latitude>%4</latitude>\n"
      "   <longitude>%5</longitude>\n"
      "  </station>\n";

    file.write(data.arg(station->id())
	       .arg(station->name())
	       .arg(station->description())
	       .arg(station->pos().x())
	       .arg(station->pos().y())
	       .toUtf8());
  }
  file.write("</stations>\n");
}

void
StationsPluginSimple::loadOverride(const QString & file)
{
  loadDiskCache(file);
}

void
StationsPluginSimple::loadDiskCache(const QString & path)
{
  QFile file(path);
  QDomDocument doc;
  QDomNode node;

  if (!file.exists())
    return ;

  file.open(QIODevice::ReadOnly);
  doc.setContent(&file);

  loadStations(doc.firstChildElement("stations"));
}

void
StationsPluginSimple::loadStations(QDomNode node)
{
  QRectF area = rect();

  if (node.isNull())
    return ;

  node = node.firstChildElement("station");

  while (!node.isNull()) {
    bool ok;
    int id;
    QString name, description;
    double latitude, longitude;

    id = node.toElement().attribute("id").toInt(&ok);
    name = node.firstChildElement("name").text();
    description = node.firstChildElement("description").text();
    latitude = node.firstChildElement("latitude").text().toDouble();
    longitude = node.firstChildElement("longitude").text().toDouble();

    node = node.nextSiblingElement("station");

    if (!ok || id < 0)
      continue ;

    if (latitude && longitude) {
      if (!area.contains(latitude, longitude))
	continue ;
    } else if (latitude && !area.contains(latitude, area.center().y())) {
      continue ;
    } else if (longitude && !area.contains(area.center().x(), longitude)) {
      continue ;
    }

    Station *station = getOrCreateStation(id);

    if (station->name().isEmpty())
      station->setName(name);

    if (station->description().isEmpty())
      station->setDescription(description);

    if (station->pos().isNull())
      station->setPos(QPointF(latitude, longitude));
    else if (station->pos().x() == 0)
      station->setPos(QPointF(latitude, station->pos().y()));
    else if (station->pos().y() == 0)
      station->setPos(QPointF(station->pos().x(), longitude));

    stations[id] = station;
  }
}
