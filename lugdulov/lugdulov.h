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

#ifndef LUGDULOV_H
# define LUGDULOV_H

#include <qglobal.h>
#include <QtGui/QDialog>
#include <QtGui/QAction>
#include <QtGui/QAbstractItemView>

#include "config.h"

static inline void showAndDelete(QDialog *dialog)
{
#if defined(Q_WS_MAEMO_5)
  /* Can't use stacked windows with modal dialogs ...*/
  dialog->setAttribute(Qt::WA_DeleteOnClose, true);
  dialog->show();
#elif defined(Q_WS_S60) || defined(Q_WS_SIMULATOR)
  dialog->setAttribute(Qt::WA_DeleteOnClose, true);
  dialog->showMaximized();
#else
  dialog->exec();
  delete dialog;
#endif
}

static inline void setupDialog(QDialog *dialog, bool back = true)
{
#ifdef Q_WS_MAEMO_5
  dialog->setAttribute(Qt::WA_Maemo5StackedWindow);
  dialog->setAttribute(Qt::WA_Maemo5AutoOrientation, true);
#endif
#if defined(Q_WS_S60) || defined(Q_WS_SIMULATOR)

  if (back) {
      QAction* backAction = new QAction( QObject::tr("Back"), dialog);

      backAction->setSoftKeyRole( QAction::NegativeSoftKey );
      QObject::connect(backAction, SIGNAL(triggered()), dialog, SLOT(close()));
      dialog->addAction(backAction);
  }
#endif
}

#if defined(Q_WS_MAEMO_5)
#include <QtMaemo5/QtMaemo5>

static inline void installKineticScroller(QAbstractScrollArea *area)
{
  area->property("kineticScroller").value<QAbstractKineticScroller *>()->setEnabled(true);
}
#else

#if (QT_VERSION >= QT_VERSION_CHECK(4, 9, 0))
#include <QtGui/QScroller>
#include <QtGui/QScrollEvent>
#include <QtGui/QScrollPrepareEvent>
#else
#ifdef HAVE_KINETIC_SCROLLER_SOLUTION
#include <QtScroller>
#include <QtScrollEvent>
#include <QtScrollPrepareEvent>
#define QScroller QtScroller
#define QScrollEvent QtScrollEvent
#define QScrollPrepareEvent QtScrollPrepareEvent
#endif
#endif

static inline QScroller *installKineticScroller(QObject *target)
{
  bool touch = false;
  QScroller::ScrollerGestureType type;

  if (touch)
    type = QtScroller::TouchGesture;
  else
    type = QtScroller::LeftMouseButtonGesture;

  QScroller::grabGesture(target, type);
  return QScroller::scroller(target);
}

static inline QScroller *installKineticScroller(QAbstractItemView *view)
{
  view->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
  view->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
  return installKineticScroller(view->viewport());
}
#endif

#endif
