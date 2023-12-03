#include "meteor.h"
#include <QOpenGLFunctions>

Meteor::Meteor(float radius, float initialX, float initialY, QWidget *parent)
    : Circle(parent) {
    setGeometry(initialX, initialY, radius, radius);
}

void Meteor::initializeGL() {
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Transparent background
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Meteor::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // glOrtho(0, w, h, 0, -1, 1); // Orthographic projection
    // glMatrixMode(GL_MODELVIEW);
}

void Meteor::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(x() + width() / 2.0f, y() + height() / 2.0f, 0.0f); // Move the meteor to its position

    const int numSegments = 10;
    const float radius = width() / 2.0f; // Use half of the width as the radius

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(0.0f, 0.0f); // Center of the circle

    for (int i = 0; i <= numSegments; ++i) {
        float theta = 2.0f * 3.1415926f * static_cast<float>(i) / static_cast<float>(numSegments);
        float x = radius * std::cos(theta);
        float y = radius * std::sin(theta);
        glVertex2f(x, y);
    }

    glEnd();
}
