#include "mydraw.hpp"

MyDraw::MyDraw() : AbstractDrawPicture()
{
}

QGraphicsScene* MyDraw::getSceneGraphic(){
    return sceneGraphic;
}

void MyDraw::setSceneGraphic(QGraphicsScene* sceneGraphic){
    this->sceneGraphic=sceneGraphic;
}
