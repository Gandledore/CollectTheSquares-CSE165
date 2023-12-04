#ifndef TARGET_H
#define TARGET_H
#include <QOpenGLWidget>


class Target : public QOpenGLWidget{

    Q_OBJECT

public:
    Target(QWidget *parent = nullptr, float x=0, float y=0);
    float getXleft();
    float getXright();
    float getYup();
    float getYDown();
    virtual void updatePos();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    float initial_x;
    float initial_y;
    float x_pos;
    float y_pos;
    float target_width;
    float target_height;
};

#endif // TARGET_H
