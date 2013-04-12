#include "mainwindow.h"
#include <QApplication>
#include "Field.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Field f(10, 10);
    f.resize(900, 700);
    f.show();

    return a.exec();
}
