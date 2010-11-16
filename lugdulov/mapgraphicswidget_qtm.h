/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Mobility Components.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef MAPGRAPHICSWIDGET_H
#define MAPGRAPHICSWIDGET_H

#include <QtGui/QGraphicsSceneMouseEvent>
#include <QtCore/QTime>

#include "mobility.h"

class MapGraphicsWidget : public QGraphicsGeoMap
{
    Q_OBJECT
public:
    MapGraphicsWidget(QGeoMappingManager *manager);
    ~MapGraphicsWidget();

signals:
    void objectsClicked(QList < QGeoMapObject * > objects);

private slots:
    void kineticTimerEvent();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent* event);
    void wheelEvent(QGraphicsSceneWheelEvent* event);

private:
    bool panActive;
    bool panDecellerate;

    // Fractional pan, used by panFloatWrapper
    QPointF remainingPan;

    // current kinetic panning speed, in pixel/msec
    QPointF kineticPanSpeed;
    QPoint panDir;
    QTimer *kineticTimer;
    QTime lastMoveTime;

    // An entry in the mouse history. first=speed, second=time
    typedef QPair<QPointF, QTime> MouseHistoryEntry;
    // A history of the last (currently 5) mouse move events is stored in order to smooth out movement detection for kinetic panning
    QList<MouseHistoryEntry> mouseHistory;

    void panFloatWrapper(const QPointF& delta);
    void applyPan(const Qt::KeyboardModifiers& modifiers);
};

#endif // MAPGRAPHICSWIDGET_H
