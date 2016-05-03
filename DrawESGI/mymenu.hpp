#ifndef TESTQOBJET_H
#define TESTQOBJET_H
//#include "abtracttestqobject.hpp"
#include <QApplication>
#include <QPushButton>
#include <QFileDialog>
#include <QWidget>
#include <QMenu>
#include <QPixmap>
class MyMenu : public QWidget//: public AbtractTestQobject
{
    Q_OBJECT
private:
    QPushButton *m_button;
    //Menu file
    QMenu *fileMenu;
    QAction *newFile;
    QAction *openFile;
    QPixmap imageChoose;
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
    QPushButton* getM_button();
    //Menu list to add to menuBar
    QVector<QMenu*>ListMenu();
public slots:
    void myopenfile();
};

#endif // TESTQOBJET_H
