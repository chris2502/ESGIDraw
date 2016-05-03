#ifndef MYPICTURE_HPP
#define MYPICTURE_HPP
#include "abstractallapplication.hpp"
#include "abstractdrawpicture.hpp"
#include <QPixmap>

class MyPicture : public AbstractDrawPicture
{


public:
    MyPicture();
    MyPicture(QPixmap);
    //overwrite getter and setter from parent AbstractDrawPicture
    QGraphicsScene* getSceneGraphic();
    void setSceneGraphic(QGraphicsScene*);
};

#endif // MYPICTURE_HPP
