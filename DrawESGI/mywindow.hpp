#ifndef WINDOWTEST_H
#define WINDOWTEST_H

#include <QWidget>
#include <QApplication>
#include <QMenuBar>
//#include "abtracttestqobject.hpp"
#include "mymenu.hpp"
#include <QGridLayout>
class MyWindow : public QWidget
{
private:
     QMenuBar *barMenu;
    MyMenu *mymenu;
    QGridLayout *layoutGrid;
   // AbtractTestQobject *testObjectAbs;
public:
    MyWindow();
};

#endif // WINDOWTEST_H
