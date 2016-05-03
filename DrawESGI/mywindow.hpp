#ifndef WINDOWTEST_H
#define WINDOWTEST_H

#include <QWidget>
#include <QApplication>
#include <QMenuBar>
#include <QDesktopWidget>
//#include "abtracttestqobject.hpp"
#include "mymenu.hpp"
#include <QGridLayout>
#include <QGraphicsView>
class MyWindow : public QWidget
{
private:
    int w_win;
    int h_win;
    int x_win;
    int y_win;

    QMenuBar *barMenu;
    MyMenu *mymenu;
    QGridLayout *layoutGrid;
    QGraphicsView *viewGraphic;
   // AbtractTestQobject *testObjectAbs;
public:
    MyWindow();
};

#endif // WINDOWTEST_H
