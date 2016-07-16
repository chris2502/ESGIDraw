#include "righttoolmenu.hpp"
#include <QDebug>
RightToolMenu::RightToolMenu(QPoint p)
{

    barMenu = new QMenuBar(this);


    //pixmapAction = new QVector<QAction*>();
//    menuPixmap->addAction(&pixmapAction);
    prioritySPinBox= new QSpinBox();
    prioritySPinBox->setMaximum(20);
    positionSpinBoxX= new QSpinBox();
    positionSpinBoxX->setMaximum(400);
    positionSpinBoxY= new QSpinBox();
    positionSpinBoxY->setMaximum(400);
    opacitySpinBox = new QSpinBox();
    opacitySpinBox->setMaximum(20);
    opacitySpinBox->setValue(10);
    QFormLayout *formLayout = new QFormLayout();
    formLayout->setMargin(50);
    formLayout->addRow(tr("&Priority:"), prioritySPinBox);
    formLayout->addRow(tr("&Position x:"), positionSpinBoxX);
    formLayout->addRow(tr("&Position y:"), positionSpinBoxY);
    formLayout->addRow(tr("&Opacity:"), opacitySpinBox);



    connect(prioritySPinBox, SIGNAL(valueChanged(int)), this, SLOT(slotPriority(int)));
    connect(positionSpinBoxX, SIGNAL(valueChanged(int)), this, SLOT(slotPositionX(int)));
    connect(positionSpinBoxY, SIGNAL(valueChanged(int)), this, SLOT(slotPositionY(int)));
    connect(opacitySpinBox, SIGNAL(valueChanged(int)), this, SLOT(slotOpacity(int)));

    setLayout(formLayout);
    this->move(p.x()+400, p.y()+100);
    this->setWindowTitle("Tools Menu");
}


void RightToolMenu::setPositionSpinBoxX(int positionSpinBoxX){
    this->positionSpinBoxX->setValue( positionSpinBoxX);
}

void RightToolMenu::setPositionSpinBoxY(int positionSpinBoxY){
    this->positionSpinBoxY->setValue(positionSpinBoxY);
}



void RightToolMenu::slotPriority(int priority){
    emit signalPriority(priority);
}

void RightToolMenu::slotPositionX(int positionX){
    emit signalPositionX(positionX);
}

void RightToolMenu::slotPositionY(int positionY){
    emit signalPositionY(positionY);
}

void RightToolMenu::slotOpacity(int opacity){
    qreal r= (1.0 *opacity) /10;
    emit signalOpacity(r);
}


void RightToolMenu::setFileNameActive(QString fileNameActive){
    this->fileNameActive=fileNameActive;
}

void RightToolMenu::addFileNameImageToAction(QString fileName){
    QAction *action = new QAction(fileName, this);
    action->setCheckable(true);
    barMenu->addAction(action);
    connect(barMenu, SIGNAL(triggered(QAction*)), SLOT(slotSelectPixmap(QAction*)));
}

void RightToolMenu::slotSelectPixmap(QAction * action){

    foreach (QAction *actionVar, barMenu->actions()) {
        if(actionVar != action){
            actionVar->setChecked(false);

        }
    }
    action->setChecked(true);
    emit signalSelectPixmap((action->text()));
}
