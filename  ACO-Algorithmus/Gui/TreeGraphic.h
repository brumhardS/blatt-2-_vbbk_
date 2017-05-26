#ifndef TREE_H
#define TREE_H

#include <QGraphicsItem>



class TreeGraphic : public QGraphicsItem
{
public:
    TreeGraphic();
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
};

#endif // TREE_H
