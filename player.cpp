#include "player.h"
#include <QOpenGLFunctions>
#include <QKeyEvent>
#include <QTimer>
#include "target.h"

Player::Player(QWidget *parent, Target** targs)
    : QOpenGLWidget(parent), rotationAngle(0.0f), x_pos(0.0f), y_pos(0.0f), move_speed(0.05f){
    setFocusPolicy(Qt::StrongFocus);
    targets = targs;
    num_targets_left = 16;
    move_timer = new QTimer(this);
    connect(move_timer, &QTimer::timeout, this, &Player::updatePlayerPosition);
    move_timer->start(16); //Draw Interval
}

void Player::initializeGL(){
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->initializeOpenGLFunctions();
    glClearColor(0, 0, 0, 1); //Background
    setGeometry(0,0,1200,600);
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
    glColor3f(0, 1, 0); //Gold
    glVertex3f(0.0f,                0.5f*scale_factor  , 0.0f); // Top vertex
    glVertex3f(-0.25f*scale_factor, -0.25f*scale_factor, 0.0f); // Bottom-left vertex
    glVertex3f(0.25f*scale_factor,  -0.25f*scale_factor, 0.0f); // Bottom-right vertex
    glEnd();
}

void Player::keyPressEvent(QKeyEvent *event){
    float rotation_speed = 5.0f;
    // float speed = 0.01f;
    switch(event->key()){
        case Qt::Key_Left:
            rotationAngle += rotation_speed;
            break;
        case Qt::Key_Right:
            rotationAngle -= rotation_speed;
                break;
        // case Qt::Key_Up:
        //     y_pos += speed * std::cos(qDegreesToRadians(rotationAngle));
        //     x_pos -= speed * std::sin(qDegreesToRadians(rotationAngle));
        //     break;
        default:
            break;
    } //End of switch

        update();
}
// bool Player::checkX(Target* t){
//     qDebug() << "Target X bounds" << t->x_pos << t->x_pos+t->target_width << "| Player:" << 600*(x_pos+1) << "||" << t->y_pos << t->y_pos+t->target_height << "| Player:"<< 300*(1-y_pos);
//     if(){
//         qDebug() << "Within them";
//         return true;
//     }
//     return false;
// }
bool Player::checkTargetCollision(Target* t){
    return (600*(x_pos+1) >= t->x_pos && 600*(x_pos+1) <= t->x_pos+t->target_width && 300*(1-y_pos) >= t->y_pos && 300*(1-y_pos)<=t->y_pos+t->target_height);
}
int Player::checkCollisions(){
    for(int i =0;i<16;i++){
        if(targets[i]!=nullptr){
            if(checkTargetCollision(targets[i])){
                delete targets[i];
                targets[i]=nullptr;
                num_targets_left--;
                if(num_targets_left<=0){
                    emit gameEnd();
                }
                return i;
            }
        }
    }
    return -1;
}
void Player::updatePlayerPosition(){
    float speed = 0.004f;
    y_pos += speed * std::cos(qDegreesToRadians(rotationAngle));
    x_pos -= speed * std::sin(qDegreesToRadians(rotationAngle));
    int crash = checkCollisions();
    update();
}
