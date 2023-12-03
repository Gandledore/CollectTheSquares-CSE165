#ifndef PLAYER_H
#define PLAYER_H

#include <QOpenGLWidget>
#include <QLabel>
#include "target.h"

class Player : public QOpenGLWidget{

Q_OBJECT

public:
    Player(QWidget *parent = nullptr, Target** targs = nullptr);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void keyPressEvent(QKeyEvent *event) override;
    void updatePlayerPosition();

    void updateTimer();

    bool checkTargetCollision(Target* t);
    int checkCollisions();
    bool checkX(Target* t);

private:
    float rotationAngle;
    float x_pos;
    float y_pos;
    QTimer *move_timer;
    float move_speed;
    Target** targets;
};

#endif // PLAYER_H
