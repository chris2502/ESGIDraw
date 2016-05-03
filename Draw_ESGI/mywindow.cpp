#include "mywindow.hpp"

MyWindow::MyWindow():QWidget()
{
    //params's main window
    w_win=QApplication::desktop()->width()/2;
    h_win= QApplication::desktop()->height()/2;
    x_win= w_win/2;
    y_win=h_win/2;
    setGeometry(x_win, y_win, w_win, h_win);

    //layout of the main window
    layoutGrid=new QGridLayout;

    //Menu bar of the main Window
    barMenu= new QMenuBar(this);


    //construct menu
    MyMenu myMenu;
    /*  add menu to abstractMenu.
        note that, we would had to parse directory to add plugin
    */
    menuList.push_back(&myMenu);
    //List item menu of bar menu
    foreach (AbstractMenu* menuAbstract, menuList) {
        QVector<QMenu*> tmpMenu=menuAbstract->ListMenu();
        foreach (QMenu* eltMenu, tmpMenu) {
            barMenu->addMenu(eltMenu);
        }
    }

    //Construct draw and picture
    MyDraw myDraw;
    MyPicture myPicture(myMenu.getImageChoose());
    /*  add draw and picture to abstractDrawPicture.
        note that, we would had to parse directory to add plugin
    */
    drawPictureList.push_back(&myDraw);
    drawPictureList.push_back(&myPicture);

    /*foreach (AbstractDrawPicture* drawPicture, drawPictureList) {
        viewGraphic=new QGraphicsView(drawPicture->getSceneGraphic());
    }
    */

    viewGraphic=new QGraphicsView(myPicture.getSceneGraphic());
    layoutGrid->addWidget(barMenu, 0, 1, 1, 5);
    layoutGrid->addWidget(viewGraphic, 1, 1, -1, 3);
    setLayout(layoutGrid);
    show();

}
