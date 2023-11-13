#include <QApplication>
#include "mainwindow.h"
//-------Blocks-------
#include "Blocks/Blue_Ricky.h"
#include "Blocks/Cleveland_Z.h"
#include "Blocks/Hero.h"
#include "Blocks/Orange_Ricky.h"
#include "Blocks/Rhode_Island_Z.h"
#include "Blocks/Smashboy.h"
#include "Blocks/Teewee.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}