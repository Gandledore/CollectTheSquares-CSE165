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
    glClearColor(0.392f, 0.122f, 0.502f, 0.0f); //Background
}

void Player::resizeGL(int w, int h){
    glViewport(0,0,w,h);
}

void Player::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(x_pos, y_pos, -1.0f); // Move the player to its position
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f); // Rotate around the z-axis

    // Draw the player (triangle) here
    glBegin(GL_TRIANGLES);
    float scale_factor = 0.1f;
    glColor3f(0.878f, 0.765f, 0.102f); //Gold
    glVertex3f(0.0f,                0.5f*scale_factor  , 0.0f); // Top vertex
    glVertex3f(-0.25f*scale_factor, -0.25f*scale_factor, 0.0f); // Bottom-left vertex
    glVertex3f(0.25f*scale_factor,  -0.25f*scale_factor, 0.0f); // Bottom-right vertex
    glEnd();
}

void Player::keyPressEvent(QKeyEvent *event){
    float rotation_speed = 5.0f;
    float speed = 0.01f;
    switch(event->key()){
        case Qt::Key_Left:
            rotationAngle += rotation_speed;
            break;
        case Qt::Key_Right:
            rotationAngle -= rotation_speed;
                break;
        case Qt::Key_Up:
            y_pos += speed * std::cos(qDegreesToRadians(rotationAngle));
            x_pos -= speed * std::sin(qDegreesToRadians(rotationAngle));
            break;
        default:
            break;
    } //End of switch

        update();
}
