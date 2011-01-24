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

#include <QtGui/QApplication>
#include <QtGui/QDesktopWidget>
#include <QtGui/QPainter>
#include <QtCore/QDebug>

#include "config.h"

#include "stationdelegate.h"
#include "stationsmodel.h"
#include "stationssortfilterproxymodel.h"
#include "stationsplugin.h"
#include "station.h"

StationDelegate::StationDelegate(QObject *parent)
  : QStyledItemDelegate(parent)
{
}

StationDelegate::~StationDelegate()
{
}

void
StationDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
		       const QModelIndex &index) const
{
  Station *station = (Station *)index.data(StationsModel::StationRole).value<void *>();
  QString description, name;

  if (!station)
    return QStyledItemDelegate::paint(painter, option, index);

  painter->save();

  QPen pen = painter->pen();
  QFont font = painter->font();
  QStyleOptionViewItemV2 optionv2 = QStyleOptionViewItemV2(option);

  QPalette::ColorGroup cg = option.state & QStyle::State_Enabled
    ? QPalette::Normal : QPalette::Disabled;

  if (cg == QPalette::Normal && !(option.state & QStyle::State_Active))
    cg = QPalette::Inactive;

  if (option.state & QStyle::State_Selected) {
    painter->setPen(option.palette.color(cg, QPalette::HighlightedText));
  } else {
    painter->setPen(option.palette.color(cg, QPalette::Text));
  }

  QApplication::style()->drawPrimitive(QStyle::PE_PanelItemViewItem, &option, painter);

  font = option.font;
  font.setBold(true);

  QRectF rect = option.rect;

  rect.setHeight(rect.height() - 10);
  rect.setTop(rect.top() + 5);

  painter->setFont(font);
  name = station->name();
  if (QFontMetrics(font).width(name) > option.rect.width()) {
      QFontMetrics fm(font);
      qreal size = qMax(0, option.rect.width());

      size /= fm.averageCharWidth();
      size -= QString::fromLatin1(" ... ").size();
      name = station->name().left(size);
      name += QLatin1String("...");
  }
  painter->drawText(rect, Qt::AlignLeft|Qt::AlignTop, name);

  if (index.data(StationsModel::StationBookmarkRole).toBool()) {
    QPixmap bookmark = QPixmap(":/res/favorites.png").scaled(16, 16, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPoint pt(QFontMetrics(font).width(station->name()) + 5, rect.top());

    painter->drawPixmap(pt, bookmark);
  }

  font.setBold(false);
#ifdef Q_WS_MAEMO_5
  font.setPointSize(10);
#else
  font.setPointSize(font.pointSize() - 1);
#endif
  painter->setFont(font);

  qreal distance = index.data(StationsSortFilterProxyModel::StationDistanceRole).toDouble();
  QString distanceText;

#if !defined(Q_WS_S60) && !defined(Q_WS_SIMULATOR)
  if (distance >= 0)
    distanceText.sprintf(" (%dm)", (int)distance);

  description = station->description();
  description += distanceText;
  if (QFontMetrics(font).width(description) > option.rect.width()) {
      QFontMetrics fm(font);
      qreal size = qMax(0, option.rect.width() - fm.width(distanceText));

      size /= fm.averageCharWidth();
      size -= QString::fromLatin1(" ... ").size();
      description = station->description().left(size);
      description += QLatin1String("...");
      description += distanceText;
  }

  painter->drawText(rect, Qt::AlignLeft|Qt::AlignBottom, description);
#endif

  font.setPointSize(option.font.pointSize());
  painter->setFont(font);

  QString slotText;
  QString bikeText;
  QString fakeText = QLatin1String("00");

  if (station->freeSlots() >= 0)
    slotText = QString("%1").arg(station->freeSlots());
  if (station->bikes() >= 0)
    bikeText = QString("%1").arg(station->bikes());

  QPointF pt;
  QPixmap slot(":/res/slot.png");
  QPixmap bike = station->plugin()->bikeIcon().pixmap(slot.size());
  QFontMetrics fm(font);

  rect.setTop(option.rect.top());
  rect.setLeft(option.rect.right() - fm.width(fakeText));
  rect.setWidth(fm.width(fakeText));
  rect.setHeight(option.rect.height());

  painter->drawText(rect, Qt::AlignRight|Qt::AlignVCenter, slotText);

  pt.setX(rect.left() - slot.width());
  pt.setY(rect.center().y() - slot.height() / 2);

  if (station->freeSlots() >= 0)
    painter->drawPixmap(pt, slot);

  rect.setTop(option.rect.top());
  rect.setLeft(pt.x() - fm.width(fakeText));
  rect.setWidth(fm.width(fakeText));
  rect.setHeight(option.rect.height());

  painter->drawText(rect, Qt::AlignRight|Qt::AlignVCenter, bikeText);

  pt.setX(rect.left() - bike.width());
  pt.setY(option.rect.center().y() - slot.height() / 2);

  painter->drawPixmap(pt, bike);

  painter->restore();
}

QSize
StationDelegate::sizeHint(const QStyleOptionViewItem &option,
			  const QModelIndex &index ) const
{
  Station *station = (Station *)index.data(StationsModel::StationRole).value<void *>();
  QSize s;
  QFontMetrics fm(option.font);

  if (!station)
    return QSize();

  /* Wow oO */
  s.setHeight(48 + fm.height() * 2);
#if defined(Q_WS_S60) || defined(Q_WS_SIMULATOR)
  s.setWidth((48 + fm.width("000")) * 2);
#elif defined(Q_WS_MAEMO_5)
  s.setWidth(400); /* Ugly .. but it works .. */
#else
  s.setWidth(qMax((int)(fm.width(station->name()) * 1.2), (48 + fm.width("000")) * 2));
#endif

  /*
   * Maemo is very, very bad with nonstandard row sizes.
   *  It involves a lot of pixmap resizing and other horrors which is *really* noticably slow.
   * To prevent this, we min-bound rows at 70px (style default)
   */
  if (QApplication::style()->inherits("QMaemo5Style")) {
    if (s.height() < 70) {
      s.setHeight(70);
    }
  }

  return s;
}

