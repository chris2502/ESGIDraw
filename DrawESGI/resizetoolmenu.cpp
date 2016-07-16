#include "resizetoolmenu.h"
#include <QDebug>
ResizeToolMenu::ResizeToolMenu(QPoint p)
{
    sizeX= new QSpinBox();
    sizeX->setMaximum(400);
    sizeY= new QSpinBox();
    sizeY->setMaximum(400);
    //opacitySpinBox->setValue(10);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow(tr("&Width :"), sizeX);
    formLayout->addRow(tr("&Height :"), sizeY);

    connect(sizeX, SIGNAL(valueChanged(int)), this, SLOT(slotResizeX(int)));
    connect(sizeY, SIGNAL(valueChanged(int)), this, SLOT(slotResizeY(int)));

    setLayout(formLayout);
    this->move(p.x()+400, p.y()+100);
    this->setWindowTitle("Tools Menu");
    this->show();
}

void ResizeToolMenu::slotResizeX(int priority){
    emit signalResizeX(priority);
}

void ResizeToolMenu::slotResizeY(int positionX){
    emit signalResizeY(positionX);
}
