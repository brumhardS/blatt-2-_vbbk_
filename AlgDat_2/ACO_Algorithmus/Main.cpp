//#include "MainWindow.h"

#include <thread>
#include <QApplication>
#include <QDebug>
#include <QtWidgets>
#include <math.h>
#include <Gui/BerryGraphic.h>
#include <Gui/MainWindow.h>
#include <Logic/MainApplication.h>
#include "Gui/AntGraphic.h"

void initializeAndStartAlgorithmThread(MainApplication * mainapplication)
{
    QThread* thread = new QThread;
    mainapplication->moveToThread(thread);
    QObject::connect(thread, SIGNAL(started()), mainapplication, SLOT(run()));
    QObject::connect(mainapplication, SIGNAL(finished()), thread, SLOT(quit()));
    QObject::connect(mainapplication, SIGNAL(finished()), mainapplication, SLOT(deleteLater()));
    QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

int main(int argc, char **argv)
{
   QApplication app(argc, argv);
   qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

   MainApplication *mainapplication = new MainApplication();

   MainWindow * mainWindow =
           new MainWindow(mainapplication->getList(),
                          new QPoint(BERRY_POSITION_X, BERRY_POSITION_Y),
                          new QPoint(ANT_COLONY_X, ANT_COLONY_Y),
                          new QPoint(RASTER_X, RASTER_Y));
   mainWindow->show();

   initializeAndStartAlgorithmThread(mainapplication);

   return app.exec();
}

