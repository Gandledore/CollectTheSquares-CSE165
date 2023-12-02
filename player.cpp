#include "player.h"
#include <QOpenGLFunctions>
#include <QKeyEvent>


Player::Player(QWidget *parent)
    : QOpenGLWidget(parent), rotationAngle(0.0f){
    setFocusPolicy(Qt::StrongFocus);
}

void Player::initializeGL(){
     QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->initializeOpenGLFunctions();
    glClearColor(0.392f, 0.122f, 0.502f, 1.0f);
}

void Player::resizeGL(int w, int h){
    glViewport(0,0,w,h);
}

void Player::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // glTranslatef(0.0f, 0.0f, -1.0f); // Move the triangle away from the camera
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f); // Rotate around the z-axis

    float scale_factor = 0.1;
    GLfloat vertices[] = {
        0.0f, 0.5f*scale_factor, 0.0f,   // Top vertex
        -0.25f*scale_factor, -0.25f*scale_factor, 0.0f, // Bottom-left vertex
        0.25f*scale_factor, -0.25f*scale_factor, 0.0f   // Bottom-right vertex
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glColor3f(.8f, 0.69f, 0.204f); // Green color
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void Player::keyPressEvent(QKeyEvent *event){
    float rotation_speed = 5.0f;
    switch(event->key()){
        case Qt::Key_Left:
            rotationAngle += rotation_speed;
            break;
        case Qt::Key_Right:
            rotationAngle -= rotation_speed;
                break;
        default:
            break;
    } //End of switch

        update();
}
