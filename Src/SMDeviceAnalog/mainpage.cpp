#include "mainpage.h"
#include "ui_mainpage.h"
#include "serialportdev.h"
#include "serialportprotocol.h"

MainPage::MainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    this->setWindowTitle("智能家居模拟设备终端");
    this->setWindowIcon(QIcon(":/logo.ico"));

    ui->lnTe->display("25");
    ui->lnTe_2->display("25");
    ui->lnTe_3->display("25");
    ui->lnTe_4->display("25");

    //将系统检测到的串口添加到下拉框中
    ui->cbPortName->addItems(SerialPortDev::getObject()->getSerialList());

    //将传感器数据设定固定的有效范围
    QDoubleValidator *doubleVal = new QDoubleValidator(0, 100, 2, this);
    QIntValidator *intVal10 = new QIntValidator(0, 10, this);
    QIntValidator *intVal500 = new QIntValidator(0, 500, this);
    QIntValidator *intVal5000 = new QIntValidator(0, 5000, this);
    QIntValidator *intVal20000 = new QIntValidator(0, 20000, this);
    ui->lineEdit->setValidator(doubleVal);
    ui->lineEdit_2->setValidator(doubleVal);
    ui->lineEdit_3->setValidator(intVal20000);
    ui->lineEdit_4->setValidator(intVal500);
    ui->lineEdit_5->setValidator(intVal5000);
    ui->lineEdit_6->setValidator(intVal500);
    ui->lineEdit_7->setValidator(intVal500);
    ui->lineEdit_8->setValidator(intVal10);
    ui->lineEdit_9->setValidator(intVal500);
    ui->lineEdit_10->setValidator(intVal500);

    //设置LED和窗帘的滑条不可用
    ui->hsLed->setEnabled(false);
    ui->hsLed_2->setEnabled(false);
    ui->hsLed_3->setEnabled(false);
    ui->hsLed_4->setEnabled(false);
    ui->hscurtains->setEnabled(false);
    ui->hscurtains_2->setEnabled(false);
    ui->hscurtains_3->setEnabled(false);
    ui->hscurtains_4->setEnabled(false);

    ui->stackedWidget->setCurrentIndex(0);


    connect(SerialPortProtocol::getObject(),
            SIGNAL(newAirConditionerControl(int,int,int,int)),
            this,
            SLOT(newAirConditionerControlSlot(int,int,int,int)));
    connect(SerialPortProtocol::getObject(),
            SIGNAL(newLedControl(int,int)),
            this,
            SLOT(newLedControlSlot(int,int)));
    connect(SerialPortProtocol::getObject(),
            SIGNAL(newHeaterControl(int,int)),
            this,SLOT(newHeaterControlSlot(int,int)));
    connect(SerialPortProtocol::getObject(),
            SIGNAL(newCurtainsControl(int,int)),
            this,SLOT(newCurtainsControlSlot(int,int)));
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_btnOpenSerial_clicked()
{
    if(ui->btnOpenSerial->text() == "打开")
    {
        if(SerialPortDev::getObject()->openSerial(
                    ui->cbPortName->currentText(),
                    ui->cbBaudrate->currentText().toInt()))
        {
            ui->btnOpenSerial->setText("关闭");
        }
    }
    else
    {
        SerialPortDev::getObject()->closeSerial();
        ui->btnOpenSerial->setText("打开");
    }
}

void MainPage::newAirConditionerControlSlot(int index, int model, int te, int fun)
{
    switch (index) {
    case 0x01:
        if(model < 4)
        {
            ui->cbAirModel->setCurrentIndex(model);
            ui->lbAirStatus->setText("开");
        }
        else
            ui->lbAirStatus->setText("关");
        ui->cbAirFun->setCurrentIndex(fun);
        if(te >= 16 && te <= 35)
            ui->lnTe->display(te);
        break;
    case 0x02:
        if(model < 4)
        {
            ui->cbAirModel_2->setCurrentIndex(model);
            ui->lbAirStatus_2->setText("开");
        }
        else
            ui->lbAirStatus_2->setText("关");
        ui->cbAirFun_2->setCurrentIndex(fun);
        if(te >= 16 && te <= 35)
            ui->lnTe_2->display(te);
        break;
    case 0x03:
        if(model < 4)
        {
            ui->cbAirModel_3->setCurrentIndex(model);
            ui->lbAirStatus_3->setText("开");
        }
        else
            ui->lbAirStatus_3->setText("关");
        ui->cbAirFun_3->setCurrentIndex(fun);
        if(te >= 16 && te <= 35)
            ui->lnTe_3->display(te);
        break;
    case 0x04:
        if(model < 4)
        {
            ui->cbAirModel_4->setCurrentIndex(model);
            ui->lbAirStatus_4->setText("开");
        }
        else
            ui->lbAirStatus_4->setText("关");
        ui->cbAirFun_4->setCurrentIndex(fun);
        if(te >= 16 && te <= 35)
            ui->lnTe_4->display(te);
        break;
    default:
        break;
    }
}

