#ifndef RIGHTTOOLMENU_H
#define RIGHTTOOLMENU_H

#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QString>
#include <QPoint>
#include <QAction>
#include <QVector>
#include <QMenuBar>
#include<QLayout>
class RightToolMenu: public QWidget
{
    Q_OBJECT
    QSpinBox *prioritySPinBox;
    QSpinBox *positionSpinBoxX;
    QSpinBox *positionSpinBoxY;
    QSpinBox *opacitySpinBox;
    bool enableInput;
    QString fileNameActive;
    QMenu *menuPixmap;
    QMenuBar * barMenu;
    QVector<QAction*> pixmapAction;
public:
    RightToolMenu(QPoint point);
    ~RightToolMenu();
    void setPositionSpinBoxX(int positionSpinBoxX);
    void setPositionSpinBoxY(int positionSpinBoxY);

    void setPrioritySpinBox(int prioritySPinBox);

    void setOpacitySpinBox(int opacitySpinBox);

    void addFileNameImageToAction(QString);
    void setFileNameActive(QString);

    virtual bool isEnable();
    virtual void setEnabled(bool);

public slots:
    void slotPriority(int);
    void slotPositionX(int);
    void slotPositionY(int);
    void slotOpacity(int);
    void slotSelectPixmap(QAction*);

signals:
    void signalPriority(int);
    void signalPositionX(int);
    void signalPositionY(int);
    void signalOpacity(qreal);
    void signalSelectPixmap(QString);

};

#endif // RIGHTTOOLMENU_H
