#include<QApplication>
#include "mywindow.hpp"
int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    MyWindow mywindow;
    mywindow.show();
    //testObject->show();
    return app.exec();
}
