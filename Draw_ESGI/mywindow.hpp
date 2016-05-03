#ifndef MYWINDOW_H
#define MYWINDOW_H

#include "abstractmenu.hpp"
#include "mymenu.hpp"

#include "abstractdrawpicture.hpp"
#include "mypicture.hpp"
#include "mydraw.hpp"

#include "abstracttoolbar.hpp"
#include "mytoolbar.hpp"

#include <QApplication>
#include <QWidget>
#include <QDesktopWidget>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QVector>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGridLayout>
class MyWindow : public QWidget
{

private:
    int w_win;
    int h_win;
    int x_win;
    int y_win;
    QMenuBar *barMenu;
    QVector<AbstractMenu*> menuList;
    QVector<AbstractDrawPicture*> drawPictureList;
    QVector<AbstractToolBar*> toolBarList;
    QGraphicsView *viewGraphic;
    QGridLayout *layoutGrid;

public:
    MyWindow();

};

#endif // MYWINDOW_H
