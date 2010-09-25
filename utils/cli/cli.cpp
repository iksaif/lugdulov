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

#include <QtCore/QCoreApplication>
#include <QtCore/QTimer>
#include <QtCore/QVariant>
#include <QtCore/QDebug>

#include "cli.h"

static const struct QCommandLineConfigEntry conf[] =
  {
    { QCommandLine::Switch, 'l', "list", "List available plugins", QCommandLine::Optional },
    { QCommandLine::Switch, 's', "status", "Fetch status (default)", QCommandLine::Optional },
    { QCommandLine::Switch, 'i', "infos", "Fetch informations", QCommandLine::Optional },
    { QCommandLine::Option, 'f', "fmt", "Output format (xml, json (default))", QCommandLine::Optional },
    { QCommandLine::Param, '\0', "plugin", "Fetch informations for that plugin", QCommandLine::OptionalMultiple },
    QCOMMANDLINE_CONFIG_ENTRY_END
  };

Cli::Cli(QObject *parent)
  : QObject(parent)
{
  cmdline = new QCommandLine(this);
  cmdline->setConfig(conf);
  cmdline->enableVersion(true); // enable -v // --version
  cmdline->enableHelp(true); // enable -h / --help

  connect(cmdline, SIGNAL(switchFound(const QString &)),
	  this, SLOT(switchFound(const QString &)));
  connect(cmdline, SIGNAL(optionFound(const QString &, const QVariant &)),
	  this, SLOT(optionFound(const QString &, const QVariant &)));
  connect(cmdline, SIGNAL(paramFound(const QString &, const QVariant &)),
	  this, SLOT(paramFound(const QString &, const QVariant &)));
  connect(cmdline, SIGNAL(parseError(const QString &)),
	  this, SLOT(parseError(const QString &)));

  action = List;
  format = Json;

  cmdline->parse();

  QTimer::singleShot(0, this, SLOT(run()));
}

Cli::~Cli()
{
}

void
Cli::switchFound(const QString & name)
{
  if (name == "list")
    action = List;
  if (name == "status")
    action = Status;
  if (name == "infos")
    action = Infos;
}

void
Cli::optionFound(const QString & name, const QVariant & value)
{
  if (name == "fmt") {
    QString fmt = value.toString();

    if (value == "json")
      format = Json;
    else if (value == "xml")
      format = Xml;
    else
      parseError("Invalid format, must be json or xml");
  }
}

void
Cli::paramFound(const QString & name, const QVariant & value)
{
  if (name == "plugin")
    plugins << value.toString();
}

void
Cli::parseError(const QString & error)
{
  qWarning() << qPrintable(error);
  cmdline->showHelp(true, -1);
  QCoreApplication::quit();
}

void
Cli::run()
{
  /*
   * Créer les plugins
   * Liste:
   *  lister les plugins avec id-name
   * Infos:
   *  Pour tout les plugins, choper les infos des plugins
   * Status:
   *  Lancer un update sur tout les plugins, puis quand tout est finit, afficher le résultat
   */
  qDebug() << action << format << plugins;
  QCoreApplication::instance()->quit();
}
