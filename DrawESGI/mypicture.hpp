#ifndef MYPICUTRE_H
#define MYPICUTRE_H
#include <QApplication>
#include <QWidget>
#include <QGraphicsScene>
#include <QPixmap>
#include <QImage>
#include <QImageWriter>
#include <QFile>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>

class MyPicture : public QWidget
{
    //Q_OBJECT
private:
    QGraphicsScene *sceneGraphic;
    QString fileName;
    QPixmap imageChoose;
    QImage image;
public:
    MyPicture(QWidget *parent=Q_NULLPTR, QString fileName=Q_NULLPTR);
    QGraphicsScene* getSceneGraphic();
    void clearSceneGraphic();
    void setSceneGraphic(QGraphicsScene *sceneGraphic);
    QString getFileName();
    QPixmap getImageChoose();
    void setImageChoose(QPixmap imageChoose);
    void setFileName(QString fileName);
    void savePicture();
    void printPicture();
    void draw();
public slots:
    void slotOpenFile(QPixmap*);

};

#endif // MYPICUTRE_H
