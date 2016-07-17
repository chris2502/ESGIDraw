#include "mywindow.hpp"

MyWindow::MyWindow() : QWidget()
{
    //params's main window
    w_win=QApplication::desktop()->width()/2;
    h_win= QApplication::desktop()->height()/2;
    x_win= w_win/2;
    y_win=h_win/2;
    setGeometry(x_win, y_win, w_win, h_win);
    inDrawing = false;
    geometric_type = 1;

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


    //canvas
    viewGraphic=new QGraphicsView();
    viewGraphic->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    viewGraphic->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->refactorToolRightWindow();

    //picture which add to graphicview
    mypicture =new MyPicture(viewGraphic->pos(), this);

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
        connect(menuAbstract->getThisWidget(), SIGNAL(signalRightTools()), this, SLOT(slotRightTools()));
        connect(menuAbstract->getThisWidget(), SIGNAL(signalRotate()), this, SLOT(slotRotate()));
        connect(menuAbstract->getThisWidget(), SIGNAL(signalResize()), this, SLOT(slotMenuResize()));
        connect(menuAbstract->getThisWidget(), SIGNAL(signalChangeColor(QColor*)), this, SLOT(slotChangeColor(QColor*)));
        connect(menuAbstract->getThisWidget(), SIGNAL(signalNewCalque()), SLOT(slotNewCalque()));
        connect(menuAbstract->getThisWidget(), SIGNAL(signalChangeGeometricsSharp(int)), this, SLOT(slotChangeGeometricsSharp(int)));
    }

    connect(mouseCatch, SIGNAL(signalMouseCatch(QPoint)), this, SLOT(slotMouseCatch(QPoint)));
    connect(mouseCatch, SIGNAL(signalMouseCatchDrawLine(QPoint, QPoint)), this, SLOT(slotMouseCatchDrawLine(QPoint, QPoint)));

    layoutGrid->addWidget(barMenu, 0,0, 1, 5);
    layoutGrid->addWidget(viewGraphic, 1,0, 9, 3);

    layoutGrid->addWidget(mouseCatch, 1,0, 9, 3);
   // layoutGrid->addWidget(mymenu->getM_button(), 1,0, 1, 1);

    setLayout(layoutGrid);


   // testObjectAbs = new testQObjet();
    show();
}

void MyWindow::slotOpenFile(QString fileName, QAction *saveFile){ qDebug() << "iewgraph";
    mypicture->setFileName(fileName);
    if(!toolMenuRight->isEnable()){
        toolMenuRight->setEnabled(true);
    }
    toolMenuRight->show();
    toolMenuRight->addFileNameImageToAction(fileName);
    if(mypicture->isEmptyScene()){
        viewGraphic->setScene(mypicture->getSceneGraphic());
    }
    saveFile->setEnabled(true);
}

void MyWindow::slotClearScene(QAction *saveFile){
    delete toolMenuRight;
    this->refactorToolRightWindow();
    mypicture->clearSceneGraphic();
    delete mypicture;
    mypicture =new MyPicture(viewGraphic->pos(), this);
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
    mypicture->rotatePixmap();
}

void MyWindow::slotMouseCatch(const QPoint point){
    if(mypicture->isEmptyScene()){
        viewGraphic->setScene(mypicture->getSceneGraphic());
    }

    switch(geometric_type){

    //Simple Point
    case 1:
        mypicture->addPointMouse(point, viewGraphic->pos());
        mypicture->drawPointMouse(point);

        break;
    //Line
    case 2:
        //qDebug() << "Mouse pressed state  is " << mouseCatch->getPressedState() << inDrawing;

        if (mouseCatch->getPressedState()==true && inDrawing==false)
        {
            startPos = point;
             inDrawing = true;
        }
        else if(mouseCatch->getPressedState()==false)
        {
            endPos = point;
           // qDebug() << "Beginning line points" << startPos.x() << " " << startPos.y();
           //qDebug() << "Ending line points" << endPos.x() << " " << endPos.y();
            mypicture->DrawLine(startPos, endPos);
            inDrawing = false;
        }

    }
}

