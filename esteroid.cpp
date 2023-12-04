#include "esteroid.h"
#include "ui_esteroid.h"
#include <QTimer>
#include <QLabel>
#include "player.h"

#include <QPushButton>
#include <QFont>

Esteroid::Esteroid(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Esteroid)
{
    ui->setupUi(this);

    // QTimer *timer = new QTimer(this);
    // connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    // timer->start(1000);
    Target** targets = new Target*[16];
    Player *ship = new Player(this,targets);
    for(int i=0;i<16;i++){
        targets[i] = new Target(this,550+100*(i%4),200+100*(i/4));
    }
    connect(ship,&Player::gameEnd,this,&Esteroid::finishGame);
}

void Esteroid::finishGame(int finalTime) {

    QPushButton *closeButton = new QPushButton("Close Game", this);
    connect(closeButton, &QPushButton::clicked, this, &Esteroid::closeGame);
    closeButton->setGeometry(550, 250, 100, 30);
    closeButton->show();

    QLabel *finalTimeLabel = new QLabel(this);
    QFont f( "Open Sans", 20, QFont::Bold);
    finalTimeLabel->setStyleSheet("QLabel { background-color : black; color:white}");
    finalTimeLabel->setFont(f);
    finalTimeLabel->setText("Score: " + QString::number(finalTime) + " seconds");
    finalTimeLabel->setGeometry(400, 140, 400, 40);
    finalTimeLabel->setAlignment(Qt::AlignCenter);
    finalTimeLabel->show();

}

void Esteroid::closeGame()
{
    close();
}


Esteroid::~Esteroid()
{
    delete ui;
}
