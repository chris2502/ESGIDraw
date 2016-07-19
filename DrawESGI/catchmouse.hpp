#ifndef CATCHMOUSE_H
#define CATCHMOUSE_H
#include <QWidget>
#include <QMouseEvent>
#include <QPoint>

class CatchMouse : public QWidget
{
    Q_OBJECT
    bool isPressed;

public:
    CatchMouse();
    CatchMouse(int p_type);

    bool getPressedState();

    //virtual inherit qobject
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void signalMouseCatch(QPoint);
};

#endif // CATCHMOUSE_H
