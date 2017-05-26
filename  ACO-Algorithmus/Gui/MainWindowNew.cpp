#include "MainWindowNew.h"
#include "NodeWidget.h"

MainWindowNew::MainWindowNew()
{
    mainLayout = new QGridLayout;
    initWindow();
    setLayout(mainLayout);
    setFixedSize(500,500);
}

void MainWindowNew::initWindow()
{
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->addWidget(new NodeWidget(), 0,0);
    mainLayout->addWidget(new NodeWidget(), 0,1);
    mainLayout->addWidget(new NodeWidget(), 0,2);
    mainLayout->addWidget(new NodeWidget(), 0,3);
    mainLayout->addWidget(new NodeWidget(), 0,4);
    mainLayout->addWidget(new NodeWidget(), 0,5);
    mainLayout->addWidget(new NodeWidget(), 0,6);
    mainLayout->addWidget(new NodeWidget(), 0,7);
    mainLayout->addWidget(new NodeWidget(), 0,8);
}


