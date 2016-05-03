#ifndef MYDRAW_HPP
#define MYDRAW_HPP
#include "abstractallapplication.hpp"
#include "abstractdrawpicture.hpp"
class MyDraw : public AbstractDrawPicture
{

public:
    MyDraw();
    //overwrite getter and setter from parent AbstractDrawPicture
    QGraphicsScene *getSceneGraphic();
    void setSceneGraphic(QGraphicsScene*);
};

#endif // DRAW_HPP
