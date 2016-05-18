#include "myplugin.hpp"

MyPlugin::MyPlugin()
{
    //Menu file
    fileMenu= new QMenu("Fileplugin");

    newFile= new QAction("New file", fileMenu);

    openFile= new QAction("Open file",fileMenu);
    //open dialog window to choose file image
    connect(openFile,SIGNAL(triggered()), this, SLOT(slotOpenfile()), Qt::AutoConnection);

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

}

MyPlugin::~MyPlugin(){

}

QWidget* MyPlugin::getThisWidget(){
    return this;
}

QVector<QMenu*> MyPlugin::ListMenu(){
   QVector<QMenu*> qlistMenu;
   qlistMenu.push_back(fileMenu);

   return qlistMenu;
}


void MyPlugin::slotOpenfile(){
    QFileDialog dialogFile;
    dialogFile.setFileMode(QFileDialog::ExistingFile);
    dialogFile.setNameFilter(tr("Images (*.png *.jpg)"));
    dialogFile.setViewMode(QFileDialog::Detail);
    fileName= dialogFile.getOpenFileName();
    emit signalOpenfile(fileName);
}



QString MyPlugin::getFileName(){
    return fileName;
}

Q_PLUGIN_METADATA(Plugin_Menu)
