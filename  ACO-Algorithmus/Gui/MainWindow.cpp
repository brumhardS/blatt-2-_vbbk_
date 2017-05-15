#include "AntGraphic.h"
#include "BerryGraphic.h"
#include "MainWindow.h"
#include <QDebug>

MainWindow::MainWindow() :
    rectAngle(0, 0, 700, 700),
    view(&scene)
{    
    scene.setSceneRect(rectAngle);

    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    for (int i = 0; i < ANT_COUNT; ++i) {
        AntGraphic *ant = new AntGraphic;
        ant->setPos(rectAngle.topLeft());
        scene.addItem(ant);
    }


    /*
        for(int j = 0; j < rectAngle.height(); j++)
        {
            AntGraphic *ant = new AntGraphic;
            ant->setPos(0,j);
            scene.addItem(ant);
        }

        for(int j = 0; j < rectAngle.width(); j++)
        {
            AntGraphic *ant = new AntGraphic;
            ant->setPos(j,0);
            scene.addItem(ant);
        }
        */

    qDebug() << "Rect-Width: ";
    qDebug() << rectAngle.width();
    qDebug() << "Rect-Height:";
    qDebug() << rectAngle.height();

    BerryGraphic *berry = new BerryGraphic;
    berry->setPos(rectAngle.center());
    scene.addItem(berry);

    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(QPixmap(":/Images/gras.jpg"));

    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);

    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "ACO-Algorithmus"));
    view.resize(700, 700);
    view.show();

    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(1000 / 33);
}

void MainWindow::show()
{
    view.show();
}


