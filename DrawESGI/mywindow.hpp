#ifndef WINDOWTEST_H
#define WINDOWTEST_H

#include <QWidget>
#include <QApplication>
#include <QMenuBar>
#include <QDesktopWidget>
//#include "abtracttestqobject.hpp"
#include "mymenu.hpp"
#include "mypicture.hpp"
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
class MyWindow : public QWidget
{
    Q_OBJECT
private:
    int w_win;
    int h_win;
    int x_win;
    int y_win;

    QMenuBar *barMenu;
    MyMenu *mymenu;
    MyPicture *mypicture;
    QGridLayout *layoutGrid;
    QGraphicsView *viewGraphic;
    QGraphicsScene *sceneGraphic;
   // AbtractTestQobject *testObjectAbs;
public:
    MyWindow();
public slots:
    void slotOpenFile(QString);
};

#endif // WINDOWTEST_H
