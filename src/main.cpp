#include "mainwindow.h"
#include "./moduleView/projecttreewidget.h"
#include <QApplication>

#include "mypaintwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /* paintWidget */
//    MyPaintWidget myPaintWidget(nullptr);
//    myPaintWidget.show();
    /**/

    return a.exec();
}
