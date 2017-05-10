//#include "MainWindow.h"

#include <QApplication>
#include <QDebug>
#include <QtWidgets>
#include <math.h>
#include <Gui/BerryGraphic.h>
#include <Gui/MainWindow.h>
#include "Gui/AntGraphic.h"

int main(int argc, char **argv)
{
   QApplication app(argc, argv);
   qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
   MainWindow *mainWindow = new MainWindow;
   mainWindow->show();
   return app.exec();
}

