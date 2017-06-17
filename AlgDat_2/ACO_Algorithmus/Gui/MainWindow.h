#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QTimer>

#include <Data/Ant.h>



class MainWindow : public QObject
{
    Q_OBJECT

public:
     MainWindow(QList<Ant*> *allAnts, QPoint * berryPosition, QPoint * antColony, QPoint *raster);
     void show();

     QRectF getRectAngle() const;
     void setRectAngle(const QRectF &value);

private:

     QPoint modelToWinCoordinates(int x, int y);

     QGraphicsScene * scene;
     QRectF rectAngle;
     QGraphicsView * view;
     QTimer timer;
};

#endif // MAINWINDOW_H
