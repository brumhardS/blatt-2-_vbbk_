//#include "MainWindow.h"

#include <QApplication>
#include <QDebug>
#include <QtWidgets>
#include <math.h>
#include <Gui/BerryGraphic.h>
#include <Gui/MainWindow.h>
#include <Logic/MainApplication.h>
#include "Gui/AntGraphic.h"

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
   return app.exec();
}

