#ifndef WINDOWTEST_H
#define WINDOWTEST_H
#include "abstractmenu.hpp"
#include "righttoolmenu.hpp"
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

    QVector<AbstractMenu*> menuAbstractList;
    QMenuBar *barMenu;
    MyPicture *mypicture;
    CatchMouse *mouseCatch;
    QGridLayout *layoutGrid;
    QGraphicsView *viewGraphic;
    QGraphicsScene *sceneGraphic;
    RightToolMenu *toolMenuRight;
    QMouseEvent *event;
   // AbtractTestQobject *testObjectAbs;
public:
    MyWindow();
public slots:
    void slotOpenFile(QString, QAction*);
    void slotClearScene(QAction*);
    void slotSavePicture();
    void slotPrintPicture();
    void slotRightTools();
    void slotRotate();
    void slotMouseCatch(const QPoint);
    void slotPriority(int);
    void slotPositionX(int);
    void slotPositionY(int);
    void slotOpacity(qreal);
    void slotChangeColor(QColor*);

public:
    virtual void resizeEvent(QResizeEvent *);
};

#endif // WINDOWTEST_H
