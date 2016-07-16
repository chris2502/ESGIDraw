#ifndef RESIZETOOLMENU_H
#define RESIZETOOLMENU_H

#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QString>
#include <QPoint>
#include <QPushButton>

class ResizeToolMenu: public QWidget
{
    Q_OBJECT
    QSpinBox *sizeX;
    QSpinBox *sizeY;
     QPushButton *button;

public:
    ResizeToolMenu(QPoint point, int defaultSizeX, int defaultSizeY);

    void setPositionSpinBoxX(int positionSpinBoxX);
    void setPositionSpinBoxY(int positionSpinBoxY);

public slots:
    void slotResize();

signals:
    void signalResize(int, int);
};

#endif // RESIZETOOLMENU_H
