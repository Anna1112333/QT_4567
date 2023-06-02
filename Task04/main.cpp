#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    int i=0;
    QApplication::setStyle("fusion");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
