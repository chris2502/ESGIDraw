#include "mypicture.hpp"
#include <QDebug>
MyPicture::MyPicture()
{
    sceneGraphic= new QGraphicsScene();
}

MyPicture::MyPicture(QString fileName)
{
    this->fileName.clear();
    this->fileName=fileName;
    sceneGraphic= new QGraphicsScene();

}

QGraphicsScene* MyPicture::getSceneGraphic(){
    return sceneGraphic;
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
    sceneGraphic->addPixmap(imageChoose);
}

void MyPicture::signalOpenFile(QPixmap* imageChoose){
    if(imageChoose!=nullptr){
        sceneGraphic->clear();
        sceneGraphic->addPixmap(*imageChoose);
    }
}
