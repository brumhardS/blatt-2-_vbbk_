#ifndef BERRY_H
#define BERRY_H

#include <QGraphicsItem>




class BerryGraphic : public QGraphicsItem
{
public:
    BerryGraphic();
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
};

#endif // BERRY_H
