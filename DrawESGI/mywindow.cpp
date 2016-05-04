#include "mywindow.hpp"

MyWindow::MyWindow() : QWidget()
{
    //params's main window
    w_win=QApplication::desktop()->width()/2;
    h_win= QApplication::desktop()->height()/2;
    x_win= w_win/2;
    y_win=h_win/2;
    setGeometry(x_win, y_win, w_win, h_win);

    //layout of main window
    layoutGrid= new QGridLayout(this);

    //Bar menu of main window
    barMenu= new QMenuBar(this);
    //menu which add to bar menu
    mymenu = new MyMenu();
    QVector<QMenu*> tmpMenu= mymenu->ListMenu();
    foreach (QMenu* eltMenu, tmpMenu) {
        barMenu->addMenu(eltMenu);
    }
    //mypicture =new MyPicture(mymenu->getImageChoose());
    viewGraphic=new QGraphicsView();
    connect(mymenu, SIGNAL(signalOpenfile(QPixmap)), this, SLOT(reception(QPixmap)));
    layoutGrid->addWidget(barMenu, 0,0, 1, 5);
    layoutGrid->addWidget(viewGraphic, 1,0, 9, 3);
   // layoutGrid->addWidget(mymenu->getM_button(), 1,0, 1, 1);

    setLayout(layoutGrid);


   // testObjectAbs = new testQObjet();
    show();
}

void MyWindow::reception(QPixmap imageChoose){
    sceneGraphic=new QGraphicsScene();
    sceneGraphic->addPixmap(mymenu->getImageChoose());
    viewGraphic->setScene(sceneGraphic);
}
