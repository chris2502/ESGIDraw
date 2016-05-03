#include "abstractdrawpicture.hpp"

AbstractDrawPicture::AbstractDrawPicture()
{
     //scene's canvas
    sceneGraphic= new  QGraphicsScene();
}

QGraphicsScene* AbstractDrawPicture::getSceneGraphic(){
    return sceneGraphic;
}

void AbstractDrawPicture::setSceneGraphic(QGraphicsScene* sceneGraphic){
    this->sceneGraphic=sceneGraphic;
}
