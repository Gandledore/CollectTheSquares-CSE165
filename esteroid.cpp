#include "esteroid.h"
#include "ui_esteroid.h"

Esteroid::Esteroid(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Esteroid)
{
    ui->setupUi(this);
}

Esteroid::~Esteroid()
{
    delete ui;
}
