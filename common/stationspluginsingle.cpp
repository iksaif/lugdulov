#include "stationspluginsingle.h"

StationsPluginSingle::StationsPluginSingle(QObject *parent)
  : StationsPluginSimple(parent)
{
}

StationsPluginSingle::~StationsPluginSingle()
{
}

void
StationsPluginSingle::update(Station *station)
{
  fetchOnline();
}

void
StationsPluginSingle::update(const QList < Station * > & stations)
{
  fetchOnline();
}

QUrl
StationsPluginSingle::statusUrl(int id)
{
  Q_UNUSED(id);

  return QUrl();
}

void
StationsPluginSingle::handleStatus(const QByteArray & data, int id)
{
  Q_UNUSED(data);
  Q_UNUSED(id);
}

void
StationsPluginSingle::updateCached(Station *station)
{
  QTime time = QTime::currentTime().addMSecs(-30000);
  QTime now = QTime::currentTime();
  QList <Station * > stations;

  stations << station;

  if (updated[NULL] > time)
    emit stationsUpdated(stations);
  else {
    update(station);
    updated[NULL] = now;
  }
}

void
StationsPluginSingle::updateCached(const QList < Station * > & stations)
{
  QTime time = QTime::currentTime().addMSecs(-30000);
  QTime now = QTime::currentTime();

  if (updated[NULL] > time)
    emit stationsUpdated(stations);
  else {
    update(stations);
    updated[NULL] = now;
  }
}

