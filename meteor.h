#ifndef METEOR_H
#define METEOR_H

#include "circle.h"

class Meteor : public Circle {
public:
    Meteor(float radius, float initialX, float initialY, QWidget *parent = nullptr);

    void moveTowardsPlayer(float playerX, float playerY);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;


};

#endif // METEOR_H
