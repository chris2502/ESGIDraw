#include "mypicture.hpp"
#include <QDebug>
MyPicture::MyPicture()
{

}

MyPicture::MyPicture(QPixmap* imageChoose)
{

    sceneGraphic= new QGraphicsScene();

}

QGraphicsScene* MyPicture::getSceneGraphic(){
    return sceneGraphic;
}

void MyPicture::receiveSignalOpenFile(QPixmap* imageChoose){
    if(imageChoose!=nullptr){
        sceneGraphic->clear();
        sceneGraphic->addPixmap(*imageChoose);
    }
}
