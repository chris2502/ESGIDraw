#include "myloadplugin.hpp"

MyLoadPlugin::MyLoadPlugin(){

}

AbstractMenu* MyLoadPlugin::getPluginByName(const QString& fileName) {
    QPluginLoader loader(fileName); // On charge le plugin.
    QObject *plugin = loader.instance(); // On prend l'instance.
    return qobject_cast<AbstractMenu*>(plugin); // Et on retourne le plugin casté.
}

QVector<AbstractMenu*> MyLoadPlugin::getLoadPlugin(const QString& dirName){
    QVector<AbstractMenu*> pluginList;
    QDir plugDir = QDir(dirName);
    foreach(QString file, plugDir.entryList(QDir::Files)) {
        // On vérifie si le fichier est un plugin avant de l'ajouter à la liste
        if(AbstractMenu* plugin = MyLoadPlugin::getPluginByName(plugDir.absoluteFilePath(file))){
            pluginList.push_back(plugin);
             qDebug() <<file<<" c'est un plugin";
        }
        else{
            qDebug() <<file<<" n'est pas un plugin";
        }
    }
    return pluginList;
}
