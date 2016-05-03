#include "mymenu.hpp"

MyMenu::MyMenu()
{
    //Menu file
    fileMenu= new QMenu("File");
    newFile= new QAction("New file", fileMenu);
    openFile= new QAction("Open file",fileMenu);
    //open dialog window to choose file image
    connect(openFile,SIGNAL(triggered()), this, SLOT(myopenfile()));
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

    m_button= new QPushButton();
    m_button->connect(m_button, SIGNAL(clicked()), this, SLOT(myopenfile()), Qt::AutoConnection);
 //   QWidget::connect(&m_button, SIGNAL(clicked()), this, SLOT(myopenfile()), Qt::AutoConnection);

}

QVector<QMenu*> MyMenu::ListMenu(){
   QVector<QMenu*> qlistMenu;
   qlistMenu.push_back(fileMenu);
   return qlistMenu;
}


void MyMenu::myopenfile(){
    QFileDialog dialogFile;
    dialogFile.setFileMode(QFileDialog::ExistingFile);
    dialogFile.setNameFilter(tr("Images (*.png *.jpg)"));
    dialogFile.setViewMode(QFileDialog::Detail);
    QString fileName;
    fileName= dialogFile.getOpenFileName();
}

QPushButton* MyMenu::getM_button(){
    return m_button;
}
