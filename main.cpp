#include <QApplication>
#include "esteroid.h"
#include "player.h"
#include "target.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Esteroid w;
    Player *ship = new Player(&w);
    Target** targets = new Target*[16];
    for(int i=0;i<16;i++){
        targets[i] = new Target(&w,550+100*(i%4),200+100*(i/4));
    }
    // w.setCentralWidget(ship);
    w.setGeometry(0, 0, 1200, 600);
    w.show();
    return a.exec();
}
