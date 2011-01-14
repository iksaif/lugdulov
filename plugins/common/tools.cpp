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
#include <QtCore/QCoreApplication>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

#include "config.h"

#include "tools.h"
#if defined(HAVE_QT_BEARER)
#include "onlinestatemanager.h"
#endif

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
#if defined(Q_WS_MAEMO_5)
    request->setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::AlwaysCache);
#elif defined(Q_OS_SYMBIAN)
    /* isOnline doesn't always work on symbian :/ */
    request->setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferCache);
#else
    /* FIXME, may work correctly on win32 and osx, need to test */
    ; /* Do nothing ... */
#endif

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
#if defined(HAVE_QT_BEARER)
    return OnlineStateManager::instance()->isOnline();
#else
    return true;
#endif
}
#include <QDebug>
QDir
Tools::pluginsPath(void)
{
  QDir dir = QCoreApplication::applicationDirPath();

#if defined(Q_OS_MAC)
  if (dir.dirName() == "MacOS") {
    dir.cdUp();
  }
  dir.cd("plugins");
  dir.cd("lugdulov");
#elif defined(Q_OS_WIN32)
  dir.cd("plugins");
  dir.cd("lugdulov");
#else
  dir.cdUp();
  dir.cd("lib");
  dir.cd("lugdulov");
  dir.cd("plugins");
#endif
qWarning() << dir.canonicalPath();
  return dir;
}
