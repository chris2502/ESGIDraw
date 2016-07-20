#include "catchmouse.hpp"
CatchMouse::CatchMouse()
{
 isPressed = false;
}

bool CatchMouse::getPressedState(){
    return isPressed;
}

void CatchMouse::mouseMoveEvent(QMouseEvent *event){
        emit signalMouseCatch(event->pos());
}

void CatchMouse::mousePressEvent(QMouseEvent *event){
        if(event->button() == Qt::LeftButton){
            this->isPressed = true;
            emit signalMouseCatch(event->pos());
         }
}

void CatchMouse::mouseReleaseEvent(QMouseEvent *event){
        this->isPressed = false;
        emit signalMouseCatch(event->pos());

}
