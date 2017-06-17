#include "AntGraphic.h"
#include "BerryGraphic.h"
#include "MainWindow.h"
#include <QBackingStore>
#include <QDebug>
#include <Data/Ant.h>

MainWindow::MainWindow(QList<Ant*> *allAnts, QPoint * berryPosition, QPoint * antColony, QPoint *raster) :
    rectAngle(0,0,720,720)
{    
    Q_UNUSED(raster);
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);
    scene->setSceneRect(rectAngle);

    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    for (int i = 0; i < allAnts->size(); ++i)
    {
        BasicGraphicItem *ant = new AntGraphic();

        QObject::connect(allAnts->at(i), &Ant::move, (AntGraphic*) ant, &AntGraphic::goNext);
        ant->setPos(modelToWinCoordinates(antColony->rx(), antColony->ry()));

        scene->addItem(ant);
    }

    BasicGraphicItem *berryThree = new BerryGraphic;
    berryThree->setPos(modelToWinCoordinates(berryPosition->rx(), berryPosition->ry()));
    scene->addItem(berryThree);

    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(QPixmap(":/Images/gras.jpg"));

    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);

    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "ACO-Algorithmus"));
    view->resize(700, 700);
    view->show();

    QObject::connect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer.start(1000 / 33);
}

void MainWindow::show()
{
    view->show();
}

QRectF MainWindow::getRectAngle() const
{
    return rectAngle;
}

void MainWindow::setRectAngle(const QRectF &value)
{
    rectAngle = value;
}

QPoint MainWindow::modelToWinCoordinates(int x, int y)
{
    return QPoint((720/20 * x),(720/20 * y));
}


