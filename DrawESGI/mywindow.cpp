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
    //catch pos mouse
    mouseCatch= new CatchMouse();
    //menu which add to bar menu
    AbstractMenu *mymenu= new MyMenu();
    menuAbstractList.push_back(mymenu);
    const QString str=qApp->applicationDirPath() + "/../build-Myplugins-Desktop_Qt_5_6_0_GCC_64bit-Release";
    qDebug()<< "Dossier des plugins: "<< str;
    foreach (AbstractMenu* idPlugin, MyLoadPlugin::getLoadPlugin(str)) {
        menuAbstractList.push_back(idPlugin);
    }

    //picture which add to graphicview
    mypicture =new MyPicture(this);
    //canvas
    viewGraphic=new QGraphicsView();

    foreach (AbstractMenu* menuAbstract, menuAbstractList) {
        //add to bar menu
        QVector<QMenu*> tmpMenu= menuAbstract->ListMenu();
        foreach (QMenu* eltMenu, tmpMenu) {
            barMenu->addMenu(eltMenu);
        }
        connect(menuAbstract->getThisWidget(), SIGNAL(signalOpenfile(QString, QAction*)), this, SLOT(slotOpenFile(QString, QAction*)), Qt::AutoConnection);
        connect(menuAbstract->getThisWidget(), SIGNAL(signalClearScene(QAction*)), this, SLOT(slotClearScene(QAction*)));
        connect(menuAbstract->getThisWidget(), SIGNAL(signalSavePicture()), this, SLOT(slotSavePicture()));
        connect(menuAbstract->getThisWidget(), SIGNAL(signalPrintPicture()), this, SLOT(slotPrintPicture()));
        connect(menuAbstract->getThisWidget(), SIGNAL(signalRotate()), this, SLOT(slotRotate()));
    }

    connect(mouseCatch, SIGNAL(signalMouseCatch(QPoint)), this, SLOT(slotMouseCatch(QPoint)));
    layoutGrid->addWidget(barMenu, 0,0, 1, 5);
    layoutGrid->addWidget(viewGraphic, 1,0, 9, 3);

    layoutGrid->addWidget(mouseCatch, 1,0, 9, 3);
   // layoutGrid->addWidget(mymenu->getM_button(), 1,0, 1, 1);

    setLayout(layoutGrid);


   // testObjectAbs = new testQObjet();
    show();
}

void MyWindow::slotOpenFile(QString fileName, QAction *saveFile){
    mypicture->setFileName(fileName);
    if(mypicture->isEmptyScene()){
        viewGraphic->setScene(mypicture->getSceneGraphic());
    }
    saveFile->setEnabled(true);
}

void MyWindow::slotClearScene(QAction *saveFile){
    mypicture->clearSceneGraphic();
    saveFile->setDisabled(true);
}

void MyWindow::slotSavePicture(){
    mypicture->savePicture();
}

void MyWindow::slotPrintPicture(){
    mypicture->printPicture();
}


void MyWindow::slotRotate(){
//qInfo() << "Slot Rotate call"<<endl;
viewGraphic->rotate(90);

void MyWindow::slotMouseCatch(const QPoint point){
    mypicture->addPointMouse(point, viewGraphic->pos());
    mypicture->drawPointMouse();
    if(mypicture->isEmptyScene()){
        viewGraphic->setScene(mypicture->getSceneGraphic());
    }

}
