#ifndef WINDOWTEST_H
#define WINDOWTEST_H
#include "abstractmenu.hpp"
#include "righttoolmenu.hpp"
#include "resizetoolmenu.h"
#include <QDesktopWidget>
#include "myloadplugin.hpp"
#include "mymenu.hpp"
#include "mypicture.hpp"
#include <QGridLayout>
#include <QGraphicsView>
#include <QMenuBar>
#include <QVector>
#include <QResizeEvent>
#include "catchmouse.hpp"
class MyWindow : public QWidget
{
    Q_OBJECT
private:
    int w_win;
    int h_win;
    int x_win;
    int y_win;
    int nInitialX = 0;
    int nInitialY = 0;
    int nFinalX = 0;
    int nFinalY = 0;
    int drawLines = 1;

    QVector<AbstractMenu*> menuAbstractList;
    QMenuBar *barMenu;
    MyPicture *mypicture;
    CatchMouse *mouseCatch;
    QGridLayout *layoutGrid;
    QGraphicsView *viewGraphic;
    QGraphicsScene *sceneGraphic;
    RightToolMenu *toolMenuRight;
    ResizeToolMenu *resizetoolmenu;
    QMouseEvent *event;
   // AbtractTestQobject *testObjectAbs;
public:
    MyWindow();
    void refactorWindow();
    void refactorToolRightWindow();
    void refactorPicture();
public slots:
    void slotOpenFile(QString, QAction*);
    void slotClearScene(QAction*);
    void slotSavePicture();
    void slotPrintPicture();
    void slotRightTools();
    void slotRotate();
    void slotMouseCatch(const QPoint);
    void slotMouseCatchDrawLine(const QPoint, const QPoint);
    void slotPriority(int);
    void slotPositionX(int);
    void slotPositionY(int);
    void slotOpacity(qreal);
    void slotChangeColor(QColor*);
    void slotNewCalque();
    void slotSelectPixmap(QString);
   void slotChangeGeometricsSharp(int);

    void slotMenuResize();
    void slotResize(int, int);

public:
    virtual void resizeEvent(QResizeEvent *);
};

#endif // WINDOWTEST_H
