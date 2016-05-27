#ifndef CATCHMOUSE_H
#define CATCHMOUSE_H
#include <QWidget>
#include <QMouseEvent>
#include <QPoint>

class CatchMouse : public QWidget
{
    Q_OBJECT
public:
    CatchMouse();

    //virtual inherit qobject
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void signalMouseCatch(QPoint);
};

#endif // CATCHMOUSE_H
