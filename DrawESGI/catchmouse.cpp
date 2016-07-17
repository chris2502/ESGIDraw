#include "catchmouse.hpp"
#include <QDebug>
CatchMouse::CatchMouse()
{
 type = 1;
 startPos = QPoint();
 endPos = QPoint();
 inDrawing = false;
 setMouseTracking(true);
 isPressed = false;
}

CatchMouse::CatchMouse(int p_type)
{
        type = p_type;
         isPressed = false;
}

void CatchMouse::setType(int p_type){
    //qDebug() << "SET TYPE " << p_type;
    type = p_type;
}
void CatchMouse::setIsPressed(bool b){
    //qDebug() << "SET TYPE " << p_type;
    isPressed = b;
}

bool CatchMouse::getIsPressedState(){
    return isPressed;
}

void CatchMouse::mouseMoveEvent(QMouseEvent *event){

    qDebug() << "cord move"<< event->pos();


        emit signalMouseCatch(event->pos());

}

void CatchMouse::mousePressEvent(QMouseEvent *event){

        if(event->button() == Qt::LeftButton){
            this->isPressed = true;
            qDebug() << "cord press"<< event->pos() << isPressed;
            emit signalMouseCatch(event->pos());
         }

}

void CatchMouse::mouseReleaseEvent(QMouseEvent *event){
        this->isPressed = false;
    qDebug() << "cord realease TOTOTO"<< isPressed;
    qDebug() << "cord realease"<< event->pos();
        emit signalMouseCatch(event->pos());

}
