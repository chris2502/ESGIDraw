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
    QAction *rightToolsMenu;
    //Menu picture
    QMenu *pictureMenu;
    QAction *rotation;
    QAction *resize;
    //Menu layer
    QMenu *layerMenu;
    QAction *newCalque;
    QMenu *toolsMenu;
    QMenu *geometricMenu;
    //Menu GeometricsSharp
    QAction *gPoint;
    QAction *gLine;
    //Menu Color
    QMenu *colorMenu;
    QAction *blue;
    QAction *red;
    QAction *green;
    QAction *black;
    QAction *white;
    QAction *grey;
    QAction *pink;

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

    void slotTheme();

    void slotRotate();
    void slotResize();

    void slotRightTools();

    void slotNewCalque();

    void slotColorBlue();
    void slotColorRed();
    void slotColorGreen();
    void slotColorBlack();
    void slotColorWhite();
    void slotColorGrey();
    void slotColorPink();

    //void slotChangeGeometricsSharp(int*);
    void slotChangeGeometricsSharpPoint();
    void slotChangeGeometricsSharpLine();

signals:
    void mySignal(QGraphicsScene*);
    void signalOpenfile(QString, QAction*);
    void signalClearScene(QAction*);
    void signalSavePicture();
    void signalPrintPicture();

    void signalTheme();

    void signalNewCalque();

    void signalRightTools();
    void signalRotate();
    void signalResize();

    void signalChangeColor(QColor*);
    void signalChangeGeometricsSharp(int);
};

#endif // TESTQOBJET_H
