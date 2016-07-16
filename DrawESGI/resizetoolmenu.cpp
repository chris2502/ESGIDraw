#include "resizetoolmenu.h"
#include <QDebug>
ResizeToolMenu::ResizeToolMenu(QPoint p, int defaultSizeX, int defaultSizeY)
{

    sizeX= new QSpinBox();
    sizeX->setMaximum(1000);
    sizeX->setValue(defaultSizeX);
    sizeY= new QSpinBox();
    sizeY->setMaximum(1000);
    sizeY->setValue(defaultSizeY);
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

void ResizeToolMenu::slotResizeX(int newSizeX){
    emit signalResizeX(newSizeX);
}

void ResizeToolMenu::slotResizeY(int newSizeY){
    emit signalResizeY(newSizeY);
}
