#include <QApplication>
#include "esteroid.h"
#include "player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Esteroid w;
    Player *ship = new Player(&w);
    w.setCentralWidget(ship);
    w.setGeometry(100, 100, 800, 600);
    w.show();
    return a.exec();
}
