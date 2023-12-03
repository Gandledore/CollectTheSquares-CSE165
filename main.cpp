#include <QApplication>
#include <QTimer>
#include "esteroid.h"
#include "player.h"
#include "meteor.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Esteroid w;
    Player *ship = new Player(&w);
    w.setCentralWidget(ship);
    w.setGeometry(100, 100, 800, 600);
    w.show();

    // Create a BigMeteor instance and add it to the central widget
    Meteor *bigMeteor = new Meteor(0.5f, 1.0f, 1.0f, &w);
    w.setCentralWidget(bigMeteor);

    // Use a timer to regularly update the game state
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&] {
        // Update the player and meteor positions
        ship->update();
        bigMeteor->update();
    });

    timer.start(16); // Adjust the interval as needed

    return a.exec();
}
