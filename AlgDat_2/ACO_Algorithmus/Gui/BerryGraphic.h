#ifndef BERRY_H
#define BERRY_H

#include "BasicGraphicItem.h"

#include <QGraphicsItem>




class BerryGraphic : public BasicGraphicItem
{
public:
    BerryGraphic();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
};
#endif // BERRY_H
