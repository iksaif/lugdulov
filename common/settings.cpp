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

#include <QtGui/QDesktopServices>
#include <QtCore/QCoreApplication>
#include <QtCore/QFileInfo>
#include <QtCore/QDir>

#include "settings.h"
#include "station.h"
#include "stationsplugin.h"

Settings *Settings::instance_ = NULL;

Settings::Settings(QObject *parent)
  : QSettings(QSettings::IniFormat, QSettings::UserScope,
	      QCoreApplication::organizationName(),
	      QCoreApplication::applicationName(),
	      parent)
{
}

Settings::~Settings()
{

}

Settings *
Settings::settings()
{
  if (!instance_) {
    instance_ = new Settings();

    if (instance_->value("version") != QCoreApplication::applicationVersion()) {
      instance_->setValue("version", QCoreApplication::applicationVersion());
      instance_->sync();
    }
  }

  return instance_;
}

QString
Settings::path()
{
  Settings *conf = settings();

  return QFileInfo(conf->fileName()).dir().canonicalPath();
}

bool
Settings::bookmarked(Station *station)
{
  bool ret;

  Settings *conf = Settings::settings();

  conf->beginGroup("Bookmarks");
  conf->beginGroup(station->plugin()->id());
  ret = conf->value(QString("%1").arg(station->id())).toBool();
  conf->endGroup();
  conf->endGroup();
  return ret;
}

void
Settings::bookmark(Station *station, bool bookmark)
{
  Settings *conf = Settings::settings();
  QString key("%1");

  key = key.arg(station->id());

  conf->beginGroup("Bookmarks");
  conf->beginGroup(station->plugin()->id());
  if (bookmark)
    conf->setValue(key, true);
  else
    conf->remove(key);
  conf->endGroup();
  conf->endGroup();
}

QList < int >
Settings::bookmarks(StationsPlugin *plugin)
{
  Settings conf;
  QList < int > ret;

  conf.beginGroup("Bookmarks");
  conf.beginGroup(plugin->id());
  foreach (QString id, conf.childKeys())
    ret << id.toInt();
  conf.endGroup();
  conf.endGroup();
  return ret;
}

static bool removeDir(const QString &dirName)
{
  bool result = true;
  QDir dir(dirName);
  QFlags<QDir::Filter> flags = QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files;

  if (!dir.exists())
    return result;

  foreach (QFileInfo info, dir.entryInfoList(flags, QDir::DirsFirst)) {
    if (info.isDir())
      result = removeDir(info.absoluteFilePath());
    else
      result = QFile::remove(info.absoluteFilePath());
    if (!result)
	return result;
    result = dir.rmdir(dirName);
  }
  return result;
}

void
Settings::clearCache(void)
{
  removeDir(QDesktopServices::storageLocation(QDesktopServices::CacheLocation));
}


