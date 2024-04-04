//
// Created by jiang on 2024/4/4.
//

#ifndef INC_01_HELLOWIDGET_MYOPENGLWIDGET_H
#define INC_01_HELLOWIDGET_MYOPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>

class MyOpenGLWidget : public QOpenGLWidget, QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
public:
    explicit MyOpenGLWidget(QWidget* parent = nullptr);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

};


#endif //INC_01_HELLOWIDGET_MYOPENGLWIDGET_H
