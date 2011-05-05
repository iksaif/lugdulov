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

#ifndef SETTINGS_H
# define SETTINGS_H

#include <QtCore/QSettings>

class Station;
class StationsPlugin;

class Settings : public QSettings {
  Q_OBJECT
public:
  Settings(QObject * parent = 0);
  ~Settings();
  static Settings *settings();
  static QString path();
  static bool bookmarked(Station *station);
  static void bookmark(Station *station, bool bookmark);
  static QList < int > bookmarks(StationsPlugin *plugin);

private:
  static Settings *instance_;
};

#endif

