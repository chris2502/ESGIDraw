#ifndef ABSTRACTMENU_HPP
#define ABSTRACTMENU_HPP
#include "abstractallapplication.hpp"
#include <QApplication>
#include <QObject>
#include <QVector>
#include <QMenu>
#include <QStatusBar>
#include <QPixmap>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QFile>
#include <QAction>


class AbstractMenu : public QWidget
{
     Q_OBJECT
public:
    AbstractMenu();
    //Renvoi
    virtual QVector<QMenu*> ListMenu()=0;
    virtual const QStatusBar* getStatusBar()=0;
    virtual void setStatusBar(QStatusBar*)=0;

public slots:
    virtual void chooseFile()=0;
    virtual void clearFile()=0;
};

#endif // ABSTRACTMENU_HPP
