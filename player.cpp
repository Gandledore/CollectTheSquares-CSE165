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
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Player::resizeGL(int w, int h){
    glViewport(0,0,w,h);
}

void Player::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -1.0f); // Move the triangle away from the camera
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f); // Rotate around the z-axis

    GLfloat vertices[] = {
        0.0f, 0.5f, 0.0f,   // Top vertex
        -0.5f, -0.5f, 0.0f, // Bottom-left vertex
        0.5f, -0.5f, 0.0f   // Bottom-right vertex
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void Player::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Left:
            rotationAngle -= 5.0f;
            break;
        case Qt::Key_Right:
            rotationAngle += 5.0f;
                break;
        default:
            break;
    } //End of switch

        update();
}
