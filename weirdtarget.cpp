#include "weirdtarget.h"

weirdTarget::weirdTarget(QWidget *parent, float x, float y) : Target(parent,x,y) {
    speed = .05;
}
void weirdTarget::updatePos(){
    x_pos += speed * -(y_pos-initial_y+20)*x_pos/y_pos;
    y_pos += speed * (x_pos-initial_x+30);
    setGeometry(x_pos,y_pos,target_width,target_height);
    update();
}
weirdTarget::~weirdTarget(){}
