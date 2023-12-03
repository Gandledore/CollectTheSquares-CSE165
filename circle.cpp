#include "circle.h"
#include <QOpenGLFunctions>

Circle::Circle(QWidget *parent) {
}

void Circle::initializeGL(){
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Transparent background
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Circle::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
}

void Circle::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -1.0f); // Move the circle away from the camera

    const int numSegments = 100;
    const float radius = 2.0f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 1.0f, 0.0f); // Red color
    glVertex2f(0.0f, 0.0f); // Center of the circle

    for (int i = 0; i <= numSegments; ++i) {
        float theta = 2.0f * 3.1415926f * static_cast<float>(i) / static_cast<float>(numSegments);
        float x = radius * std::cos(theta);
        float y = radius * std::sin(theta);
        glVertex2f(x, y);
    }

    glEnd();
}
