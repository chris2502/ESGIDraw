#include "catchmouse.hpp"
#include <QDebug>
CatchMouse::CatchMouse()
{
 isPressed = false;
}

bool CatchMouse::getPressedState(){
    return isPressed;
}

void CatchMouse::mouseMoveEvent(QMouseEvent *event){
    //qDebug() << "cord move"<< event->pos();
        emit signalMouseCatch(event->pos());
}

void CatchMouse::mousePressEvent(QMouseEvent *event){
        if(event->button() == Qt::LeftButton){
            this->isPressed = true;
            //qDebug() << "cord press"<< event->pos() << isPressed;
            emit signalMouseCatch(event->pos());
         }
}

void CatchMouse::mouseReleaseEvent(QMouseEvent *event){
        this->isPressed = false;
    //qDebug() << "cord realease"<< event->pos();
        emit signalMouseCatch(event->pos());

}
