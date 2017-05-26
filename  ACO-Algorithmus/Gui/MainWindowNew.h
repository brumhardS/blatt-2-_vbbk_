#ifndef MAINWINDOWNEW_H
#define MAINWINDOWNEW_H

#include <QMainWindow>
#include <QVBoxLayout>

class MainWindowNew : public QMainWindow
{
    Q_OBJECT
public:
    MainWindowNew();

private:
    QGridLayout *mainLayout;

    void initWindow();
};

#endif // MAINWINDOWNEW_H
