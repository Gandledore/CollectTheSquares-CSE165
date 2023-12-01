#include "esteroid.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Esteroid w;
    w.show();
    return a.exec();
}
