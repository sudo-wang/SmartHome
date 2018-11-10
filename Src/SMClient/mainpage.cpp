#include "mainpage.h"
#include "ui_mainpage.h"
#include "networkprotocol.h"
#include "iconhelper.h"
#include <QDebug>

#define iconSize    50
#define iconWidth   100
#define iconHeight  70
#define navBtnWidth 45
#define navIcoWidth 18

MainPage::MainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    this->initForm();
    this->initNav();
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::initForm()
{
    ui->labTitle->setText("智能家居系统");
    this->setWindowTitle(ui->labTitle->text());
    this->setProperty("canMove", true);
    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    ui->widgetTop->setProperty("flag", "nav");
    ui->widgetTop->setFixedHeight(40);
    ui->stackedWidget->setCurrentIndex(0);

    ui->btnReturn->setText("首页");
    ui->btnMsg->setText("退出");

    ui->lnTe->display(25);    // 设定空调的初始温度为 25 度

    QStringList qss;

    //全局无焦点虚边框,全局文字颜色,全局字号
    qss.append(QString("*{outline:0px;color:#FEFEFE;}"));

    //主窗体背景
    qss.append(QString("QWidget#widgetMain{border-image:url(%1);}").arg(":/images/main.jpg"));

    //标题字体大小
    qss.append(QString("QLabel#labTitle{font:%1px;}").arg(navIcoWidth));

    //顶部导航
    qss.append(QString("QWidget[flag=\"nav\"]{background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,"
                       "stop:0 %1,stop:1 %2);}").arg("#00688B").arg("#093746"));
    qss.append(QString("QWidget[flag=\"nav\"] QAbstractButton{background:none;border:none;"
                       "min-width:%1px;max-width:%1px;}").arg(navBtnWidth));

    this->setStyleSheet(qss.join(""));
}

void MainPage::initNav()
{
    QList<QString> listColorBg;
    listColorBg << "#1570A5" << "#16A085" << "#C0392B" << "#047058" << "#9B59BB" << "#34495E";
    QList<QString> listColorText;
    listColorText << "#FEFEFE" << "#FEFEFE" << "#FEFEFE" << "#FEFEFE" << "#FEFEFE" << "#FEFEFE";

    QList<QString> listText;
    listText << "环境监测" << "热水器" << "空调" << "LED" << "窗帘" << "注销";

    btns << ui->btnShow << ui->btnHeater << ui->btnAirCon << ui->btnLED << ui->btnWindow << ui->btnCancellation;
    for (int i = 0; i < btns.count(); i++) {
        QToolButton *btn = btns.at(i);
        btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btn->setIconSize(QSize(iconWidth, iconHeight));

        btn->setText(listText.at(i));

        QStringList list;
        list.append(QString("QToolButton{font:%1px;background:%2;}").arg(iconSize / 2.5).arg(listColorBg.at(i)));
        list.append(QString("QToolButton{border:none;border-radius:8px;padding:30px;}"));
        list.append(QString("QToolButton:pressed{background:%1;}").arg("#737A97"));
        btn->setStyleSheet(list.join(""));

        connect(btn, SIGNAL(clicked(bool)), this, SLOT(buttonClicked()));
    }
}

void MainPage::buttonClicked()
{
    QToolButton *btn = (QToolButton *)sender();
    if(btn->text() == "环境监测")
        ui->stackedWidget->setCurrentIndex(1);
    if(btn->text() == "热水器")
        ui->stackedWidget->setCurrentIndex(2);
    if(btn->text() == "空调")
        ui->stackedWidget->setCurrentIndex(3);
    if(btn->text() == "LED")
        ui->stackedWidget->setCurrentIndex(4);
    if(btn->text() == "窗帘")
        ui->stackedWidget->setCurrentIndex(5);
    if(btn->text() == "注销")                               // 实现了注销页面跳转到登陆界面
        emit LogOffSignal();
//        ui->stackedWidget->setCurrentIndex(1);
    ui->labTitle->setText(btn->text());
    ui->btnReturn->setText("返回");
}

