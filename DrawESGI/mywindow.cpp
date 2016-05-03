#include "mywindow.hpp"

MyWindow::MyWindow() : QWidget()
{
    //params's main window
    w_win=QApplication::desktop()->width()/2;
    h_win= QApplication::desktop()->height()/2;
    x_win= w_win/2;
    y_win=h_win/2;
    setGeometry(x_win, y_win, w_win, h_win);


    layoutGrid= new QGridLayout(this);
    barMenu= new QMenuBar(this);
    mymenu = new MyMenu();
    QVector<QMenu*> tmpMenu= mymenu->ListMenu();
    foreach (QMenu* eltMenu, tmpMenu) {
        barMenu->addMenu(eltMenu);
    }

    viewGraphic=new QGraphicsView();
    layoutGrid->addWidget(barMenu, 0,0, 1, 1);
    layoutGrid->addWidget(viewGraphic, 1,0, 1, 1);
   // layoutGrid->addWidget(mymenu->getM_button(), 1,0, 1, 1);

    setLayout(layoutGrid);

   // testObjectAbs = new testQObjet();
    //show();
}
