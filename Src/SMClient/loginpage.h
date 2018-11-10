#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include "mainpage.h"
#include <QPropertyAnimation>
#include <QMouseEvent>
#include "networkdev.h"
#include "config.h"
#include <QEvent>
#include <QPoint>
#include <QImage>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QObject>
#include <QPixmap>
#include <QPaintEvent>

namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = 0);
    ~LoginPage();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);

    bool eventFilter(QObject *watched, QEvent *event); //虚函数事件过滤器的重写，
                                                       //过滤出按钮的移进移出事件

protected slots:
    void loginBtnSlot();
    void logOffSlot();
    void exitBtnSlot();
private:
    QImage loginImg;                    //背景图片
    MainPage w;
    QPoint p;                         //实现无边框的窗口移动，在两个鼠标事件中传递信息
    QPropertyAnimation * winOpacity;
    QPropertyAnimation * aniIn;         //移进按键动画
    QPropertyAnimation * aniOut;        //移出按键动画
    QPropertyAnimation * minAni;
    QPropertyAnimation * maxAni;
    QObject *lastObj;                  //修复切换动画过快产生的按键重叠bug，记录上一个动画对象
    Ui::LoginPage *ui;
};

#endif // LOGINPAGE_H
