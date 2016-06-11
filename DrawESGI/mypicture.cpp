#include "mypicture.hpp"
#include <QDebug>

MyPicture::MyPicture(QWidget *parent, QString fileName)
{
    this->fileName.clear();
    this->fileName=fileName;
    sceneGraphic= new QGraphicsScene(parent);
    pixmapItem=Q_NULLPTR;
    degreeRotate=0;
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
    sceneGraphic->addItem(pixmapItem);
    pixmapItem->setPos(-50, -70);

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
                                                      QWidget::tr("Images (*.png *.xpm *.jpg)"));

    imageChoose.save(saveFilename);
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
    QPen pen(Qt::blue, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    foreach(QPoint point, pointMouse){
        qDebug() << "drawPoint: "<< point<<"| pointX :"<<point.x()<<"| pointY: "<<point.y();
        sceneGraphic->addEllipse(point.x(), point.y(), 5, 5, pen);
    }
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
