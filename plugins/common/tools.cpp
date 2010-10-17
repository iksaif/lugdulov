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

#include "config.h"

#include "tools.h"
#include "onlinestatemanager.h"

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
  if (!isOnline())
    request->setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::AlwaysCache);
#if defined(Q_WS_MAEMO_5)
  request->setRawHeader("User-Agent", "Mozilla/5.0 (X11; U; Linux armv7l; fr-FR; rv:1.9.2b6pre) Gecko/20100318 Firefox/3.5 Maemo Browser 1.7.4.8 RX-51 N900");
#elif defined(Q_WS_S60)
  request->setRawHeader("User-Agent", "Mozilla/5.0 (SymbianOS/9.4; Series60/5.0 NokiaN97-1/12.0.024; Profile/MIDP-2.1 Configuration/CLDC-1.1; en-us)"
		       "AppleWebKit/525 (KHTML, like Gecko) BrowserNG/7.1.12344");
#endif
}

bool
Tools::isOnline()
{
    return OnlineStateManager::instance()->isOnline();
}
