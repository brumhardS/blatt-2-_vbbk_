#ifndef NODEWIDGET_H
#define NODEWIDGET_H

#include <QGraphicsItem>
#include <QWidget>

class NodeGraphic : public QGraphicsItem
{
public:
    NodeGraphic();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // NODEWIDGET_H
