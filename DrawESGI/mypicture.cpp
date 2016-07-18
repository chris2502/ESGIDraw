#include "mypicture.hpp"
#include <QDebug>

MyPicture::MyPicture(QPoint  posViewGraphics, QWidget *parent, QString fileName)
{
    this->posViewGraphics=posViewGraphics;
    degreeRotate=0;
    positionX=posViewGraphics.x();
    positionY=posViewGraphics.y();
    priority=0;
    opacity=1;
    this->fileName.clear();
    this->fileName=fileName;
    sceneGraphic= new QGraphicsScene(parent);
    sceneRight = new QGraphicsScene(parent);
    pixmapItem=Q_NULLPTR;
    pixmapItemRight= new QGraphicsPixmapItem();
    degreeRotate=0;
    pen = new QPen(Qt::green, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
}

QGraphicsScene* MyPicture::getSceneGraphic(){
    return sceneGraphic;
}

void MyPicture::setSceneGraphic(QGraphicsScene * sceneGraphic){
  delete sceneGraphic;
  sceneGraphic=sceneGraphic;
}

void MyPicture::clearSceneGraphic(){
    pointMouse.clear();
    sceneGraphic->clear();
}

QString MyPicture::getFileName(){
    return fileName;
}

QPixmap MyPicture::getImageChoose(){
    return imageChoose;
}

void MyPicture::setImageChoose(QPixmap imageChoose){
    this->imageChoose=imageChoose;

}

void MyPicture::setFileName(QString fileName){
    this->fileName.clear();
    this->fileName=fileName;
    imageChoose.load(fileName);
    pixmapItem = new QGraphicsPixmapItem(imageChoose);
    pixmapItemList[fileName]=pixmapItem;
    QMap<QString, QString> tmp;
    tmp[tr("priority")]=QString::number(pixmapItem->zValue());
    tmp[tr("positionX")]=QString::number(pixmapItem->pos().x());
    tmp[tr("positionY")]=QString::number(pixmapItem->pos().y());
    tmp[tr("opacity")]=QString::number(pixmapItem->opacity());
    infosPixmapItemList[fileName]=tmp;

    //pixmapItem->setPos(-50, -70);
    sceneGraphic->addItem(pixmapItem);

}


QMap<QString, QString> MyPicture::getInfosPixmapList(QString fileName){
     foreach (QString key, infosPixmapItemList.keys()) {
        if(key.compare(fileName) == 0){
            return infosPixmapItemList[key];
        }
    }
     QMap<QString, QString>tmp;
     return tmp;
}

/*void MyPicture::slotOpenFile(QPixmap* imageChoose){ qDebug() << "pk slotOPen";
    if(imageChoose!=nullptr){
        sceneGraphic->clear();
        sceneGraphic->addPixmap(*imageChoose);
    }
}
*/
void MyPicture::savePicture(){
    /*
    QImage image("media/toto.png");
    imageChoose.convertFromImage(image);
    QImageWriter imageWriter;
    image.setText("Author", "chris");
    imageWriter.write(image);
    image.save("media/toto.png");*/
    QString saveFilename=QFileDialog::getSaveFileName(this, QWidget::tr("Save File"),
                                                      "media/imageSave.png",
                                                      QWidget::tr("Images (*.png *.xpm *.jpg *.jpeg *.JPG)"));

        getImage().save(saveFilename);

   // imageChoose.save(saveFilename);
}

void MyPicture::printPicture(){

    QString saveFilename=QFileDialog::getSaveFileName(this, QWidget::tr("Save File to pdf"),
                                                      "media/ouput.pdf",
                                                      QWidget::tr("Files (*.pdf)"));
    QPrinter printer(QPrinter::HighResolution); //create your QPrinter (don't need to be high resolution, anyway)
    printer.setPageSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Portrait);
    printer.setPageMargins (15,15,15,15,QPrinter::Millimeter);
    printer.setFullPage(false);
    printer.setOutputFileName(saveFilename);
    printer.setOutputFormat(QPrinter::PdfFormat);
    QPainter *painter= new QPainter(&printer); // create a painter which will paint 'on printer'.
    painter->setFont(QFont("Tahoma",8));
    painter->drawPixmap(200, 200, imageChoose.width()*20, imageChoose.height()*20, imageChoose);

    painter->end();
}

void MyPicture::addPointMouse(QPoint point, QPoint posViewGraphics){
    qDebug() << "posviewgraph: "<< posViewGraphics;
    pointMouse.push_back(point);
}

void MyPicture::drawPointMouse(){
    foreach(QPoint point, pointMouse){
        qDebug() << "drawPoint: "<< point<<"| pointX :"<<point.x()<<"| pointY: "<<point.y();
        sceneGraphic->addEllipse(point.x(), point.y(), 5, 5, *pen);
    }
}

