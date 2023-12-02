#ifndef PLAYER_H
#define PLAYER_H

#include <QOpenGLWidget>


class Player : public QOpenGLWidget{

Q_OBJECT

public:
    Player(QWidget *parent = nullptr);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void keyPressEvent(QKeyEvent *event) override;
    void updatePlayerPosition();

private:
    float rotationAngle;
    float x_pos;
    float y_pos;
    QTimer *move_timer;
    float move_speed;
};

#endif // PLAYER_H
