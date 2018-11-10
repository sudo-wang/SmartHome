/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPage
{
public:
    QWidget *widgetMain;
    QVBoxLayout *verticalLayout;
    QWidget *widgetTop;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnReturn;
    QLabel *labTitle;
    QPushButton *btnMsg;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QToolButton *btnShow;
    QToolButton *btnHeater;
    QToolButton *btnAirCon;
    QToolButton *btnLED;
    QToolButton *btnWindow;
    QToolButton *btnCancellation;
    QWidget *Show;
    QWidget *Heater;
    QCheckBox *heartBtn_2;
    QCheckBox *heartBtn;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *heartLineEdit_3;
    QPushButton *heartPushButton_3;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *heartLineEdit_4;
    QPushButton *heartPushButton_4;
    QSlider *heaterlSlider;
    QSlider *heaterlSlider_2;
    QWidget *AirCon;
    QLabel *label;
    QCheckBox *airBtn;
    QPushButton *pushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *groupBox;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *cbAirModel;
    QComboBox *cbAirFun;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnAirSub;
    QPushButton *btnAirAdd;
    QGroupBox *groupBox_3;
    QLCDNumber *lnTe;
    QWidget *LED;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *ledBtn;
    QCheckBox *ledBtn_2;
    QCheckBox *ledBtn_3;
    QCheckBox *ledBtn_4;
    QVBoxLayout *verticalLayout_2;
    QSlider *ledSlider;
    QSlider *ledSlider_2;
    QSlider *ledSlider_3;
    QSlider *ledSlider_4;
    QWidget *Window;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_8;
    QCheckBox *curtainsBtn;
    QCheckBox *curtainsBtn_2;
    QCheckBox *curtainsBtn_3;
    QCheckBox *curtainsBtn_4;
    QVBoxLayout *verticalLayout_3;
    QSlider *curtainsSlider;
    QSlider *curtainsSlider_2;
    QSlider *curtainsSlider_3;
    QSlider *curtainsSlider_4;

    void setupUi(QWidget *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName(QStringLiteral("MainPage"));
        MainPage->resize(798, 479);
        widgetMain = new QWidget(MainPage);
        widgetMain->setObjectName(QStringLiteral("widgetMain"));
        widgetMain->setGeometry(QRect(0, 0, 800, 480));
        verticalLayout = new QVBoxLayout(widgetMain);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widgetTop = new QWidget(widgetMain);
        widgetTop->setObjectName(QStringLiteral("widgetTop"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetTop->sizePolicy().hasHeightForWidth());
        widgetTop->setSizePolicy(sizePolicy);
        widgetTop->setMaximumSize(QSize(16777215, 45));
        horizontalLayout = new QHBoxLayout(widgetTop);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnReturn = new QPushButton(widgetTop);
        btnReturn->setObjectName(QStringLiteral("btnReturn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnReturn->sizePolicy().hasHeightForWidth());
        btnReturn->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(btnReturn);

        labTitle = new QLabel(widgetTop);
        labTitle->setObjectName(QStringLiteral("labTitle"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labTitle->sizePolicy().hasHeightForWidth());
        labTitle->setSizePolicy(sizePolicy2);
        labTitle->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labTitle);

        btnMsg = new QPushButton(widgetTop);
        btnMsg->setObjectName(QStringLiteral("btnMsg"));
        sizePolicy1.setHeightForWidth(btnMsg->sizePolicy().hasHeightForWidth());
        btnMsg->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(btnMsg);


        verticalLayout->addWidget(widgetTop);

        stackedWidget = new QStackedWidget(widgetMain);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout = new QGridLayout(page);
        gridLayout->setSpacing(15);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(20, 20, 20, 20);
        btnShow = new QToolButton(page);
        btnShow->setObjectName(QStringLiteral("btnShow"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnShow->sizePolicy().hasHeightForWidth());
        btnShow->setSizePolicy(sizePolicy3);
        btnShow->setStyleSheet(QStringLiteral(""));
        btnShow->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnShow, 0, 0, 1, 1);

        btnHeater = new QToolButton(page);
        btnHeater->setObjectName(QStringLiteral("btnHeater"));
        sizePolicy3.setHeightForWidth(btnHeater->sizePolicy().hasHeightForWidth());
        btnHeater->setSizePolicy(sizePolicy3);
        btnHeater->setStyleSheet(QStringLiteral(""));
        btnHeater->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnHeater, 0, 1, 1, 1);

        btnAirCon = new QToolButton(page);
        btnAirCon->setObjectName(QStringLiteral("btnAirCon"));
        sizePolicy3.setHeightForWidth(btnAirCon->sizePolicy().hasHeightForWidth());
        btnAirCon->setSizePolicy(sizePolicy3);
        btnAirCon->setStyleSheet(QStringLiteral(""));
        btnAirCon->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnAirCon, 0, 2, 1, 1);

        btnLED = new QToolButton(page);
        btnLED->setObjectName(QStringLiteral("btnLED"));
        sizePolicy3.setHeightForWidth(btnLED->sizePolicy().hasHeightForWidth());
        btnLED->setSizePolicy(sizePolicy3);
        btnLED->setStyleSheet(QStringLiteral(""));
        btnLED->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnLED, 1, 0, 1, 1);

        btnWindow = new QToolButton(page);
        btnWindow->setObjectName(QStringLiteral("btnWindow"));
        sizePolicy3.setHeightForWidth(btnWindow->sizePolicy().hasHeightForWidth());
        btnWindow->setSizePolicy(sizePolicy3);
        btnWindow->setStyleSheet(QStringLiteral(""));
        btnWindow->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnWindow, 1, 1, 1, 1);

        btnCancellation = new QToolButton(page);
        btnCancellation->setObjectName(QStringLiteral("btnCancellation"));
        sizePolicy3.setHeightForWidth(btnCancellation->sizePolicy().hasHeightForWidth());
        btnCancellation->setSizePolicy(sizePolicy3);
        btnCancellation->setStyleSheet(QStringLiteral(""));
        btnCancellation->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnCancellation, 1, 2, 1, 1);

        stackedWidget->addWidget(page);
        Show = new QWidget();
        Show->setObjectName(QStringLiteral("Show"));
        stackedWidget->addWidget(Show);
        Heater = new QWidget();
        Heater->setObjectName(QStringLiteral("Heater"));
        heartBtn_2 = new QCheckBox(Heater);
        heartBtn_2->setObjectName(QStringLiteral("heartBtn_2"));
        heartBtn_2->setGeometry(QRect(430, 50, 161, 31));
        heartBtn_2->setStyleSheet(QLatin1String("QCheckBox::indicator:unchecked {\n"
"image: url(:/images/switch-off-icon.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/images/switch-on-icon.png);\n"
"}\n"
""));
        heartBtn = new QCheckBox(Heater);
        heartBtn->setObjectName(QStringLiteral("heartBtn"));
        heartBtn->setGeometry(QRect(50, 50, 161, 31));
        heartBtn->setStyleSheet(QLatin1String("QCheckBox::indicator:unchecked {\n"
"image: url(:/images/switch-off-icon.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/images/switch-on-icon.png);\n"
"}\n"
""));
        layoutWidget_2 = new QWidget(Heater);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(50, 120, 311, 131));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_3->setMargin(10);

        horizontalLayout_4->addWidget(label_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(10);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        heartLineEdit_3 = new QLineEdit(layoutWidget_2);
        heartLineEdit_3->setObjectName(QStringLiteral("heartLineEdit_3"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(4);
        sizePolicy4.setHeightForWidth(heartLineEdit_3->sizePolicy().hasHeightForWidth());
        heartLineEdit_3->setSizePolicy(sizePolicy4);
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(20);
        font.setBold(false);
        font.setWeight(50);
        heartLineEdit_3->setFont(font);
        heartLineEdit_3->setStyleSheet(QStringLiteral("background-color: transparent"));

        verticalLayout_6->addWidget(heartLineEdit_3);

        heartPushButton_3 = new QPushButton(layoutWidget_2);
        heartPushButton_3->setObjectName(QStringLiteral("heartPushButton_3"));
        heartPushButton_3->setStyleSheet(QStringLiteral("background-color: transparent"));

        verticalLayout_6->addWidget(heartPushButton_3);


        horizontalLayout_4->addLayout(verticalLayout_6);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 6);
        layoutWidget_3 = new QWidget(Heater);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(430, 120, 311, 131));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_4->setMargin(10);

        horizontalLayout_6->addWidget(label_4);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(10);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetDefaultConstraint);
        heartLineEdit_4 = new QLineEdit(layoutWidget_3);
        heartLineEdit_4->setObjectName(QStringLiteral("heartLineEdit_4"));
        sizePolicy4.setHeightForWidth(heartLineEdit_4->sizePolicy().hasHeightForWidth());
        heartLineEdit_4->setSizePolicy(sizePolicy4);
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(20);
        heartLineEdit_4->setFont(font1);
        heartLineEdit_4->setStyleSheet(QStringLiteral("background-color: transparent"));

        verticalLayout_7->addWidget(heartLineEdit_4);

        heartPushButton_4 = new QPushButton(layoutWidget_3);
        heartPushButton_4->setObjectName(QStringLiteral("heartPushButton_4"));
        heartPushButton_4->setStyleSheet(QStringLiteral("background-color: transparent"));

        verticalLayout_7->addWidget(heartPushButton_4);


        horizontalLayout_6->addLayout(verticalLayout_7);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 6);
        heaterlSlider = new QSlider(Heater);
        heaterlSlider->setObjectName(QStringLiteral("heaterlSlider"));
        heaterlSlider->setGeometry(QRect(50, 300, 311, 31));
        heaterlSlider->setOrientation(Qt::Horizontal);
        heaterlSlider_2 = new QSlider(Heater);
        heaterlSlider_2->setObjectName(QStringLiteral("heaterlSlider_2"));
        heaterlSlider_2->setGeometry(QRect(430, 300, 311, 31));
        heaterlSlider_2->setOrientation(Qt::Horizontal);
        stackedWidget->addWidget(Heater);
        AirCon = new QWidget();
        AirCon->setObjectName(QStringLiteral("AirCon"));
        label = new QLabel(AirCon);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 40, 121, 41));
        QFont font2;
        font2.setPointSize(15);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
        airBtn = new QCheckBox(AirCon);
        airBtn->setObjectName(QStringLiteral("airBtn"));
        airBtn->setGeometry(QRect(200, 50, 161, 31));
        airBtn->setStyleSheet(QLatin1String("QCheckBox::indicator:unchecked {\n"
"image: url(:/images/switch-off-icon.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/images/switch-on-icon.png);\n"
"}\n"
""));
        pushButton = new QPushButton(AirCon);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(680, 330, 91, 31));
        pushButton->setStyleSheet(QStringLiteral("background-color: transparent"));
        widget = new QWidget(AirCon);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 120, 741, 181));
        horizontalLayout_8 = new QHBoxLayout(widget);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 50, 191, 41));
        horizontalLayout_5 = new QHBoxLayout(widget1);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        cbAirModel = new QComboBox(widget1);
        cbAirModel->setObjectName(QStringLiteral("cbAirModel"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(cbAirModel->sizePolicy().hasHeightForWidth());
        cbAirModel->setSizePolicy(sizePolicy5);
        cbAirModel->setStyleSheet(QStringLiteral("background-color: transparent"));

        horizontalLayout_5->addWidget(cbAirModel);

        cbAirFun = new QComboBox(widget1);
        cbAirFun->setObjectName(QStringLiteral("cbAirFun"));
        sizePolicy5.setHeightForWidth(cbAirFun->sizePolicy().hasHeightForWidth());
        cbAirFun->setSizePolicy(sizePolicy5);
        cbAirFun->setMaximumSize(QSize(16777215, 16777215));
        cbAirFun->setStyleSheet(QStringLiteral("background-color: transparent"));
        cbAirFun->setEditable(false);

        horizontalLayout_5->addWidget(cbAirFun);


        horizontalLayout_8->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        layoutWidget_5 = new QWidget(groupBox_2);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(40, 30, 171, 111));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        btnAirSub = new QPushButton(layoutWidget_5);
        btnAirSub->setObjectName(QStringLiteral("btnAirSub"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(100);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(btnAirSub->sizePolicy().hasHeightForWidth());
        btnAirSub->setSizePolicy(sizePolicy6);
        btnAirSub->setMaximumSize(QSize(50, 50));
        QFont font3;
        font3.setFamily(QStringLiteral("Agency FB"));
        font3.setPointSize(28);
        font3.setBold(false);
        font3.setWeight(50);
        btnAirSub->setFont(font3);
        btnAirSub->setStyleSheet(QStringLiteral("background-color: transparent"));

        horizontalLayout_7->addWidget(btnAirSub);

        btnAirAdd = new QPushButton(layoutWidget_5);
        btnAirAdd->setObjectName(QStringLiteral("btnAirAdd"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(btnAirAdd->sizePolicy().hasHeightForWidth());
        btnAirAdd->setSizePolicy(sizePolicy7);
        btnAirAdd->setMaximumSize(QSize(50, 50));
        btnAirAdd->setFont(font3);
        btnAirAdd->setStyleSheet(QStringLiteral("background-color: transparent"));

        horizontalLayout_7->addWidget(btnAirAdd);


        horizontalLayout_8->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        lnTe = new QLCDNumber(groupBox_3);
        lnTe->setObjectName(QStringLiteral("lnTe"));
        lnTe->setGeometry(QRect(50, 30, 131, 81));
        lnTe->setLineWidth(1);
        lnTe->setDigitCount(2);

        horizontalLayout_8->addWidget(groupBox_3);

        stackedWidget->addWidget(AirCon);
        LED = new QWidget();
        LED->setObjectName(QStringLiteral("LED"));
        layoutWidget = new QWidget(LED);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 70, 551, 281));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        ledBtn = new QCheckBox(layoutWidget);
        ledBtn->setObjectName(QStringLiteral("ledBtn"));
        ledBtn->setStyleSheet(QLatin1String("QCheckBox::indicator:unchecked {\n"
"image: url(:/images/switch-off-icon.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/images/switch-on-icon.png);\n"
"}\n"
""));

        verticalLayout_5->addWidget(ledBtn);

        ledBtn_2 = new QCheckBox(layoutWidget);
        ledBtn_2->setObjectName(QStringLiteral("ledBtn_2"));
        ledBtn_2->setStyleSheet(QLatin1String("QCheckBox::indicator:unchecked {\n"
"image: url(:/images/switch-off-icon.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/images/switch-on-icon.png);\n"
"}\n"
""));

        verticalLayout_5->addWidget(ledBtn_2);

        ledBtn_3 = new QCheckBox(layoutWidget);
        ledBtn_3->setObjectName(QStringLiteral("ledBtn_3"));
        ledBtn_3->setStyleSheet(QLatin1String("QCheckBox::indicator:unchecked {\n"
"image: url(:/images/switch-off-icon.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/images/switch-on-icon.png);\n"
"}\n"
""));

        verticalLayout_5->addWidget(ledBtn_3);

        ledBtn_4 = new QCheckBox(layoutWidget);
        ledBtn_4->setObjectName(QStringLiteral("ledBtn_4"));
        ledBtn_4->setStyleSheet(QLatin1String("QCheckBox::indicator:unchecked {\n"
"image: url(:/images/switch-off-icon.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/images/switch-on-icon.png);\n"
"}\n"
""));

        verticalLayout_5->addWidget(ledBtn_4);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        ledSlider = new QSlider(layoutWidget);
        ledSlider->setObjectName(QStringLiteral("ledSlider"));
        ledSlider->setMaximum(255);
        ledSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(ledSlider);

        ledSlider_2 = new QSlider(layoutWidget);
        ledSlider_2->setObjectName(QStringLiteral("ledSlider_2"));
        ledSlider_2->setMaximum(255);
        ledSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(ledSlider_2);

        ledSlider_3 = new QSlider(layoutWidget);
        ledSlider_3->setObjectName(QStringLiteral("ledSlider_3"));
        ledSlider_3->setMaximum(255);
        ledSlider_3->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(ledSlider_3);

        ledSlider_4 = new QSlider(layoutWidget);
        ledSlider_4->setObjectName(QStringLiteral("ledSlider_4"));
        ledSlider_4->setMaximum(255);
        ledSlider_4->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(ledSlider_4);


        horizontalLayout_2->addLayout(verticalLayout_2);

        stackedWidget->addWidget(LED);
        Window = new QWidget();
        Window->setObjectName(QStringLiteral("Window"));
        layoutWidget_4 = new QWidget(Window);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(110, 80, 561, 281));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        curtainsBtn = new QCheckBox(layoutWidget_4);
        curtainsBtn->setObjectName(QStringLiteral("curtainsBtn"));
        curtainsBtn->setStyleSheet(QLatin1String("QCheckBox::indicator:unchecked {\n"
"image: url(:/images/switch-off-icon.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/images/switch-on-icon.png);\n"
"}\n"
""));

        verticalLayout_8->addWidget(curtainsBtn);

        curtainsBtn_2 = new QCheckBox(layoutWidget_4);
        curtainsBtn_2->setObjectName(QStringLiteral("curtainsBtn_2"));
        curtainsBtn_2->setStyleSheet(QLatin1String("QCheckBox::indicator:unchecked {\n"
"image: url(:/images/switch-off-icon.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/images/switch-on-icon.png);\n"
"}\n"
""));

        verticalLayout_8->addWidget(curtainsBtn_2);

        curtainsBtn_3 = new QCheckBox(layoutWidget_4);
        curtainsBtn_3->setObjectName(QStringLiteral("curtainsBtn_3"));
        curtainsBtn_3->setStyleSheet(QLatin1String("QCheckBox::indicator:unchecked {\n"
"image: url(:/images/switch-off-icon.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/images/switch-on-icon.png);\n"
"}\n"
""));

        verticalLayout_8->addWidget(curtainsBtn_3);

        curtainsBtn_4 = new QCheckBox(layoutWidget_4);
        curtainsBtn_4->setObjectName(QStringLiteral("curtainsBtn_4"));
        curtainsBtn_4->setStyleSheet(QLatin1String("QCheckBox::indicator:unchecked {\n"
"image: url(:/images/switch-off-icon.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/images/switch-on-icon.png);\n"
"}\n"
""));

        verticalLayout_8->addWidget(curtainsBtn_4);


        horizontalLayout_3->addLayout(verticalLayout_8);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        curtainsSlider = new QSlider(layoutWidget_4);
        curtainsSlider->setObjectName(QStringLiteral("curtainsSlider"));
        curtainsSlider->setMaximum(255);
        curtainsSlider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(curtainsSlider);

        curtainsSlider_2 = new QSlider(layoutWidget_4);
        curtainsSlider_2->setObjectName(QStringLiteral("curtainsSlider_2"));
        curtainsSlider_2->setMaximum(255);
        curtainsSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(curtainsSlider_2);

        curtainsSlider_3 = new QSlider(layoutWidget_4);
        curtainsSlider_3->setObjectName(QStringLiteral("curtainsSlider_3"));
        curtainsSlider_3->setMaximum(255);
        curtainsSlider_3->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(curtainsSlider_3);

        curtainsSlider_4 = new QSlider(layoutWidget_4);
        curtainsSlider_4->setObjectName(QStringLiteral("curtainsSlider_4"));
        curtainsSlider_4->setMaximum(255);
        curtainsSlider_4->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(curtainsSlider_4);


        horizontalLayout_3->addLayout(verticalLayout_3);

        stackedWidget->addWidget(Window);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(MainPage);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainPage);
    } // setupUi

    void retranslateUi(QWidget *MainPage)
    {
        MainPage->setWindowTitle(QApplication::translate("MainPage", "MainPage", Q_NULLPTR));
        btnReturn->setText(QString());
        labTitle->setText(QApplication::translate("MainPage", "0", Q_NULLPTR));
        btnMsg->setText(QString());
        btnShow->setText(QString());
        btnHeater->setText(QString());
        btnAirCon->setText(QString());
        btnLED->setText(QString());
        btnWindow->setText(QString());
        btnCancellation->setText(QString());
        heartBtn_2->setText(QApplication::translate("MainPage", "\346\264\227\346\276\241\347\203\255\346\260\264\345\231\250\345\274\200\345\205\263", Q_NULLPTR));
        heartBtn->setText(QApplication::translate("MainPage", "\347\203\247\346\260\264\347\203\255\346\260\264\345\231\250\345\274\200\345\205\263", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainPage", "\350\257\267\350\276\223\345\205\245\347\203\255\346\260\264\345\231\250\346\270\251\345\272\246\357\274\232", Q_NULLPTR));
        heartPushButton_3->setText(QApplication::translate("MainPage", "\347\241\256\350\256\244", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainPage", "\350\257\267\350\276\223\345\205\245\347\203\255\346\260\264\345\231\250\346\270\251\345\272\246\357\274\232", Q_NULLPTR));
        heartPushButton_4->setText(QApplication::translate("MainPage", "\347\241\256\350\256\244", Q_NULLPTR));
        label->setText(QApplication::translate("MainPage", "\347\251\272\350\260\2031", Q_NULLPTR));
        airBtn->setText(QApplication::translate("MainPage", "\347\251\272\350\260\203\345\274\200\345\205\263", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainPage", "\347\241\256\345\256\232", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainPage", "\346\250\241\345\274\217\351\200\211\346\213\251", Q_NULLPTR));
        cbAirModel->clear();
        cbAirModel->insertItems(0, QStringList()
         << QApplication::translate("MainPage", "\345\210\266\347\203\255", Q_NULLPTR)
         << QApplication::translate("MainPage", "\345\210\266\345\206\267", Q_NULLPTR)
         << QApplication::translate("MainPage", "\351\231\244\346\271\277", Q_NULLPTR)
         << QApplication::translate("MainPage", "\345\220\271\351\243\216", Q_NULLPTR)
        );
        cbAirFun->clear();
        cbAirFun->insertItems(0, QStringList()
         << QApplication::translate("MainPage", "\350\207\252\345\212\250", Q_NULLPTR)
         << QApplication::translate("MainPage", "\344\270\200", Q_NULLPTR)
         << QApplication::translate("MainPage", "\344\272\214", Q_NULLPTR)
         << QApplication::translate("MainPage", "\344\270\211", Q_NULLPTR)
         << QApplication::translate("MainPage", "\345\233\233", Q_NULLPTR)
         << QApplication::translate("MainPage", "\344\272\224", Q_NULLPTR)
        );
        groupBox_2->setTitle(QApplication::translate("MainPage", "\346\270\251\345\272\246\350\260\203\350\212\202", Q_NULLPTR));
        btnAirSub->setText(QApplication::translate("MainPage", "-", Q_NULLPTR));
        btnAirAdd->setText(QApplication::translate("MainPage", "+", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainPage", "\345\272\246\346\225\260\346\230\276\347\244\272", Q_NULLPTR));
        ledBtn->setText(QApplication::translate("MainPage", "LED1\345\274\200\345\205\263", Q_NULLPTR));
        ledBtn_2->setText(QApplication::translate("MainPage", "LED2\345\274\200\345\205\263", Q_NULLPTR));
        ledBtn_3->setText(QApplication::translate("MainPage", "LED3\345\274\200\345\205\263", Q_NULLPTR));
        ledBtn_4->setText(QApplication::translate("MainPage", "LED4\345\274\200\345\205\263", Q_NULLPTR));
        curtainsBtn->setText(QApplication::translate("MainPage", "\347\252\227\345\270\2301\345\274\200\345\205\263", Q_NULLPTR));
        curtainsBtn_2->setText(QApplication::translate("MainPage", "\347\252\227\345\270\2302\345\274\200\345\205\263", Q_NULLPTR));
        curtainsBtn_3->setText(QApplication::translate("MainPage", "\347\252\227\345\270\2303\345\274\200\345\205\263", Q_NULLPTR));
        curtainsBtn_4->setText(QApplication::translate("MainPage", "\347\252\227\345\270\2304\345\274\200\345\205\263", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
