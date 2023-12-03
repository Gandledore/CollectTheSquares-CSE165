#ifndef TARGET_H
#define TARGET_H
#include <QOpenGLWidget>


class Target : public QOpenGLWidget{

    Q_OBJECT

public:
    Target(QWidget *parent = nullptr, float x=0, float y=0);
    float x_pos;
    float y_pos;
    float target_width;
    float target_height;

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

};

#endif // TARGET_H
