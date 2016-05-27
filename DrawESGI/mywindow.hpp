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
    QGridLayout *layoutGrid;
    QGraphicsView *viewGraphic;
    QGraphicsScene *sceneGraphic;
   // AbtractTestQobject *testObjectAbs;
public:
    MyWindow();
public slots:
    void slotOpenFile(QString, QAction*);
    void slotClearScene(QAction*);
    void slotSavePicture();
    void slotPrintPicture();
    void slotRotate();

};

#endif // WINDOWTEST_H
