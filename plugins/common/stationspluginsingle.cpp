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
