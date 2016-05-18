#ifndef ABTRACTTESTQOBJECT_H
#define ABTRACTTESTQOBJECT_H
#include <QApplication>
#include <QtPlugin>
#include <QFileDialog>
#include <QMessageBox>
#include <QWidget>
#include <QGraphicsScene>
#include <QMenu>


class AbstractMenu
{

public:
    //Menu list to add to menuBar
    virtual QVector<QMenu*>ListMenu()=0;
    virtual QWidget* getThisWidget()=0;
    virtual ~AbstractMenu(){}


public slots:
    virtual void slotOpenfile()=0;

signals:
    virtual void mySignal(QGraphicsScene*)=0;
    virtual void signalOpenfile(QString, QAction*)=0;
    virtual void signalClearScene(QAction*)=0;
};
Q_DECLARE_INTERFACE(AbstractMenu, "fr.ESGI.abstractmenu")


#endif // ABTRACTTESTQOBJECT_H
