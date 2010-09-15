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

#include <QtCore/QtPlugin>

#include "factory.h"
#include "nurnberg.h"
#include "potsdam.h"
#include "hamburg.h"
#include "erlangen.h"
#include "offenbach_am_main.h"
#include "herne.h"
#include "bielefeld.h"
#include "friedrichshafen.h"
#include "hannover.h"
#include "offenburg.h"
#include "coburg.h"
#include "hamm.h"
#include "berlin.h"
#include "bottrop.h"
#include "frankfurt.h"
#include "furth.h"
#include "tubingen.h"
#include "kiel.h"
#include "koblenz.h"
#include "essen.h"
#include "gelsenkirchen.h"
#include "dusseldorf.h"
#include "leipzig.h"
#include "duisburg.h"
#include "bochum.h"
#include "koln.h"
#include "munchen.h"
#include "mulheim_adr.h"
#include "oberhausen.h"
#include "lubeck.h"
#include "dortmund.h"
#include "erfurt.h"
#include "dresden.h"
#include "aschaffenburg.h"
#include "magdeburg.h"
#include "flensburg.h"


QString
StationsPluginFactoryGermany::id() const
{
  return QLatin1String("Germany");
}

QString
StationsPluginFactoryGermany::name() const
{
  return QString::fromUtf8("Germany");
}

QIcon
StationsPluginFactoryGermany::icon() const
{
  return QIcon(":/germany/de.png");
}

QList < StationsPlugin * >
StationsPluginFactoryGermany::stations(QObject *parent)
{
  QList < StationsPlugin * > ret;

  ret << new StationsPluginNurnberg(parent);
  ret << new StationsPluginPotsdam(parent);
  ret << new StationsPluginHamburg(parent);
  ret << new StationsPluginErlangen(parent);
  ret << new StationsPluginOffenbach_Am_Main(parent);
  ret << new StationsPluginHerne(parent);
  ret << new StationsPluginBielefeld(parent);
  ret << new StationsPluginFriedrichshafen(parent);
  ret << new StationsPluginHannover(parent);
  ret << new StationsPluginOffenburg(parent);
  ret << new StationsPluginCoburg(parent);
  ret << new StationsPluginHamm(parent);
  ret << new StationsPluginBerlin(parent);
  ret << new StationsPluginBottrop(parent);
  ret << new StationsPluginFrankfurt(parent);
  ret << new StationsPluginFurth(parent);
  ret << new StationsPluginTubingen(parent);
  ret << new StationsPluginKiel(parent);
  ret << new StationsPluginKoblenz(parent);
  ret << new StationsPluginEssen(parent);
  ret << new StationsPluginGelsenkirchen(parent);
  ret << new StationsPluginDusseldorf(parent);
  ret << new StationsPluginLeipzig(parent);
  ret << new StationsPluginDuisburg(parent);
  ret << new StationsPluginBochum(parent);
  ret << new StationsPluginKoln(parent);
  ret << new StationsPluginMunchen(parent);
  ret << new StationsPluginMulheim_Adr(parent);
  ret << new StationsPluginOberhausen(parent);
  ret << new StationsPluginLubeck(parent);
  ret << new StationsPluginDortmund(parent);
  ret << new StationsPluginErfurt(parent);
  ret << new StationsPluginDresden(parent);
  ret << new StationsPluginAschaffenburg(parent);
  ret << new StationsPluginMagdeburg(parent);
  ret << new StationsPluginFlensburg(parent);

  return ret;
}

Q_EXPORT_PLUGIN2(stationsgermany, StationsPluginFactoryGermany)
