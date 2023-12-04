#include "player.h"
#include <QOpenGLFunctions>
#include <QKeyEvent>
#include <QTimer>
#include "target.h"
#include "fasttarget.h"
#include "weirdtarget.h"

#include <QTime>
#include <QElapsedTimer>
#include <QLabel>
#include <QFont>
#include <string>

// QElapsedTimer *timer = new QElapsedTimer();

QTimer* track;
QLabel *label;
QElapsedTimer t;
int count = 0;

Player::Player(QWidget *parent, Target** targs)
    : QOpenGLWidget(parent), rotationAngle(0.0f), x_pos(0.0f), y_pos(0.0f), move_speed(0.05f){
    setFocusPolicy(Qt::StrongFocus);
    targets = targs;
    num_targets_left = 25;
    move_timer = new QTimer(this);
    connect(move_timer, &QTimer::timeout, this, &Player::updatePlayerPosition);
    move_timer->start(16); //Draw Interval

    label = new QLabel(this);
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(50,50,100,50);
    QFont f( "Open Sans", 20, QFont::Bold);
    label->setStyleSheet("QLabel { background-color : black; color:white}");
    label->setFont(f);
    // label->setText("first line\nsecond line");

    track = new QTimer(this);
    track->setInterval(1000);

    connect(track, &QTimer::timeout, this, &Player::updateTimer);
    track->start(); //

    t.start(); // overarching

}

// QTime t;
// QTime startTime = t.currentTime();
// QTime endTime;

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

bool Player::checkTargetCollision(Target* t){
    return (600*(x_pos+1) >= t->getXleft()) && 600*(x_pos+1) <= t->getXright() && 300*(1-y_pos) >= t->getYup() && 300*(1-y_pos)<=t->getYDown();
}

int Player::checkCollisions(){
    for(int i =0;i<25;i++){
        if(targets[i]!=nullptr){
            if(i%2==0){
                (dynamic_cast<weirdTarget*>(targets[i]))->updatePos();
            }
            else{
                (dynamic_cast<fastTarget*>(targets[i]))->updatePos();
            }
            if(checkTargetCollision(targets[i])){
                count++;
                delete targets[i];
                targets[i]=nullptr;
                num_targets_left--;
                if(num_targets_left<=0){
                    finalTime = t.elapsed()/1000;
                    qDebug() << "tada" << t.durationElapsed()/1000000000.0 << "s";
                    label->hide();
                    emit gameEnd();
                }
                return i;
            }
        }
    }
    return -1;
}

void Player::updatePlayerPosition(){
    float speed = 0.05f;
    y_pos += speed * std::cos(qDegreesToRadians(rotationAngle));
    if(std::abs(y_pos)>=1){
        y_pos*=-1;
    }
    x_pos -= speed * std::sin(qDegreesToRadians(rotationAngle));
    if(std::abs(x_pos)>=1){
        x_pos*=-1;
    }
    int crash = checkCollisions();
    update();
}

void Player::updateTimer() {
    int times = t.elapsed()/1000;
    std::string times1 = std::to_string(times);
    QString qstr = QString::fromStdString(times1);
    label->setText(qstr);
}
