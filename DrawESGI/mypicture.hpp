#ifndef MYPICUTRE_H
#define MYPICUTRE_H
#include <QApplication>
#include <QWidget>
#include <QGraphicsScene>
#include <QPixmap>

class MyPicture : public QWidget
{
    //Q_OBJECT
private:
    QGraphicsScene *sceneGraphic;
public:
    MyPicture();
    MyPicture(QPixmap *imageChoose);
    QGraphicsScene* getSceneGraphic();
public slots:
    void receiveSignalOpenFile(QPixmap*);

};

#endif // MYPICUTRE_H
