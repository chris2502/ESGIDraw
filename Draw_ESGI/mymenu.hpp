#ifndef MYMENU_HPP
#define MYMENU_HPP
#include "abstractmenu.hpp"

class MyMenu : public AbstractMenu
{
     Q_OBJECT
private:
    QStatusBar *q_statusBar;

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
    //constructor
    MyMenu();
    //Menu list to add to menuBar
    QVector<QMenu*>ListMenu();
    //overwrite getter and setter from abstractMenu
    const QStatusBar* getStatusBar();
    void setStatusBar(QStatusBar*);
    QGraphicsScene* getSceneGraphic();
    void setSceneGraphic(QGraphicsScene*);
    //getter and setter
    QPixmap getImageChoose();
    void setImageChoose(QPixmap);

public slots:
    void chooseFile();
    void clearFile();
};

#endif // MYMENU_HPP
