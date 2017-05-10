//#include "MainWindow.h"

#include <QApplication>
#include <QDebug>
#include <QtWidgets>
#include <math.h>
#include <Gui/BerryGraphic.h>
#include "Gui/AntGraphic.h"

static const int AntCount = 20;
static const int BerryCount = 20;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    QGraphicsScene scene;
    QRectF r1(-300, -300, 1000, 1000);
    scene.setSceneRect(r1);

    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    for (int i = 0; i < AntCount; ++i) {
        AntGraphic *ant = new AntGraphic;
        ant->setPos(r1.topLeft());
        scene.addItem(ant);
    }

    BerryGraphic *berry = new BerryGraphic;
    berry->setPos(r1.center());
    scene.addItem(berry);


    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(QPixmap(":/Images/gras.jpg"));

    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);

    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "ACO-Algorithmus"));
    view.resize(1000, 1000);
    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(1000 / 33);

    return app.exec();
}

