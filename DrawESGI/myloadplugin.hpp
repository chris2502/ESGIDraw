#ifndef MYLOADPLUGIN_H
#define MYLOADPLUGIN_H
#include <QVector>
#include <QPluginLoader>
#include <QDir>
#include <abstractmenu.hpp>
#include <QDebug>
class MyLoadPlugin
{   
public:
    MyLoadPlugin();
    static AbstractMenu* getPluginByName(const QString& fileName);
    static QVector<AbstractMenu*> getLoadPlugin(const QString& dirName);
};

#endif // MYLOADPLUGIN_H
