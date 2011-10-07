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

#include "config.h"

#include "mobility.h"

#include "lugdulov.h"
#include "ui_settingsdialog.h"
#include "settingsdialog.h"
#include "settings.h"

SettingsDialog::SettingsDialog(QWidget *parent)
  :
#ifdef Q_WS_MAEMO_5
  QDialog(parent, Qt::Window),
#else
  QDialog(parent),
#endif
  ui(new Ui_SettingsDialog())
{
  ui->setupUi(this);
  setupDialog(this);

#if !defined(USE_QMAPCONTROL) && !defined(LUGDULOV_LITE)
  QStringList providers = QGeoServiceProvider::availableServiceProviders();

  if (providers.contains("google"))
      ui->comboBox->addItem(tr("Google Maps"), "google");
  if (providers.contains("openstreetmap")) {
      ui->comboBox->addItem(tr("Open Street Map"), "openstreetmap");
      ui->comboBox->addItem(tr("Open Cycle Map"), "opencyclemap");
  }
  if (providers.contains("nokia"))
      ui->comboBox->addItem(tr("Ovi Maps (Nokia)"), "nokia");
  if (providers.contains("cloudmade"))
      ui->comboBox->addItem(tr("Cloudmade"), "cloudmade");
#else
# if !defined(Q_OS_SYMBIAN) /* Doesn't seems to work on symbian */
  ui->comboBox->addItem(tr("Google Maps"), "google");
# endif
  ui->comboBox->addItem(tr("Open Street Map"), "openstreetmap");
  ui->comboBox->addItem(tr("Open Cycle Map"), "opencyclemap");
#endif

  Settings conf;
  int idx;

  if ((idx = ui->comboBox->findData(conf.value("MapProvider", "opencyclemap"))) != -1)
    ui->comboBox->setCurrentIndex(idx);

  if (conf.value("GpsPowerSave").toBool())
    ui->checkBox->setCheckState(Qt::Checked);

#if !defined(HAVE_QT_LOCATION)
  ui->checkBox->hide();
#endif

  connect(ui->clearCacheButton, SIGNAL(clicked()), this, SLOT(clearCache()));
}

SettingsDialog::~SettingsDialog()
{
  delete ui;
}

void
SettingsDialog::saveSettings() const
{
  Settings conf;
  QString provider;

  provider = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
  conf.setValue("MapProvider", provider);
  conf.setValue("GpsPowerSave", ui->checkBox->checkState() == Qt::Checked);
}

void
SettingsDialog::clearCache()
{
  ui->clearCacheButton->setDisabled(true);
  Settings::clearCache();
  ui->clearCacheButton->setEnabled(true);
}