void MyWindow::slotRightTools(){
    toolMenuRight->show();
}

void MyWindow::slotPriority(int priority){
    mypicture->setPriority(priority);
}

void MyWindow::slotPositionX(int positionX){
    int tmp=positionX;qDebug() << "tmpx: "<<tmp << "viewX"<<viewGraphic->x();
    if(positionX <(viewGraphic->x()-8) || positionX> (viewGraphic->width()-8)){
        toolMenuRight->setPositionSpinBoxX(viewGraphic->x());
        tmp=viewGraphic->x()-8;
    }
    mypicture->setPositionX(tmp);
}

void MyWindow::slotPositionY(int positionY){
    int tmp=positionY;
    if(positionY <(viewGraphic->y()-45) || positionY> (viewGraphic->height()-45)){
        toolMenuRight->setPositionSpinBoxX(viewGraphic->y());
        tmp=viewGraphic->y()-45;
    }qDebug() << "posy: "<<positionY<< "viewY"<<viewGraphic->y()<<"tmpy"<<tmp;
    mypicture->setPositionY(tmp);
}

void MyWindow::slotOpacity(qreal opacity){
    mypicture->setOpacity(opacity);
}


void MyWindow::slotMenuResize(){
    resizetoolmenu =new ResizeToolMenu(this->pos(), mypicture->getSizeX(), mypicture->getSizeY());
    connect(resizetoolmenu, SIGNAL(signalResize(int, int)), this, SLOT(slotResize(int, int)));
}

void MyWindow::slotResize(int sizeX, int sizeY){
    mypicture->setSize(sizeX, sizeY);
}

void MyWindow::slotChangeColor(QColor* color){
    mypicture->setPenColor(color);
}

void MyWindow::slotChangeGeometricsSharp(int type){
    //qDebug() << "slot geometric change";
    geometric_type = type;
}


void MyWindow::slotSelectPixmap(QString fileName){
    qDebug() <<"slotselectpixmap window";
    mypicture->setPixmapItem(fileName);
}

void MyWindow::slotNewCalque(){
    qDebug() <<"slotNewCalque";
    QGraphicsScene scene;
    QGraphicsView view;
    QGraphicsPixmapItem itemPixmap;
    scene.addPixmap(QPixmap::fromImage(mypicture->getImage()));
    view.setScene(&scene);
    layoutGrid->addWidget(&view, 1,4, 3, 3);
}

void MyWindow::resizeEvent(QResizeEvent *){
   viewGraphic->setSceneRect(viewGraphic->x()-8, viewGraphic->y()-45, viewGraphic->width(), viewGraphic->height());
   //qDebug() << "viewPoint: "<<"viewpointX :"<<viewGraphic->x()<<"| viewY: "<<viewGraphic->y()<<"| viewWid: " <<viewGraphic->width() <<"| viewhei:" <<viewGraphic->height();
}

void MyWindow::refactorWindow(){

}

void MyWindow::refactorToolRightWindow(){
    //right tool menu
    toolMenuRight =new RightToolMenu(this->pos());
    connect(toolMenuRight, SIGNAL(signalSelectPixmap(QString)), SLOT(slotSelectPixmap(QString)));
    connect(toolMenuRight, SIGNAL(signalPriority(int)), this, SLOT(slotPriority(int)));
    connect(toolMenuRight, SIGNAL(signalPositionX(int)), this, SLOT(slotPositionX(int)));
    connect(toolMenuRight, SIGNAL(signalPositionY(int)), this, SLOT(slotPositionY(int)));
    connect(toolMenuRight, SIGNAL(signalOpacity(qreal)), this, SLOT(slotOpacity(qreal)));
}

void MyWindow::refactorPicture(){

}
