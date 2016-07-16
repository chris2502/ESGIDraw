#ifndef MYPICTURE_H
#define MYPICTURE_H
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
    QGraphicsItemGroup *groupItemGraphics;
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

    virtual void paintEvent(QPaintEvent *);


    void saveDraw(QPainter &painter);

    void setSizeX(int sizeX);
    void setSizeY(int sizeY);
    int getSizeX();
    int getSizeY();
public slots:
    void slotOpenFile(QPixmap*);

};

#endif // MYPICTURE_H
