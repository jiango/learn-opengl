//
// Created by jiang on 2024/4/4.
//

#include <QGLShaderProgram>
#include "MyOpenGLWidget.h"
#include <QOpenGLFunctions>

unsigned int VAO[2];
unsigned int VBO[2];
QGLShaderProgram program;
QGLShaderProgram program2;

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent) {

}

void MyOpenGLWidget::initializeGL() {
    QOpenGLFunctions_3_3_Core::initializeOpenGLFunctions();

    glGenVertexArrays(2,VAO);
    glGenBuffers(2, VBO);

    float vertices[] = {
            0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
            0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };

    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    program.addShaderFromSourceFile(QGLShader::Vertex, ":/shader/shader/triangle.vert");
    program.addShaderFromSourceFile(QGLShader::Fragment, ":/shader/shader/triangle.frag");
    program.link();
}

void MyOpenGLWidget::resizeGL(int w, int h) {
}

void MyOpenGLWidget::paintGL() {
    glClearColor(0.2, 0.2, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    program.bind();
    glBindVertexArray(VAO[0]);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
