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

#ifndef STATIONSDELEGATE_H
# define STATIONSDELEGATE_H

#include <QtGui/QStyledItemDelegate>
#include <QtGui/QFontMetrics>
#include <QtCore/QModelIndex>
#include <QtCore/QSize>

class QStyledItemModel;
class QObject;
class QPainter;

class StationDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
  StationDelegate(QObject *parent = 0);
  virtual ~StationDelegate();

  void paint(QPainter *painter, const QStyleOptionViewItem &option,
	     const QModelIndex &index) const;

  QSize sizeHint(const QStyleOptionViewItem &option,
		 const QModelIndex &index ) const;
};

#endif