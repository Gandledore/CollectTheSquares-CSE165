#include <QMainWindow>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    OpenGLWidget *openGLWidget = new OpenGLWidget(this);
    setCentralWidget(openGLWidget);
}