void MainPage::on_btnReturn_pressed()
{
    int index = ui->stackedWidget->currentIndex();
    if (index != 0) {
        ui->stackedWidget->setCurrentIndex(0);
        ui->labTitle->setText("智能家居系统");
        ui->btnReturn->setText("首页");
    }
}

void MainPage::on_btnMsg_pressed()      // 加入退出登录时，所有设备进入初始状态
{
    NetWorkProtocol::getObject()->setHeart(1001,1,0);    // 初始化默认值
    NetWorkProtocol::getObject()->setHeart(1001,2,0);
    NetWorkProtocol::getObject()->setLed(1001,1,0);
    NetWorkProtocol::getObject()->setLed(1001,2,0);
    NetWorkProtocol::getObject()->setLed(1001,3,0);
    NetWorkProtocol::getObject()->setLed(1001,4,0);
    NetWorkProtocol::getObject()->setCurtains(1001,1,0);
    NetWorkProtocol::getObject()->setCurtains(1001,2,0);
    NetWorkProtocol::getObject()->setCurtains(1001,3,0);
    NetWorkProtocol::getObject()->setCurtains(1001,4,0);
    NetWorkProtocol::getObject()->setAir(1001,1,Heating,Auto,25);
    exit(0);
}


// 热水器界面
void MainPage::on_heartBtn_stateChanged(int arg1)    // 按钮
{
    if(arg1)     // 开
    {
        heartState = 1;
    }
    else       // 关
    {
        heart = 0;
        NetWorkProtocol::getObject()->setHeart(1001,1,heart);   // 初始化
        ui->heaterlSlider->setValue(heart);
        heartState = 0;
    }
}

void MainPage::on_heartBtn_2_stateChanged(int arg1)
{
    if(arg1)
    {
        heartState_2 = 1;
    }
    else
    {
        heart = 0;
        NetWorkProtocol::getObject()->setHeart(1001,2,heart);
        ui->heaterlSlider_2->setValue(heart);
        heartState_2 = 0;
    }
}

void MainPage::on_heartPushButton_3_clicked()
{
    if(heartState){                  // 保证开关在关的状态下操纵设备无效
        heart = ui->heartLineEdit_3->text().toInt();
        NetWorkProtocol::getObject()->setHeart(1001,1,heart);
        ui->heaterlSlider->setValue(heart);      // 将水平条状态更新
    }
}

void MainPage::on_heartPushButton_4_clicked()
{
    if(heartState_2){
        heart = ui->heartLineEdit_4 ->text().toInt();
        NetWorkProtocol::getObject()->setHeart(1001,2,heart);
        ui->heaterlSlider_2->setValue(heart);
    }
}



// LED 界面
void MainPage::on_ledBtn_stateChanged(int arg1)
{
    if(arg1)
    {
        ledState = 1;
    }
    else
    {
        NetWorkProtocol::getObject()->setLed(1001,1,0);
        ui->ledSlider->setValue(0);
        ledState = 0;
    }
}

void MainPage::on_ledBtn_2_stateChanged(int arg1)
{
    if(arg1)
    {
        ledState_2 = 1;
    }
    else
    {
        NetWorkProtocol::getObject()->setLed(1001,2,0);
        ui->ledSlider_2->setValue(0);
        ledState_2 = 0;
    }
}

void MainPage::on_ledBtn_3_stateChanged(int arg1)
{
    if(arg1)
    {
        ledState_3 = 1;
    }
    else
    {
        NetWorkProtocol::getObject()->setLed(1001,3,0);
        ui->ledSlider_3->setValue(0);
        ledState_3 = 0;
    }
}

void MainPage::on_ledBtn_4_stateChanged(int arg1)
{
    if(arg1)
    {
        ledState_4 = 1;
    }
    else
    {
        NetWorkProtocol::getObject()->setLed(1001,4,0);
        ui->ledSlider_4->setValue(0);
        ledState_4 = 0;
    }
}

