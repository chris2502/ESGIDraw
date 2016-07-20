#include "righttoolmenu.hpp"
RightToolMenu::RightToolMenu(QPoint p)
{

    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    barMenu = new QMenuBar(this);
    menuPixmap= new QMenu("Images");
    barMenu->addMenu(menuPixmap);


    prioritySPinBox= new QSpinBox();
    prioritySPinBox->setMaximum(20);
    prioritySPinBox->setMinimum(-20);
    prioritySPinBox->setDisabled(true);

    positionSpinBoxX= new QSpinBox();
    positionSpinBoxX->setMaximum(400);
    positionSpinBoxX->setDisabled(true);

    positionSpinBoxY= new QSpinBox();
    positionSpinBoxY->setMaximum(400);
    positionSpinBoxY->setDisabled(true);

    opacitySpinBox = new QSpinBox();
    opacitySpinBox->setMaximum(20);
    opacitySpinBox->setValue(10);
    opacitySpinBox->setDisabled(true);
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

RightToolMenu::~RightToolMenu(){
    delete prioritySPinBox;
    delete positionSpinBoxX;
    delete positionSpinBoxY;
    delete opacitySpinBox;
    delete menuPixmap;
    delete barMenu;
    foreach (QAction* action, pixmapAction) {
        delete action;
    }
    pixmapAction.clear();
}

void RightToolMenu::setPositionSpinBoxX(int positionSpinBoxX){
    this->positionSpinBoxX->setValue( positionSpinBoxX);
}

void RightToolMenu::setPositionSpinBoxY(int positionSpinBoxY){
    this->positionSpinBoxY->setValue(positionSpinBoxY);
}

void RightToolMenu::setPrioritySpinBox(int prioritySpinBox){
    this->prioritySPinBox->setValue(prioritySpinBox);
}

void RightToolMenu::setOpacitySpinBox(int opacitySpinBox){
    this->opacitySpinBox->setValue(opacitySpinBox);
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
    foreach (QAction *actionVar, menuPixmap->actions()) {
        actionVar->setChecked(false);
    }
    QAction *action = new QAction(fileName, this);
    action->setCheckable(true);
    action->setChecked(true);
    menuPixmap->addAction(action);

    connect(menuPixmap, SIGNAL(triggered(QAction*)), SLOT(slotSelectPixmap(QAction*)));
}

void RightToolMenu::slotSelectPixmap(QAction * action){

    foreach (QAction *actionVar, menuPixmap->actions()) {
        if(actionVar != action){
            actionVar->setChecked(false);

        }
    }
    action->setChecked(true);
    emit signalSelectPixmap((action->text()));
}

bool RightToolMenu::isEnable(){
    if(prioritySPinBox->isEnabled() && positionSpinBoxX->isEnabled() && positionSpinBoxY->isEnabled() &&
       opacitySpinBox->isEnabled()){
        return true;
    }
    return false;
}

void RightToolMenu::setEnabled(bool value){
    prioritySPinBox->setEnabled(value);
    positionSpinBoxX->setEnabled(value);
    positionSpinBoxY->setEnabled(value);
    opacitySpinBox->setEnabled(value);
}
