#include "mywindow.hpp"

MyWindow::MyWindow() : QWidget()
{
    layoutGrid= new QGridLayout(this);
    barMenu= new QMenuBar(this);
    mymenu = new MyMenu();
    QVector<QMenu*> tmpMenu= mymenu->ListMenu();
    foreach (QMenu* eltMenu, tmpMenu) {
        barMenu->addMenu(eltMenu);
    }
    layoutGrid->addWidget(barMenu, 0,0, 1, 1);
    layoutGrid->addWidget(mymenu->getM_button(), 1,0, 1, 1);


   // testObjectAbs = new testQObjet();
    //show();
}
