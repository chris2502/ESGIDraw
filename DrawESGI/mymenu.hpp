#ifndef TESTQOBJET_H
#define TESTQOBJET_H
#include "abstractmenu.hpp"
#include <QSaveFile>



class MyMenu : public QWidget, public AbstractMenu
{
    Q_OBJECT
    Q_INTERFACES(AbstractMenu)
private:
    QString name;
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
    ~MyMenu();
    //Menu list to add to menuBar
    QVector<QMenu*>ListMenu();
    QString getFileName();
    QWidget* getThisWidget();

public slots:
    void slotOpenfile();
    void slotClearScene();
    void slotSavePicture();
    void slotPrintPicture();

signals:
    void mySignal(QGraphicsScene*);
    void signalOpenfile(QString, QAction*);
    void signalClearScene(QAction*);
    void signalSavePicture();
    void signalPrintPicture();
};

#endif // TESTQOBJET_H
