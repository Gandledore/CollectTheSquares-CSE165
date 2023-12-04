#include "esteroid.h"
#include "ui_esteroid.h"
#include <QTimer>
#include <QLabel>
#include "player.h"
#include "fasttarget.h"
#include "weirdtarget.h"

Esteroid::Esteroid(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Esteroid)
{
    ui->setupUi(this);

    // QTimer *timer = new QTimer(this);
    // connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    // timer->start(1000);
    Target** targets = new Target*[25];
    Player *ship = new Player(this,targets);
    for(int i=0;i<25;i++){
        if(i%2==0){
            targets[i] = new weirdTarget(this,400+100*(i%5),100+100*(i/5));
        }
        else{
            targets[i] = new fastTarget(this,400+100*(i%5),100+100*(i/5));
        }
    }
    connect(ship,&Player::gameEnd,this,&Esteroid::finishGame);
}

void Esteroid::finishGame(){
    close();
}

Esteroid::~Esteroid()
{
    delete ui;
}