void MainPage::newLedControlSlot(int index, int b)
{
    switch (index) {
    case 0x01:
        ui->hsLed->setValue(b);
        break;
    case 0x02:
        ui->hsLed_2->setValue(b);
        break;
    case 0x03:
        ui->hsLed_3->setValue(b);
        break;
    case 0x04:
        ui->hsLed_4->setValue(b);
        break;
    }
}

void MainPage::newHeaterControlSlot(int index, int te)
{
    if(te > 100 || te < 0)
        return;
    switch (index) {
    case 0x01:
        ui->heater->setValue(te);
        break;
    case 0x02:
        ui->heater_2->setValue(te);
        break;
    }
}

void MainPage::newCurtainsControlSlot(int index, int pos)
{
    switch (index) {
    case 0x01:
        ui->hscurtains->setValue(pos);
        break;
    case 0x02:
        ui->hscurtains_2->setValue(pos);
        break;
    case 0x03:
        ui->hscurtains_3->setValue(pos);
        break;
    case 0x04:
        ui->hscurtains_4->setValue(pos);
        break;
    }
}

void MainPage::on_btnAirOpen_clicked()
{
    if(ui->lbAirStatus->text() == "开")
        ui->lbAirStatus->setText("关");
    else
        ui->lbAirStatus->setText("开");
}

void MainPage::on_btnAirAdd_clicked()
{
    if(ui->lnTe->intValue() < 35)
        ui->lnTe->display( ui->lnTe->intValue() + 1);
}

void MainPage::on_btnAirSub_clicked()
{
    if(ui->lnTe->intValue() > 16)
        ui->lnTe->display( ui->lnTe->intValue() - 1);
}

void MainPage::on_lineEdit_textChanged(const QString &arg1)
{
    SerialPortProtocol::getObject()->te1 =
            arg1.toDouble();
}

void MainPage::on_lineEdit_2_textChanged(const QString &arg1)
{
    SerialPortProtocol::getObject()->hu1 =
            arg1.toDouble();
}

void MainPage::on_lineEdit_3_textChanged(const QString &arg1)
{
    SerialPortProtocol::getObject()->light1 =
            arg1.toInt();
}

void MainPage::on_lineEdit_4_textChanged(const QString &arg1)
{
    SerialPortProtocol::getObject()->uv1 =
            arg1.toInt();
}

void MainPage::on_lineEdit_5_textChanged(const QString &arg1)
{
    SerialPortProtocol::getObject()->co21 =
            arg1.toInt();
}

void MainPage::on_lineEdit_6_textChanged(const QString &arg1)
{
    SerialPortProtocol::getObject()->pm251 =
            arg1.toInt();
}

void MainPage::on_lineEdit_7_textChanged(const QString &arg1)
{
    SerialPortProtocol::getObject()->pm101 =
            arg1.toInt();
}

void MainPage::on_lineEdit_8_textChanged(const QString &arg1)
{
    SerialPortProtocol::getObject()->atmospheric1 =
            arg1.toInt();
}

void MainPage::on_lineEdit_9_textChanged(const QString &arg1)
{
    SerialPortProtocol::getObject()->iReserve1 =
            arg1.toInt();
}

void MainPage::on_lineEdit_10_textChanged(const QString &arg1)
{
    SerialPortProtocol::getObject()->iReserve2 =
            arg1.toInt();
}

void MainPage::on_pushButton_clicked()
{
    if(ui->pushButton->text() == "正常")
    {
        SerialPortProtocol::getObject()->fire1 = true;
        ui->pushButton->setText("异常");
    }
    else
    {
        SerialPortProtocol::getObject()->fire1 = false;
        ui->pushButton->setText("正常");
    }
}

void MainPage::on_pushButton_2_clicked()
{
    if(ui->pushButton_2->text() == "正常")
    {
        SerialPortProtocol::getObject()->mq51 = true;
        ui->pushButton_2->setText("异常");
    }
    else
    {
        SerialPortProtocol::getObject()->mq51 = false;
        ui->pushButton_2->setText("正常");
    }
}

void MainPage::on_pushButton_4_clicked()
{
    if(ui->pushButton_4->text() == "正常")
    {
        SerialPortProtocol::getObject()->mq21 = true;
        ui->pushButton_4->setText("异常");
    }
    else
    {
        SerialPortProtocol::getObject()->mq21 = false;
        ui->pushButton_4->setText("正常");
    }
}

