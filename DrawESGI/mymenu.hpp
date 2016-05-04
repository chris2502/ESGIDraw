#ifndef TESTQOBJET_H
#define TESTQOBJET_H
//#include "abtracttestqobject.hpp"
#include <QApplication>
#include <QPushButton>
#include <QFileDialog>
#include <QWidget>
#include <QMenu>

class MyMenu : public QWidget//: public AbtractTestQobject
{
    Q_OBJECT
private:
    //Menu file
    QMenu *fileMenu;
    QAction *newFile;
    QAction *openFile;
    //path's image
    QString fileName;
    QAction *saveFile;
    QAction *printFile;
    QAction *settingFile;
    QAction *exitApp;

    //Menu edit
    QMenu *editMenu;
    QAction *cut;
    QAction *copy;
    QAction *paste;
    QAction *clean;
    //Menu Screen
    QMenu *screenMenu;
    QAction *theme;
    QAction *canvas;
    QAction *leftToolsMenu;
    //Menu picture
    QMenu *pictureMenu;
    QAction *rotation;
    QAction *resize;
    //Menu layer
    QMenu *layerMenu;
    QAction *newCalque;
    QMenu *toolsMenu;
    QMenu *geometricMenu;

public:
    MyMenu();
    //Menu list to add to menuBar
    QVector<QMenu*>ListMenu();
    QString getFileName();
public slots:
    void slotOpenfile();

signals:
    void signalOpenfile(QString);
};

#endif // TESTQOBJET_H
