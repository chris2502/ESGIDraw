#ifndef RIGHTTOOLMENU_H
#define RIGHTTOOLMENU_H

#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QString>
#include <QPoint>

class RightToolMenu: public QWidget
{
    Q_OBJECT
    QSpinBox *prioritySPinBox;
    QSpinBox *positionSpinBoxX;
    QSpinBox *positionSpinBoxY;
    QSpinBox *opacitySpinBox;
public:
    RightToolMenu(QPoint point);

    void setPositionSpinBoxX(int positionSpinBoxX);
    void setPositionSpinBoxY(int positionSpinBoxY);

public slots:
    void slotPriority(int);
    void slotPositionX(int);
    void slotPositionY(int);
    void slotOpacity(int);
signals:
    void signalPriority(int);
    void signalPositionX(int);
    void signalPositionY(int);
    void signalOpacity(qreal);
};

#endif // RIGHTTOOLMENU_H
