#ifndef TREE_H
#define TREE_H

#include "BasicGraphicItem.h"

#include <QGraphicsItem>



class TreeGraphic : public BasicGraphicItem
{
public:
    TreeGraphic();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

};

#endif // TREE_H
