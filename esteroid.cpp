#include "esteroid.h"
#include "ui_esteroid.h"
#include <QTimer>
#include <QLabel>

Esteroid::Esteroid(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Esteroid)
{
    ui->setupUi(this);

    // QTimer *timer = new QTimer(this);
    // connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    // timer->start(1000);
}

Esteroid::~Esteroid()
{
    delete ui;
}
