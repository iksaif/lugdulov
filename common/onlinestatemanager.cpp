/*
 * Copyright (C) 2010-2011 Corentin Chary <corentin.chary@gmail.com>
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

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

#include "mobility.h"
#include "tools.h"
#include "onlinestatemanager.h"

OnlineStateManager *OnlineStateManager::_instance;

OnlineStateManager *
OnlineStateManager::instance()
{
  if (!_instance)
    _instance = new OnlineStateManager();
  return _instance;
}


OnlineStateManager::OnlineStateManager(QObject * parent)
    : QObject(parent)
{
  am = new QNetworkAccessManager(this);
  manager = new QNetworkConfigurationManager(this);
  connect(manager, SIGNAL(onlineStateChanged(bool)), this, SLOT(setOnlineState(bool)));
  setOnlineState(manager->isOnline());
}

OnlineStateManager::~OnlineStateManager()
{
}

bool
OnlineStateManager::isOnline() const
{
  return online;
}

void
OnlineStateManager::setOnlineState(bool onlineState)
{
  online = onlineState;
  emit onlineStateChanged(onlineState);
}

void
OnlineStateManager::doOnlineTest(const QUrl & url)
{
  QNetworkRequest req(url);
  QNetworkReply *rep;

  Tools::fixupRequest(&req);
  req.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::AlwaysNetwork);

  rep = am->get(req);
  connect(rep, SIGNAL(finished()), this, SLOT(onlineTestFinished()));
}

void
OnlineStateManager::onlineTestFinished(void)
{
  QNetworkReply *rep = (QNetworkReply *)sender();
  bool ok;

  ok = rep->error() == QNetworkReply::NoError;
  if (ok)
    setOnlineState(ok);
  emit onlineTestFinished(rep->url(), rep->readAll(), ok);
}
