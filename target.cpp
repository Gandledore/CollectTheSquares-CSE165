#include "target.h"
#include <QOpenGLFunctions>
Target::Target(QWidget *parent, float x, float y)
    : QOpenGLWidget(parent), x_pos(x), y_pos(y){

}

void Target::initializeGL(){
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->initializeOpenGLFunctions();
    glClearColor(.5, .5, .5, 1); //Background
    setGeometry(x_pos,y_pos,10,10);
}

void Target::resizeGL(int w, int h){
    glViewport(0,0,w,h);
}

void Target::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    // Draw the player (triangle) here
    glColor4f(.5,.5,.5,1);
    glBegin(GL_QUADS);
    float scale_factor = 0.1f;
    glVertex2f(-1, -1);  // Bottom-left
    glVertex2f(1, -1);   // Bottom-right
    glVertex2f(1, 1);    // Top-right
    glVertex2f(-1, 1);   // Top-left
    glEnd();
}
