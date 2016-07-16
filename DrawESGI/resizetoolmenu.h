#ifndef RESIZETOOLMENU_H
#define RESIZETOOLMENU_H

#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QString>
#include <QPoint>

class ResizeToolMenu: public QWidget
{
    Q_OBJECT
    QSpinBox *sizeX;
    QSpinBox *sizeY;
public:
    ResizeToolMenu(QPoint point);

    void setPositionSpinBoxX(int positionSpinBoxX);
    void setPositionSpinBoxY(int positionSpinBoxY);

public slots:
    void slotResizeX(int);
    void slotResizeY(int);
signals:
    void signalResizeX(int);
    void signalResizeY(int);
};

#endif // RESIZETOOLMENU_H
