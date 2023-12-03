#ifndef CIRCLE_H
#define CIRCLE_H

#include <QOpenGLWidget>

class Circle : public QOpenGLWidget{

    Q_OBJECT

public:
    Circle(QWidget *parent = nullptr);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

};

#endif // CIRCLE_H
