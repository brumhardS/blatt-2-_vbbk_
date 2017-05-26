/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "AntGraphic.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#include <math.h>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;

}

//! [0]
AntGraphic::AntGraphic()
    : angle(0), speed(0), antEyeDirection(0){
    setRotation(qrand() % (360 * 16));
}
//! [0]

//! [1]
QRectF AntGraphic::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}

QPainterPath AntGraphic::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);
    return path;
}

void AntGraphic::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    /* Ameisenkörper */
    painter->setBrush(Qt::black);

    //Kopf
    painter->drawEllipse(-10, -10,  5, 5);

    //Körper
    painter->drawEllipse(-10,  -4,  5, 10);
    painter->drawEllipse(-10,   1,  5, 10);
    painter->drawEllipse(-12.5,   6,  10, 10);

    // Fühler im Kopf
    painter->drawLine(QLine(-10,-9,-11,-11));
    painter->drawLine(QLine(-11,-11,-12,-10));
    painter->drawLine(QLine(-12,-10,-13,-12));

    painter->drawLine(QLine(-10,-9,-4,-11));
    painter->drawLine(QLine(-4,-11,-3,-10));
    painter->drawLine(QLine(-3,-10,-2,-12));

    // Leg 1
    painter->drawLine(QLine(-10,-4,-14,-5));
    painter->drawLine(QLine(-14,-5,-16,-7));

    painter->drawLine(QLine(-10,-4,-1,-5));
    painter->drawLine(QLine(-1,-5,0,-7));

    // Leg 2
    painter->drawLine(QLine(-10,1,-14,1));
    painter->drawLine(QLine(-14,1,-15,5));
    painter->drawLine(QLine(-15,5,-17,7));

    painter->drawLine(QLine(-10,1,-1,1));
    painter->drawLine(QLine(-1,1,0,5));
    painter->drawLine(QLine(0,5,2,7));

    // Leg 3
    painter->drawLine(QLine(-10, 5,-17,11));
    painter->drawLine(QLine(-17,11,-19,16));
    painter->drawLine(QLine(-19,16,-22,19));
    painter->drawLine(QLine(-22,19,-23,18));

    painter->drawLine(QLine(-7, 5, 3,11));
    painter->drawLine(QLine(3,11,2,16));
    painter->drawLine(QLine(2,16,5,19));
    painter->drawLine(QLine(5,19,6,18));
}

void AntGraphic::advance(int step)
{
    if (!step)
        return;
    // Don't move too far away
    QLineF lineToCenter(QPointF(0, 0), mapFromScene(0, 0));
    if (lineToCenter.length() > 150) {
        qreal angleToCenter = ::acos(lineToCenter.dx() / lineToCenter.length());
        if (lineToCenter.dy() < 0)
            angleToCenter = TwoPi - angleToCenter;
        angleToCenter = normalizeAngle((Pi - angleToCenter) + Pi / 2);

        if (angleToCenter < Pi && angleToCenter > Pi / 4) {
            // Rotate left
            angle += (angle < -Pi / 2) ? 0.25 : -0.25;
        } else if (angleToCenter >= Pi && angleToCenter < (Pi + Pi / 2 + Pi / 4)) {
            // Rotate right
            angle += (angle < Pi / 2) ? 0.25 : -0.25;
        }
    } else if (::sin(angle) < 0) {
        angle += 0.25;
    } else if (::sin(angle) > 0) {
        angle -= 0.25;
    }

    // Try not to crash with any other mice
    QList<QGraphicsItem *> dangerMice = scene()->items(QPolygonF()
                                                       << mapToScene(0, 0)
                                                       << mapToScene(-30, -50)
                                                       << mapToScene(30, -50));
    foreach (QGraphicsItem *item, dangerMice) {
        if (item == this)
            continue;

        QLineF lineToAnt(QPointF(0, 0), mapFromItem(item, 0, 0));
        qreal angleToAnt = ::acos(lineToAnt.dx() / lineToAnt.length());
        if (lineToAnt.dy() < 0)
            angleToAnt = TwoPi - angleToAnt;
        angleToAnt = normalizeAngle((Pi - angleToAnt) + Pi / 2);

        if (angleToAnt >= 0 && angleToAnt < Pi / 2) {
            // Rotate right
            angle += 0.5;
        } else if (angleToAnt <= TwoPi && angleToAnt > (TwoPi - Pi / 2)) {
            // Rotate left
            angle -= 0.5;
        }
    }

    // Add some random movement
    if (dangerMice.size() > 1 && (qrand() % 10) == 0) {
        if (qrand() % 1)
            angle += (qrand() % 100) / 500.0;
        else
            angle -= (qrand() % 100) / 500.0;
    }
    speed += (-50 + qrand() % 100) / 100.0;

    qreal dx = ::sin(angle) * 10;
    antEyeDirection = (qAbs(dx / 5) < 1) ? 0 : dx / 5;

    setRotation(rotation() + dx);
    setPos(mapToParent(0, -(3 + sin(speed) * 3)));
}
