#include "MainWindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow();
    w->show();

    //Ausgabe während der Ausführung der Applikation, zu Testzwecken
    qDebug() << "Test";

    return a.exec();

}

