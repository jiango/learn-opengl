//
// Created by jiang on 2024/4/4.
//

#include <QGLShaderProgram>
#include "MyOpenGLWidget.h"
#include <QOpenGLFunctions>

std::string vertexShaderSource =
        R"(#version 330 core
    layout (location=0) in vec3 aPos;
    void main() {
        gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    }
)";

std::string fragmentShaderSource =
        R"(#version 330 core
    void main() {
        gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
    }
)";

std::string fragmentShaderSource2 =
        R"(#version 330 core
    void main() {
        gl_FragColor = vec4(0.5, 0.5, 0.0, 1.0);
    }
)";
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
            0.0f, 0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f
    };
    float v2[] = {
            0.0f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            1.0f, 0.5f, 0.0f
    };

    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);

    glBufferData(GL_ARRAY_BUFFER, sizeof(v2), v2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    program.addShaderFromSourceCode(QGLShader::Vertex, vertexShaderSource.c_str());
    program.addShaderFromSourceCode(QGLShader::Fragment, fragmentShaderSource.c_str());
    program.link();

    program2.addShaderFromSourceCode(QGLShader::Vertex, vertexShaderSource.c_str());
    program2.addShaderFromSourceCode(QGLShader::Fragment, fragmentShaderSource2.c_str());
    program2.link();
}

void MyOpenGLWidget::resizeGL(int w, int h) {
}

void MyOpenGLWidget::paintGL() {
    glClearColor(0.0, 0.0, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    program.bind();
    glBindVertexArray(VAO[0]);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    program2.bind();
    glBindVertexArray(VAO[1]);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
