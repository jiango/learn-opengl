//
// Created by jiang on 2024/4/4.
//

#include "MyOpenGLWidget.h"

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent) {

}

void MyOpenGLWidget::initializeGL() {
    QOpenGLFunctions_3_3_Core::initializeOpenGLFunctions();
}

void MyOpenGLWidget::resizeGL(int w, int h) {
}

void MyOpenGLWidget::paintGL() {
    glClearColor(0.0, 0.0, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
