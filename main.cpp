#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
#ifndef APPLE
    a.setWindowIcon(QIcon("favicon.ico"));
#endif
    MainWindow w;
    w.show();
    return a.exec();
}
