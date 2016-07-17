#include "catchmouse.hpp"
#include <QDebug>
CatchMouse::CatchMouse()
{
 type = 1;
 startPos = QPoint();
 endPos = QPoint();
 inDrawing = false;
 setMouseTracking(true);
}

CatchMouse::CatchMouse(int p_type)
{
        type = p_type;
}

void CatchMouse::setType(int p_type){
    //qDebug() << "SET TYPE " << p_type;
    type = p_type;
}

void CatchMouse::mouseMoveEvent(QMouseEvent *event){

    qDebug() << "cord move"<< event->pos();

    switch(type){
    //Draw point
    case 1:
        emit signalMouseCatch(event->pos());
        break;
    //Draw Line
    case 2:
        if (inDrawing)
        {
            endPos = event->pos();
            update();
        }
        break;
    }
}

void CatchMouse::mousePressEvent(QMouseEvent *event){
    switch(type){
    //Draw Point
    case 1:
        if(event->button() == Qt::LeftButton){
            qDebug() << "cord press"<< event->pos();
            emit signalMouseCatch(event->pos());
         }
        break;

    //Draw Line
    case 2:
        if (event->buttons() & Qt::LeftButton)
            {
                if (!inDrawing)
                {
                    startPos = event->pos();
                }
                else
                {
                    endPos = event->pos();

                    emit signalMouseCatchDrawLine(startPos, event->pos());
                }

                inDrawing = !inDrawing;
            }
        break;
        }


}

void CatchMouse::mouseReleaseEvent(QMouseEvent *event){
    qDebug() << "cord realease"<< event->pos();
    switch(type){
    case 1:
        emit signalMouseCatch(event->pos());
        break;
    }
}
