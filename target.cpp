#include "target.h"
#include <QOpenGLFunctions>
Target::Target(QWidget *parent, float x, float y)
    : QOpenGLWidget(parent), x_pos(x), y_pos(y){
    initial_x = x_pos;
    initial_y = y_pos;
    target_width =20;
    target_height = 20;
}

void Target::initializeGL(){
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->initializeOpenGLFunctions();
    glClearColor(.5, .5, .5, 1); //Background
    setGeometry(x_pos,y_pos,target_width,target_height);
}

void Target::resizeGL(int w, int h){
    glViewport(0,0,w,h);
}

void Target::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor4f(.5,.5,.5,1);

    glBegin(GL_QUADS);
    glVertex2f(-1, -1);  // Bottom-left
    glVertex2f(1, -1);   // Bottom-right
    glVertex2f(1, 1);    // Top-right
    glVertex2f(-1, 1);   // Top-left
    glEnd();
}

float Target::getXleft(){
    return x_pos;
}
float Target::getXright(){
    return x_pos+target_width;
}
float Target::getYup(){
    return y_pos;
}
float Target::getYDown(){
    return y_pos+target_height;
}
Target::~Target(){}
