#ifndef CATCHMOUSE_H
#define CATCHMOUSE_H
#include <QWidget>
#include <QMouseEvent>
#include <QPoint>

class CatchMouse : public QWidget
{
    Q_OBJECT
    int type;

    //For lines
    QPoint startPos;
        QPoint endPos;
        bool inDrawing;

public:
    CatchMouse();
    CatchMouse(int p_type);
    void setType(int p_type);

    //virtual inherit qobject
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void signalMouseCatch(QPoint);
    void signalMouseCatchDrawLine(QPoint, QPoint);
};

#endif // CATCHMOUSE_H
