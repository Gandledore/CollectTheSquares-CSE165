#include "esteroid.h"
#include "ui_esteroid.h"
#include "player.h"

Esteroid::Esteroid(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Esteroid)
{
    ui->setupUi(this);
    Target** targets = new Target*[16];
    Player *ship = new Player(this,targets);
    for(int i=0;i<16;i++){
        targets[i] = new Target(this,550+100*(i%4),200+100*(i/4));
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
