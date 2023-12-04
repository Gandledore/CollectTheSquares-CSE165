#include "fasttarget.h"

fastTarget::fastTarget(QWidget *parent, float x, float y) : Target(parent,x,y) {
    speed = .1;
}
void fastTarget::updatePos(){
    x_pos += speed * -(y_pos-initial_y+30);
    y_pos += speed * (x_pos-initial_x+30);
    setGeometry(x_pos,y_pos,target_width,target_height);
    update();
}
fastTarget::~fastTarget(){}
