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

#include <QtCore/QStringList>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

#include "tools.h"

void
Tools::setOnlineState(bool state)
{
  online = state;
}

bool
Tools::onlineState(void)
{
  return online;
}

bool Tools::online = false;

QString
Tools::ucFirst(const QString & str)
{
  if (str.isEmpty())
    return str;

  QStringList tokens = str.toLower().split(" ");
  QList<QString>::iterator tokItr = tokens.begin();

  for (tokItr = tokens.begin(); tokItr != tokens.end(); ++tokItr) {
    if (tokItr->isEmpty())
      continue ;
    (*tokItr)[0] = (*tokItr).at(0).toUpper();
  }
  return tokens.join(" ");
}

void
Tools::fixupRequest(QNetworkRequest * request)
{
  if (!onlineState())
    request->setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::AlwaysCache);
  //request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");
}
