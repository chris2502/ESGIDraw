#ifndef MYPICUTRE_H
#define MYPICUTRE_H
#include <QApplication>
#include <QWidget>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsItemGroup>
#include <QImage>
#include <QPoint>
#include <QPen>
#include <QImageWriter>
#include <QFile>
#include <QPrinter>
#include <QPainter>
#include <QPaintEvent>
#include <QFileDialog>
#include <QMouseEvent>
class MyPicture : public QWidget, QGraphicsItemGroup
{
    //Q_OBJECT
private:
    QGraphicsScene *sceneGraphic;
    QString fileName;
    QPixmap imageChoose;
    QVector<QGraphicsPixmapItem*> pixmapItemList;
    QImage image;
    QVector<QPoint> pointMouse;
    QMouseEvent *event;
    QGraphicsPixmapItem *pixmapItem;
    QPoint  posViewGraphics;
    int degreeRotate;
    int priority;
    int positionX;
    int positionY;
    qreal opacity;
    QPen *pen;

public:
    MyPicture(QPoint  posViewGraphics, QWidget *parent=Q_NULLPTR, QString fileName=Q_NULLPTR);
    QGraphicsScene* getSceneGraphic();
    void clearSceneGraphic();
    void setSceneGraphic(QGraphicsScene *sceneGraphic);
    QString getFileName();
    QPixmap getImageChoose();
    void setImageChoose(QPixmap imageChoose);
    void addPointMouse(QPoint, QPoint posViewGraphics);
    void drawPointMouse();
    void drawPointMouse(QPoint point);
    bool isEmptyScene();
    void setFileName(QString fileName);
    void savePicture();
    void printPicture();
    void draw();
    void rotatePixmap();

    qreal getOpacity();
    void setOpacity(qreal);

    int getPositionX();
    void setPositionX(int positionX);

    int getPositionY();
    void setPositionY(int positionY);

    int getPriority();
    void setPriority(int priority);

    void setPenColor(QColor *color);

    void setPixmapItem(QString);

    virtual void paintEvent(QPaintEvent *);


    void saveDraw(QPainter &painter);

public slots:
    void slotOpenFile(QPixmap*);

};

#endif // MYPICUTRE_H
