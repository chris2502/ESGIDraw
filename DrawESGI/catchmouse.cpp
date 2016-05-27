#include "catchmouse.hpp"
#include <QDebug>
CatchMouse::CatchMouse()
{

}

void CatchMouse::mouseMoveEvent(QMouseEvent *event){

    //qDebug() << "cord move"<< event->pos();
    emit signalMouseCatch(event->pos());
}

void CatchMouse::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        //qDebug() << "cord press"<< event->pos();
        emit signalMouseCatch(event->pos());
     }
}

void CatchMouse::mouseReleaseEvent(QMouseEvent *event){
    //qDebug() << "cord realease"<< event->pos();
    emit signalMouseCatch(event->pos());
}
