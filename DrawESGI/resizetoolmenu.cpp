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

    button = new QPushButton();

    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow(tr("&Width :"), sizeX);
    formLayout->addRow(tr("&Height :"), sizeY);
    formLayout->addRow(tr("&Valider :"), button);

    connect(button, SIGNAL(clicked()), this, SLOT(slotResize()));

    setLayout(formLayout);
    this->move(p.x()+400, p.y()+100);
    this->setWindowTitle("Tools Menu");
    this->show();
}


ResizeToolMenu::~ResizeToolMenu(){
    delete sizeX;
    delete sizeY;
    delete button;
}

void ResizeToolMenu::slotResize(){
    emit signalResize(sizeX->value(), sizeY->value());
}
