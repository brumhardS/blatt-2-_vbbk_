#include "BerryGraphic.h"
#include <QPainter>

BerryGraphic::BerryGraphic()
{

}

QRectF BerryGraphic::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}

QPainterPath BerryGraphic::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 20, 40);
    return path;
}

void BerryGraphic::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::darkMagenta);
    painter->drawEllipse(-10, -10, 40, 20);
    painter->setBrush(Qt::darkGreen);
    painter->drawEllipse(-8,  -9, 10, 10);


}
