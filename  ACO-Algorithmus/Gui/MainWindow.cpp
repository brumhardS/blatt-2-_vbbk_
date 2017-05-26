#include "AntGraphic.h"
#include "BerryGraphic.h"
#include "MainWindow.h"
#include "NodeGraphic.h"
#include "NodeWidget.h"
#include <QBackingStore>
#include <QDebug>

MainWindow::MainWindow() :
    rectAngle(0, 0, 700, 700),
    view(&scene)
{    
    scene.setSceneRect(rectAngle);

    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    for (int i = 0; i < ANT_COUNT; ++i)
    {
        AntGraphic *ant = new AntGraphic;
        ant->setPos(rectAngle.topLeft());
        scene.addItem(ant);
    }

    BerryGraphic *berry = new BerryGraphic;
    berry->setPos(rectAngle.center());
    scene.addItem(berry);

    BerryGraphic *berryTwo = new BerryGraphic;
    berryTwo->setPos(rectAngle.topLeft());
    scene.addItem(berryTwo);

    BerryGraphic *berryThree = new BerryGraphic;
    berryThree->setPos(rectAngle.topRight());
    scene.addItem(berryThree);

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