void MainPage::on_ledSlider_valueChanged(int value)    // led 水平拖拉条
{
    if(ledState)       // 保证在开关关的状态下操作无效
        NetWorkProtocol::getObject()->setLed(1001,1,value);
}

void MainPage::on_ledSlider_2_valueChanged(int value)
{
    if(ledState_2)
        NetWorkProtocol::getObject()->setLed(1001,2,value);
}

void MainPage::on_ledSlider_3_valueChanged(int value)
{
    if(ledState_3)
        NetWorkProtocol::getObject()->setLed(1001,3,value);
}

void MainPage::on_ledSlider_4_valueChanged(int value)
{
    if(ledState_4)
        NetWorkProtocol::getObject()->setLed(1001,4,value);
}



// 窗帘界面
void MainPage::on_curtainsBtn_stateChanged(int arg1)
{
    if(arg1)
    {
        curtainsState = 1;
    }
    else
    {
        NetWorkProtocol::getObject()->setCurtains(1001,1,0);
        ui->curtainsSlider->setValue(0);
        curtainsState = 0;
    }
}

void MainPage::on_curtainsBtn_2_stateChanged(int arg1)
{
    if(arg1)
    {
        curtainsState_2 = 1;
    }
    else
    {
        NetWorkProtocol::getObject()->setCurtains(1001,2,0);
        ui->curtainsSlider_2->setValue(0);
        curtainsState_2 = 0;
    }
}

void MainPage::on_curtainsBtn_3_stateChanged(int arg1)
{
    if(arg1)
    {
        curtainsState_3 = 1;
    }
    else
    {
        NetWorkProtocol::getObject()->setCurtains(1001,3,0);
        ui->curtainsSlider_3->setValue(0);
        curtainsState_3 = 0;
    }
}

void MainPage::on_curtainsBtn_4_stateChanged(int arg1)
{
    if(arg1)
    {
        curtainsState_4 = 1;
    }
    else
    {
        NetWorkProtocol::getObject()->setCurtains(1001,4,0);
        ui->curtainsSlider_4->setValue(0);
        curtainsState_4 = 0;
    }
}

void MainPage::on_curtainsSlider_valueChanged(int value)
{
    if(curtainsState)
        NetWorkProtocol::getObject()->setCurtains(1001,1,value);
}

void MainPage::on_curtainsSlider_2_valueChanged(int value)
{
    if(curtainsState_2)
        NetWorkProtocol::getObject()->setCurtains(1001,2,value);
}

void MainPage::on_curtainsSlider_3_valueChanged(int value)
{
    if(curtainsState_3)
        NetWorkProtocol::getObject()->setCurtains(1001,3,value);
}

void MainPage::on_curtainsSlider_4_valueChanged(int value)
{
    if(curtainsState_4)
        NetWorkProtocol::getObject()->setCurtains(1001,4,value);
}




// 空调界面
void MainPage::on_airBtn_stateChanged(int arg1)    // 判断开关开关
{
    if(arg1)
    {
        airState = 1;
    }
    else
    {
        NetWorkProtocol::getObject()->setAir(1001,1,Heating,Auto,25);    // 关空调采用默认值
        curtainsState = 0;
    }
}

void MainPage::on_btnAirAdd_clicked()
{
    te = ui->lnTe->intValue();
    if(te < 35)
        te++;
    ui->lnTe->display(te);
}

void MainPage::on_btnAirSub_clicked()
{
    te = ui->lnTe->intValue();
    if(te > 16)
        te--;
    ui->lnTe->display(te);
}


void MainPage::on_pushButton_clicked()
{
    if(airState)
    {
        int fun = ui->cbAirFun->currentIndex();                                        // 返回当前列表框中选中文本的序号
        int modules = ui->cbAirFun->currentIndex();                                    // 返回当前列表框中选中文本的序号
        NetWorkProtocol::getObject()->setAir(1001,1,(Modules)modules,(Fun)fun,te);     // int 类型转枚举类型
    }
}

