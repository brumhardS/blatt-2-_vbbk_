#ifndef BASICGRAPHICITEM_H
#define BASICGRAPHICITEM_H

#include <QGraphicsItem>
#include <Logging/Logging.h>


class BasicGraphicItem : public QGraphicsObject
{
public:
    BasicGraphicItem();



    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BASICGRAPHICITEM_H
