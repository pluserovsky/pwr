#include "inwentarz.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    inwentarz w;
    w.show();

    return a.exec();
}
