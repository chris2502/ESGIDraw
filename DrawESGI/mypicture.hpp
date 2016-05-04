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
    QString fileName;
    QPixmap imageChoose;
public:
    MyPicture();
    MyPicture(QString fileName);
    QGraphicsScene* getSceneGraphic();
    QString getFileName();
    QPixmap getImageChoose();
    void setImageChoose(QPixmap imageChoose);
    void setFileName(QString fileName);
public slots:
    void signalOpenFile(QPixmap*);

};

#endif // MYPICUTRE_H
