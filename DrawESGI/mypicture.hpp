#ifndef MYPICUTRE_H
#define MYPICUTRE_H
#include <QApplication>
#include <QWidget>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPoint>
#include <QPen>
#include <QImageWriter>
#include <QFile>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QMouseEvent>
class MyPicture : public QWidget, public QGraphicsScene
{
    //Q_OBJECT
private:
    QGraphicsScene *sceneGraphic;
    QString fileName;
    QPixmap imageChoose;
    QImage image;
    QVector<QPoint> pointMouse;
    QMouseEvent *event;
    QGraphicsPixmapItem *pixmapItem;
    int degreeRotate=0;
public:
    MyPicture(QWidget *parent=Q_NULLPTR, QString fileName=Q_NULLPTR);
    QGraphicsScene* getSceneGraphic();
    void clearSceneGraphic();
    void setSceneGraphic(QGraphicsScene *sceneGraphic);
    QString getFileName();
    QPixmap getImageChoose();
    void setImageChoose(QPixmap imageChoose);
    void addPointMouse(QPoint, QPoint posViewGraphics);
    void drawPointMouse();
    bool isEmptyScene();
    void setFileName(QString fileName);
    void savePicture();
    void printPicture();
    void draw();
    void rotatePixmap();
public slots:
    void slotOpenFile(QPixmap*);

};

#endif // MYPICUTRE_H
