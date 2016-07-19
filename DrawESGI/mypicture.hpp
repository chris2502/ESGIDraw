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
#include <QMap>
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
    QGraphicsScene *sceneRight;
    QString fileName;
    QPixmap imageChoose;
    QMap<QString, QGraphicsPixmapItem*> pixmapItemList;
    QMap<QString, QMap<QString, QString>> infosPixmapItemList;
    QVector<QPoint> pointMouse;
    QMouseEvent *event;
    QGraphicsPixmapItem *pixmapItem;
    QGraphicsPixmapItem *pixmapItemRight;
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
    void DrawLine(QPoint pointStart, QPoint pointEnd);
    void DrawRect(QPoint pointStart, QPoint pointEnd);
    void DrawEllipse(QPoint pointStart, QPoint pointEnd);
    bool isEmptyScene();
    void setFileName(QString fileName);
    void savePicture();
    void printPicture();
    void draw();
    void rotatePixmap();

    qreal getOpacity();
    void setOpacity(qreal);


    QMap<QString, QString> getInfosPixmapList(QString fileName);

    void applyLayer(int sizeViewX, int sizeViewY);

    int getPositionX();
    void setPositionX(int positionX);

    int getPositionY();
    void setPositionY(int positionY);

    int getPriority();
    void setPriority(int priority);

    void setPenColor(QColor *color);

    void setPixmapItem(QString);

    QGraphicsScene* getSceneRight();

    //virtual void paintEvent(QPaintEvent *);

    QGraphicsScene* renderSceneRightImage(int sizeRightViewX, int sizeRightViewY);

    QImage getImage();

    //void saveDraw(QPainter &painter);

    void setSize(int sizeX, int sizeY);
    int getSizeX();
    int getSizeY();
public slots:
    void slotOpenFile(QPixmap*);

};

#endif // MYPICTURE_H
