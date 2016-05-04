#include "mymenu.hpp"
#include "QDebug"
MyMenu::MyMenu()
{
    //Menu file
    fileMenu= new QMenu("File");

    newFile= new QAction("New file", fileMenu);

    openFile= new QAction("Open file",fileMenu);
    //open dialog window to choose file image
    connect(openFile,SIGNAL(triggered()), this, SLOT(slotOpenfile()));

    saveFile= new QAction("Save file",fileMenu);

    printFile= new QAction("Print picture",fileMenu);

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
    leftToolsMenu=new QAction("Left Tool Menu", screenMenu);

    //add to Screen
    screenMenu->addAction(theme);
    screenMenu->addAction(canvas);
    screenMenu->addAction(leftToolsMenu);

    //Menu picture
    pictureMenu= new QMenu("Picture");
    rotation=new QAction("Rotation", pictureMenu);
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

QVector<QMenu*> MyMenu::ListMenu(){
   QVector<QMenu*> qlistMenu;
   qlistMenu.push_back(fileMenu);
   qlistMenu.push_back(fileMenu);
   qlistMenu.push_back(editMenu);
   qlistMenu.push_back(screenMenu);
   qlistMenu.push_back(pictureMenu);
   qlistMenu.push_back(layerMenu);
   qlistMenu.push_back(toolsMenu);
   qlistMenu.push_back(geometricMenu);
   return qlistMenu;
}


void MyMenu::slotOpenfile(){
    QFileDialog dialogFile;
    dialogFile.setFileMode(QFileDialog::ExistingFile);
    dialogFile.setNameFilter(tr("Images (*.png *.jpg)"));
    dialogFile.setViewMode(QFileDialog::Detail);
    fileName= dialogFile.getOpenFileName();
    emit signalOpenfile(fileName);
}

QString MyMenu::getFileName(){
    return fileName;
}
