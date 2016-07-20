#include<QApplication>
#include "mywindow.hpp"
int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    MyWindow mywindow;
    return app.exec();
}
