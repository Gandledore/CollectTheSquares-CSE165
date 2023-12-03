#include <QApplication>
#include "esteroid.h"
#include "player.h"
#include "target.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Esteroid w;
    // w.setCentralWidget(ship);
    w.setGeometry(0, 0, 1200, 600);
    w.show();
    return a.exec();
}
