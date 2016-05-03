#include "mypicture.hpp"

MyPicture::MyPicture() : AbstractDrawPicture()
{

}

MyPicture::MyPicture(QPixmap imageChoose) : AbstractDrawPicture()
{
    sceneGraphic->addPixmap(imageChoose);
}

QGraphicsScene* MyPicture::getSceneGraphic(){
    return sceneGraphic;
}

void MyPicture::setSceneGraphic(QGraphicsScene *sceneGraphic){
    this->sceneGraphic=sceneGraphic;
}
