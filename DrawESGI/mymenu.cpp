#include "mymenu.hpp"
#include "QDebug"
MyMenu::MyMenu()
{
    //Menu file
    fileMenu= new QMenu("File");

    newFile= new QAction("New file", fileMenu);
    connect(newFile, SIGNAL(triggered()), this, SLOT(slotClearScene()), Qt::AutoConnection);

    openFile= new QAction("Open file",fileMenu);
    //open dialog window to choose file image
    connect(openFile,SIGNAL(triggered()), this, SLOT(slotOpenfile()), Qt::AutoConnection);

    saveFile= new QAction("Save file",fileMenu);
    //saveFile->setDisabled(true);
    connect(saveFile, SIGNAL(triggered()), this, SLOT(slotSavePicture()));

    printFile= new QAction("Print picture",fileMenu);
    connect(printFile, SIGNAL(triggered()), this, SLOT(slotPrintPicture()));

    settingFile= new QAction("Setting",fileMenu);

    exitApp= new QAction("Exit",fileMenu);
    //quit application when we click in Action exitApp
    connect(exitApp, SIGNAL(triggered()), qApp, SLOT(quit()));

    fileMenu->addAction(newFile);
    fileMenu->addAction(openFile);
    fileMenu->addAction(saveFile);
    fileMenu->addAction(printFile);
    fileMenu->addAction(settingFile);
    fileMenu->addAction(exitApp);


    //Menu edit
    editMenu= new QMenu("Edit");
    cut=new QAction("Cut", editMenu);
    copy=new QAction("Copy", editMenu);
    paste=new QAction("Paste", editMenu);
    clean=new QAction("Clean", editMenu);

    //add to edit menu
    editMenu->addAction(cut);
    editMenu->addAction(copy);
    editMenu->addAction(copy);
    editMenu->addAction(clean);


    //Menu Screen
    screenMenu= new QMenu("Screen");
    theme=new QAction("Thème", screenMenu);
    canvas=new QAction("Canvas", screenMenu);

    rightToolsMenu=new QAction("Right Tool Menu", screenMenu);
    connect(rightToolsMenu, SIGNAL(triggered()), this, SLOT(slotRightTools()));

    //add to Screen
    screenMenu->addAction(theme);
    screenMenu->addAction(canvas);
    screenMenu->addAction(rightToolsMenu);

    //Menu picture
    pictureMenu= new QMenu("Picture");

    rotation=new QAction("Rotation", pictureMenu);
    connect(rotation,SIGNAL(triggered()), this, SLOT(slotRotate()));

    resize=new QAction("Resize", pictureMenu);

    //add to picture
    pictureMenu->addAction(rotation);
    pictureMenu->addAction(resize);

    //Menu layer
    layerMenu= new QMenu("Layer");
    newCalque=new QAction("New layer", layerMenu);

    //add to layer
    layerMenu->addAction(newCalque);

    toolsMenu= new QMenu("Tools");
    geometricMenu= new QMenu("Geometric sharpes");
}

MyMenu::~MyMenu(){
 qDebug() << "destructor mymenu";
}

QWidget* MyMenu::getThisWidget(){
    return this;
}

QVector<QMenu*> MyMenu::ListMenu(){
   QVector<QMenu*> qlistMenu;
   qlistMenu.push_back(fileMenu);
   qlistMenu.push_back(editMenu);
   qlistMenu.push_back(screenMenu);
   qlistMenu.push_back(pictureMenu);
   qlistMenu.push_back(layerMenu);
   qlistMenu.push_back(toolsMenu);
   qlistMenu.push_back(geometricMenu);
   return qlistMenu;
}


void MyMenu::slotClearScene(){
    QMessageBox::StandardButton messageBox;
    messageBox= QMessageBox::question(this, "Open new project", "Are you sure to open a new project?", QMessageBox::Yes|QMessageBox::No);
    if(messageBox == QMessageBox::Yes){
        emit signalClearScene(saveFile);
    }
}

void MyMenu::slotOpenfile(){

    fileName= QFileDialog::getOpenFileName(this, tr("Open File"),
                                           "",
                                           tr("Images (*.png *.xpm *.jpg)"));
    emit signalOpenfile(fileName, saveFile);
}

void MyMenu::slotSavePicture(){
    QString name;
    //saveFile->setDisabled(true);
    emit signalSavePicture();
}
void MyMenu::slotPrintPicture(){
    emit signalPrintPicture();
}

QString MyMenu::getFileName(){
    return fileName;
}

void MyMenu::slotRotate(){
    emit signalRotate();
}

void MyMenu::slotRightTools(){
    emit signalRightTools();
}