void MyPicture::drawPointMouse(QPoint point){
        qDebug() << "drawPoint: "<< point<<"| pointX :"<<point.x()<<"| pointY: "<<point.y();
        sceneGraphic->addEllipse(point.x(), point.y(), 5, 5, *pen);

}

bool MyPicture::isEmptyScene(){
    if(sceneGraphic->isActive()){
        return false;
    }
    return true;
}

void MyPicture::rotatePixmap(){ qDebug() << "i do rotate: "<<pixmapItem;

   if(pixmapItem != Q_NULLPTR){
       degreeRotate=degreeRotate+90;
       pixmapItem->setRotation(degreeRotate);
   }
}

void MyPicture::saveDraw(QPainter &painter){
    painter.setOpacity(pixmapItem->opacity());

    painter.drawPixmap(pixmapItem->x(), pixmapItem->y(), pixmapItem->pixmap());qDebug() << "opacity"<<opacity;
    //painter.setOpacity(opacity);
    //painter.drawPixmap(pixmapItem->x()+40, pixmapItem->y()+50, imageChoose);
    //painter.setOpacity(0.1);

    foreach (QPoint p, pointMouse) {
        painter.drawPoint(p);
    }
}

void MyPicture::paintEvent(QPaintEvent *){
    QPainter painter;
    painter.begin(this);

    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen(Qt::blue, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);
    saveDraw(painter);
    painter.end();
}

void MyPicture::setOpacity(qreal opacity){
    this->opacity=opacity;
    pixmapItem->setOpacity(opacity);
    QMap<QString, QString> tmp;
    tmp[tr("opacity")]=QString::number(pixmapItem->opacity());
    infosPixmapItemList[fileName]=tmp;

}

void MyPicture::setPenColor(QColor* color){
    pen->setColor(*color);
}

qreal MyPicture::getOpacity(){
    return opacity;
}



int MyPicture::getPositionX(){
    return positionX;
}

void MyPicture::setPositionX(int positionX){
    this->positionX=positionX;
    pixmapItem->setX(positionX);
    QMap<QString, QString> tmp;
    tmp[tr("positionX")]=QString::number(pixmapItem->pos().x());
    infosPixmapItemList[fileName]=tmp;
}

int MyPicture::getPositionY(){
    return positionY;
}

void MyPicture::setPositionY(int positionY){
    this->positionY=positionY;
    pixmapItem->setY(positionY);
    QMap<QString, QString> tmp;
    tmp[tr("positionY")]=QString::number(pixmapItem->pos().y());
    infosPixmapItemList[fileName]=tmp;
}

int MyPicture::getPriority(){
    return priority;
}

void MyPicture::setPriority(int priority){
    this->priority=priority;
    pixmapItem->setZValue(priority);
    QMap<QString, QString> tmp;
    tmp[tr("priority")]=QString::number(pixmapItem->zValue());
    infosPixmapItemList[fileName]=tmp;
}


void MyPicture::setPixmapItem(QString fileName){qDebug() <<"filename: "<<fileName;
    foreach (QString key, pixmapItemList.keys()) {
        qDebug() <<"filename listpixmap"<<key;
        if(key.compare(fileName)==0){
            pixmapItem=pixmapItemList[key];
            break;
        }
    }
}

void MyPicture::setSize(int sizeX, int sizeY) {
    if(pixmapItem != Q_NULLPTR && !pixmapItem->pixmap().isNull())
        pixmapItem->setPixmap(pixmapItem->pixmap().scaled(sizeX, sizeY, Qt::IgnoreAspectRatio,
                                                          Qt::SmoothTransformation));
}

int MyPicture::getSizeX() {
    int result = 0;
    if(pixmapItem != Q_NULLPTR && !pixmapItem->pixmap().isNull())
        result = pixmapItem->pixmap().size().width();
    return result;
}

int MyPicture::getSizeY() {
    int result = 0;
    if(pixmapItem != Q_NULLPTR && !pixmapItem->pixmap().isNull())
        result = pixmapItem->pixmap().size().height();
    return result;
}

QImage MyPicture::getImage(){

    QImage img(sceneGraphic->sceneRect().size().toSize(), QImage::Format_ARGB32);
    //image.fill(Qt::transparent);
    QPainter painter(&img);
    sceneGraphic->render(&painter);

    return img;
}


QGraphicsScene* MyPicture::renderSceneRightImage(){
    pixmapItemRight->setPixmap(QPixmap::fromImage(getImage()));
    sceneRight->addItem(pixmapItem);

    return scene();
}
