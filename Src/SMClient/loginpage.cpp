#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    w.hide();
    loginImg.load(":/images/loginbg.jpg");
    this->setWindowFlag(Qt::FramelessWindowHint);        //隐藏窗口边框
    ui->passwd->setEchoMode(QLineEdit::Password);

    connect(ui->exitBtn,SIGNAL(clicked(bool)),
            this,SLOT(exitBtnSlot()));
    connect(ui->loginBtn,SIGNAL(clicked(bool)),
            this,SLOT(loginBtnSlot()));
    connect(&w,SIGNAL(LogOffSignal()),this,SLOT(logOffSlot()));


    /*动画的实例化和设置*/
    aniIn = new QPropertyAnimation(this);
    aniOut = new QPropertyAnimation(this);

    aniIn->setDuration(100);               //设置周期为100毫秒
    aniOut->setDuration(100);
    aniIn->setPropertyName("geometry");    //设置动画的属性为形状
    aniOut->setPropertyName("geometry");

    /*为界面上的按键安装上相应的事件过滤器，以便产生特有的动画效果*/
    ui->loginBtn->installEventFilter(this);
    ui->exitBtn->installEventFilter(this);

    winOpacity = new QPropertyAnimation(this,"windowOpacity");
    winOpacity->setDuration(1000);
    winOpacity->setStartValue(0);
    winOpacity->setEndValue(1);
    winOpacity->start();
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::loginBtnSlot()
{
    NetWorkDev::getObject()->connectToServer(NETWORKIPADDR,NETWORKPORT);
    w.show();
    this->hide();
}

void LoginPage::logOffSlot()
{
    this->show();
    w.hide();
}


void LoginPage::exitBtnSlot()
{
    /*当动画结束时关闭软件*/
    connect(winOpacity,SIGNAL(finished()),this,SLOT(close()));
    /*设置并启动关闭软件时的动画效果*/
    winOpacity->setStartValue(1);
    winOpacity->setEndValue(0);
    winOpacity->start();
}

void LoginPage::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        //左键按下，求得当前窗口的左上角坐标
        p = event->globalPos() - this->frameGeometry().topLeft();
    }
}

void LoginPage::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        //鼠标在按下时发生移动，相应移动当前窗口
        move(event->globalPos() - p);
    }
}

void LoginPage::paintEvent(QPaintEvent *)
{
    QPainter pa(this);
    pa.drawImage(QRect(0,0,this->width(),this->height()),loginImg,
                 QRect(0,0,loginImg.width()-300,loginImg.height()));
    QPen pen;
    QBrush logo(QPixmap(":/images/smartHomeLogo.ico"));
    pen.setWidth(5);
    pen.setColor(QColor("green"));
    pa.setPen(pen);
    pa.setBrush(logo);                         //用图片填充原型区域
    pa.drawEllipse(QPoint(300,140),75,75);
}

bool LoginPage::eventFilter(QObject *watched, QEvent *event)
{
    //事件过滤器函数的重载
    if(watched == ui->loginBtn || watched == ui->exitBtn )
    {
        //事件对象为指定的按键
        if(event->type() == QEvent::Enter)
        {
            //事件的类型为移入事件，设置并启动动画
            aniIn->setTargetObject(watched);
            QPushButton  *hoverBtn = static_cast<QPushButton*>(watched);
            aniIn->setStartValue(QRect(hoverBtn->x(),hoverBtn->y(),50,30));
            QRect t = QRect(hoverBtn->x(), hoverBtn->y(),
                    50, 40);
            aniIn->setEndValue(t);
            if(aniOut->state() == QAbstractAnimation::Running)
            {
                //上一个动画处于运行状态
                if(aniOut->targetObject() == watched)
                {
                    //上一个动画对象和本次动画对象为同一个对象，解决快速移出又快速移入同一按钮动画问题
                    maxAni = new QPropertyAnimation(hoverBtn,"geometry");
                    maxAni->setDuration(1);
                    maxAni->setStartValue(QRect(hoverBtn->geometry()));
                    maxAni->setEndValue(QRect(hoverBtn->x(),hoverBtn->y(),50,40));
                    maxAni->start();
                    return true;
                }
                else
                {
                    //上一个动画对象和本次动画对象为不同对象，解决快速移出有快速移入不同按钮的问题
                    QPushButton *lastBtn = static_cast<QPushButton*>(lastObj);
                    minAni = new QPropertyAnimation(lastObj,"geometry");
                    minAni->setDuration(1);
                    minAni->setStartValue(QRect(lastBtn->geometry()));
                    minAni->setEndValue(QRect(lastBtn->x(),lastBtn->y(),50,30));
                    minAni->start();
                }
            }
            lastObj = watched;     //记录下上一次产生动画的对象
            aniIn->start();

            //qDebug() << "鼠标移入按键";
            return true;
        }
        else if(event->type() == QEvent::Leave)
        {
            //事件类型为移出，设置并启动动画
            aniOut->setTargetObject(watched);
            QPushButton  *hoverBtn = static_cast<QPushButton*>(watched);
            aniOut->setStartValue(QRect(hoverBtn->x(),hoverBtn->y(),50,40));
            aniOut->setEndValue(QRect(hoverBtn->x(), hoverBtn->y(),
                                50, 30));
            if(aniIn->state() == QAbstractAnimation::Running)
            {
                //这里不存在上次动画对象和本次动画对象不一致的问题，故只有一种情况
                if(aniIn->targetObject() == watched)
                {
                    //上一次动画未完成，且和本次动画为同一对象
                    minAni = new QPropertyAnimation(hoverBtn,"geometry");
                    minAni->setDuration(1);
                    minAni->setStartValue(QRect(hoverBtn->geometry()));
                    minAni->setEndValue(QRect(hoverBtn->x(),hoverBtn->y(),50,30));
                    minAni->start();
                    return true;
                }
            }
            lastObj = watched;   //记录下上一次产生动画的对象
            aniOut->start();
            //qDebug() << "鼠标移出按键";
            return true;
        }
        else{
            //事件为其他类型，交由父类正常处理
            return QWidget::eventFilter(watched,event);
        }
    }
    else
    {
        //事件对象为指定按钮以外的对象，交由父类正常处理
        return QWidget::eventFilter(watched, event);
    }
}
