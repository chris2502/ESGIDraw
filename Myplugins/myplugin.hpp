#ifndef MYPLUGIN_H
#define MYPLUGIN_H
#include "abstractmenu.hpp"


class MyPlugin : QWidget, AbstractMenu
{
    Q_OBJECT
    Q_INTERFACES(AbstractMenu)
    Q_PLUGIN_METADATA(Plugin_Menu)
private:
    //Menu file
    QMenu *fileMenu;
    QAction *newFile;
    QAction *openFile;
    //path's image
    QString fileName;
    QAction *saveFile;
    QAction *printFile;
    QAction *settingFile;
    QAction *exitApp;
public:
    MyPlugin();
    ~MyPlugin();
    //Menu list to add to menuBar
    QVector<QMenu*>ListMenu();
    QString getFileName();
    QWidget* getThisWidget();

public slots:
    void slotOpenfile();

signals:
    void mySignal(QGraphicsScene*);
    void signalOpenfile(QString);
};

#endif // MYPLUGIN_H