void MainPage::on_pushButton_5_clicked()
{
    if(ui->pushButton_5->text() == "正常")
    {
        SerialPortProtocol::getObject()->os1 = true;
        ui->pushButton_5->setText("异常");
    }
    else
    {
        SerialPortProtocol::getObject()->os1 = false;
        ui->pushButton_5->setText("正常");
    }
}

void MainPage::on_pushButton_6_clicked()
{
    if(ui->pushButton_6->text() == "正常")
    {
        SerialPortProtocol::getObject()->re1 = true;
        ui->pushButton_6->setText("异常");
    }
    else
    {
        SerialPortProtocol::getObject()->re1 = false;
        ui->pushButton_6->setText("正常");
    }
}

void MainPage::on_pushButton_8_clicked()
{
    if(ui->pushButton_8->text() == "正常")
    {
        SerialPortProtocol::getObject()->bReserve1 = true;
        ui->pushButton_8->setText("异常");
    }
    else
    {
        SerialPortProtocol::getObject()->bReserve1 = false;
        ui->pushButton_8->setText("正常");
    }
}

void MainPage::on_pushButton_9_clicked()
{
    if(ui->pushButton_9->text() == "正常")
    {
        SerialPortProtocol::getObject()->bReserve2 = true;
        ui->pushButton_9->setText("异常");
    }
    else
    {
        SerialPortProtocol::getObject()->bReserve2 = false;
        ui->pushButton_9->setText("正常");
    }
}

void MainPage::on_pushButton_10_clicked()
{
    if(ui->pushButton_10->text() == "正常")
    {
        SerialPortProtocol::getObject()->bReserve3 = true;
        ui->pushButton_10->setText("异常");
    }
    else
    {
        SerialPortProtocol::getObject()->bReserve3 = false;
        ui->pushButton_10->setText("正常");
    }
}

void MainPage::on_pushButton_11_clicked()
{
    if(ui->pushButton_11->text() == "正常")
    {
        SerialPortProtocol::getObject()->bReserve4 = true;
        ui->pushButton_11->setText("异常");
    }
    else
    {
        SerialPortProtocol::getObject()->bReserve4 = false;
        ui->pushButton_11->setText("正常");
    }
}

void MainPage::on_pushButton_12_clicked()
{
    if(ui->pushButton_12->text() == "正常")
    {
        SerialPortProtocol::getObject()->bReserve5 = true;
        ui->pushButton_12->setText("异常");
    }
    else
    {
        SerialPortProtocol::getObject()->bReserve5 = false;
        ui->pushButton_12->setText("正常");
    }
}

void MainPage::on_btnAirOpen_2_clicked()
{
    if(ui->lbAirStatus_2->text() == "开")
        ui->lbAirStatus_2->setText("关");
    else
        ui->lbAirStatus_2->setText("开");
}

void MainPage::on_btnAirOpen_3_clicked()
{
    if(ui->lbAirStatus_3->text() == "开")
        ui->lbAirStatus_3->setText("关");
    else
        ui->lbAirStatus_3->setText("开");
}

void MainPage::on_btnAirOpen_4_clicked()
{
    if(ui->lbAirStatus_4->text() == "开")
        ui->lbAirStatus_4->setText("关");
    else
        ui->lbAirStatus_4->setText("开");
}

void MainPage::on_btnAirAdd_2_clicked()
{
    if(ui->lnTe_2->intValue() < 35)
        ui->lnTe_2->display( ui->lnTe_2->intValue() + 1);
}

void MainPage::on_btnAirAdd_3_clicked()
{
    if(ui->lnTe_3->intValue() < 35)
        ui->lnTe_3->display( ui->lnTe_3->intValue() + 1);
}

void MainPage::on_btnAirAdd_4_clicked()
{
    if(ui->lnTe_4->intValue() < 35)
        ui->lnTe_4->display( ui->lnTe_4->intValue() + 1);
}

void MainPage::on_btnAirSub_2_clicked()
{
    if(ui->lnTe_2->intValue() > 16)
        ui->lnTe_2->display( ui->lnTe_2->intValue() - 1);
}

void MainPage::on_btnAirSub_3_clicked()
{
    if(ui->lnTe_3->intValue() > 16)
        ui->lnTe_3->display( ui->lnTe_3->intValue() - 1);
}

void MainPage::on_btnAirSub_4_clicked()
{
    if(ui->lnTe_4->intValue() > 16)
        ui->lnTe_4->display( ui->lnTe_4->intValue() - 1);
}

void MainPage::on_btnnext_clicked()
{
    if(ui->stackedWidget->currentIndex() < ui->stackedWidget->count() - 1 )
    {
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);
    }
}

void MainPage::on_btnper_clicked()
{
    if(ui->stackedWidget->currentIndex() > 0 )
    {
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() - 1);
    }
}
