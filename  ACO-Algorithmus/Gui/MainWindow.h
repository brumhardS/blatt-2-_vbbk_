#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QTimer>

#define ANT_COUNT 500
#define BERRY_COUNT 1

class MainWindow
{
public:
     MainWindow();
     void show();

private:
     QGraphicsScene scene;
     QRectF rectAngle;
     QGraphicsView view;
     QTimer timer;
};

#endif // MAINWINDOW_H
