#include "player.h"
#include <QOpenGLFunctions>


Player::Player(QWidget *parent)
    : QOpenGLWidget(parent){
}

void Player::initializeGL(){
     QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Player::resizeGL(int w, int h){
    glViewport(0,0,w,h);
}

void Player::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glVertex3f(0.0f, 0.5f, 0.0f); // Top vertex
    glVertex3f(-0.5f, -0.5f, 0.0f); // Bottom-left vertex
    glVertex3f(0.5f, -0.5f, 0.0f); // Bottom-right vertex
    glEnd();

}
