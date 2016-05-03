#ifndef ABSTRACTDRAWPICTURE_HPP
#define ABSTRACTDRAWPICTURE_HPP
#include "abstractallapplication.hpp"
#include <QGraphicsScene>
class AbstractDrawPicture
{
protected:
    QGraphicsScene *sceneGraphic;
public:
    AbstractDrawPicture();
    virtual QGraphicsScene *getSceneGraphic();
    virtual void setSceneGraphic(QGraphicsScene*);
};

#endif // MYDRAWPICTURE_HPP
