#ifndef WINDOWTEST_H
#define WINDOWTEST_H
#include "abstractmenu.hpp"
#include <QDesktopWidget>
#include "myloadplugin.hpp"
#include "mymenu.hpp"
#include "mypicture.hpp"
#include <QGridLayout>
#include <QGraphicsView>
#include <QMenuBar>
#include <QVector>
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

    QMouseEvent *event;
   // AbtractTestQobject *testObjectAbs;
public:
    MyWindow();
public slots:
    void slotOpenFile(QString, QAction*);
    void slotClearScene(QAction*);
    void slotSavePicture();
    void slotPrintPicture();
    void slotRotate();
    void slotMouseCatch(const QPoint);

};

#endif // WINDOWTEST_H
