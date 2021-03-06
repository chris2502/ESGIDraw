#include "mymenu.hpp"
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
    saveFile->setDisabled(true);
    connect(saveFile, SIGNAL(triggered()), this, SLOT(slotSavePicture()));

    printFile= new QAction("Export pdf",fileMenu);
    connect(printFile, SIGNAL(triggered()), this, SLOT(slotPrintPicture()));

    settingFile= new QAction("Setting",fileMenu);
    settingFile->setDisabled(true);

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
    editMenu->setDisabled(true);

    //Menu Screen
    screenMenu= new QMenu("Screen");
    theme=new QAction("Thème", screenMenu);
    connect(theme, SIGNAL(triggered()), SLOT(slotTheme()));
    theme->setDisabled(true);
    canvas=new QAction("Canvas", screenMenu);
    canvas->setDisabled(true);
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
    connect(resize,SIGNAL(triggered()), this, SLOT(slotResize()));

    //add to picture
    pictureMenu->addAction(rotation);
    pictureMenu->addAction(resize);

    //Menu layer
    layerMenu= new QMenu("Layer");
    newCalque=new QAction("New layer", layerMenu);

    //add to layer
    layerMenu->addAction(newCalque);
    connect(newCalque, SIGNAL(triggered()), this, SLOT(slotNewCalque()));

    toolsMenu= new QMenu("Tools");
    toolsMenu->setDisabled(true);

    geometricMenu= new QMenu("Geometric sharpes");
    gPoint=new QAction("Point", geometricMenu);
    gLine=new QAction("Line", geometricMenu);
    gRect=new QAction("Rectangle", geometricMenu);
    gEllipse=new QAction("Ellipse", geometricMenu);

    geometricMenu->addAction(gPoint);
    geometricMenu->addAction(gLine);
    geometricMenu->addAction(gRect);
    geometricMenu->addAction(gEllipse);

    connect(gPoint, SIGNAL(triggered()), this, SLOT(slotChangeGeometricsSharpPoint()));
    connect(gLine, SIGNAL(triggered()), this, SLOT(slotChangeGeometricsSharpLine()));
    connect(gRect, SIGNAL(triggered()), this, SLOT(slotChangeGeometricsSharpRect()));
    connect(gEllipse, SIGNAL(triggered()), this, SLOT(slotChangeGeometricsSharpEllipse()));

    //Color Menu
    colorMenu= new QMenu("Color");
    blue=new QAction("Blue", colorMenu);
    red=new QAction("Red", colorMenu);
    green=new QAction("Green", colorMenu);
    black=new QAction("Black", colorMenu);
    white=new QAction("White", colorMenu);
    grey=new QAction("Grey", colorMenu);
    pink=new QAction("Pink", colorMenu);

    colorMenu->addAction(blue);
    colorMenu->addAction(red);
    colorMenu->addAction(green);
    colorMenu->addAction(black);
    colorMenu->addAction(white);
    colorMenu->addAction(grey);
    colorMenu->addAction(pink);

    connect(blue, SIGNAL(triggered()), this, SLOT(slotColorBlue()));
    connect(red, SIGNAL(triggered()), this, SLOT(slotColorRed()));
    connect(green, SIGNAL(triggered()), this, SLOT(slotColorGreen()));
    connect(black, SIGNAL(triggered()), this, SLOT(slotColorBlack()));
    connect(white, SIGNAL(triggered()), this, SLOT(slotColorWhite()));
    connect(grey, SIGNAL(triggered()), this, SLOT(slotColorGrey()));
    connect(pink, SIGNAL(triggered()), this, SLOT(slotColorPink()));
}

MyMenu::~MyMenu(){
    delete newFile;
    delete openFile;
    delete saveFile;
    delete printFile;
    delete settingFile;
    delete exitApp;
    delete fileMenu;


    delete cut;
    delete copy;
    delete paste;
    delete clean;
    delete editMenu;


    delete theme;
    delete canvas;
    delete rightToolsMenu;
    delete screenMenu;

    //Menu picture
    delete rotation;
    delete resize;
    delete pictureMenu;
    //Menu layer
    delete newCalque;
    delete layerMenu;
    delete toolsMenu;
    //Menu GeometricsSharp
    delete gPoint;
    delete gLine;
    delete gRect;
    delete gEllipse;
    delete geometricMenu;
    //Menu Color
    delete blue;
    delete red;
    delete green;
    delete black;
    delete white;
    delete grey;
    delete pink;
    delete colorMenu;
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
   qlistMenu.push_back(colorMenu);
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
                                           tr("Images (*.png *.xpm *.jpg *.jpeg *.JPG)"));
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

void MyMenu::slotResize(){
    emit signalResize();
}

void MyMenu::slotRightTools(){
    emit signalRightTools();
}


void MyMenu::slotTheme(){
    emit signalTheme();
}

void MyMenu::slotColorBlue(){
    emit signalChangeColor(new QColor("blue"));
}

void MyMenu::slotColorRed(){
    emit signalChangeColor(new QColor("red"));
}
void MyMenu::slotColorGreen(){
    emit signalChangeColor(new QColor("green"));
}
void MyMenu::slotColorBlack(){
    emit signalChangeColor(new QColor("black"));
}
void MyMenu::slotColorWhite(){
    emit signalChangeColor(new QColor("white"));
}

void MyMenu::slotColorGrey(){
    emit signalChangeColor(new QColor("grey"));
}

void MyMenu::slotColorPink(){
    emit signalChangeColor(new QColor("pink"));

}

void MyMenu::slotNewCalque(){
    emit signalNewCalque();
}

void MyMenu::slotChangeGeometricsSharpPoint(){
    emit signalChangeGeometricsSharp(1);
}
void MyMenu::slotChangeGeometricsSharpLine(){
    emit signalChangeGeometricsSharp(2);
}
void MyMenu::slotChangeGeometricsSharpRect(){
    emit signalChangeGeometricsSharp(3);
}
void MyMenu::slotChangeGeometricsSharpEllipse(){
    emit signalChangeGeometricsSharp(4);
}
