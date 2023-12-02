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
};

#endif // PLAYER_H
