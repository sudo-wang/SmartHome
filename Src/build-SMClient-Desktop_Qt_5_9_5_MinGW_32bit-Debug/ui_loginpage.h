/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QWidget *widget_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *slogen;
    QSpacerItem *horizontalSpacer_7;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *loginBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exitBtn;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *username;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *passwd;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName(QStringLiteral("LoginPage"));
        LoginPage->resize(583, 447);
        widget_3 = new QWidget(LoginPage);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(9, 9, 565, 40));
        widget_3->setMaximumSize(QSize(16777215, 40));
        widget = new QWidget(widget_3);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 0, 591, 31));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        slogen = new QLabel(widget);
        slogen->setObjectName(QStringLiteral("slogen"));
        QFont font;
        font.setFamily(QStringLiteral("Aharoni"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        slogen->setFont(font);
        slogen->setStyleSheet(QStringLiteral("font: 75 9pt \"Aharoni\";"));

        horizontalLayout_5->addWidget(slogen);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        layoutWidget = new QWidget(LoginPage);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 350, 401, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        loginBtn = new QPushButton(layoutWidget);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setMinimumSize(QSize(50, 30));
        loginBtn->setStyleSheet(QLatin1String("QPushButton:hover {\n"
"background-color: green;\n"
"}\n"
"\n"
"QPushButton{\n"
"background-color: gray;\n"
"border-radius: 5px;\n"
"}"));

        horizontalLayout->addWidget(loginBtn);

        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        exitBtn = new QPushButton(layoutWidget);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setMinimumSize(QSize(50, 30));
        exitBtn->setStyleSheet(QLatin1String("QPushButton:hover {\n"
"background-color: green;\n"
"}\n"
"\n"
"QPushButton{\n"
"background-color: gray;\n"
"border-radius: 5px;\n"
"}"));

        horizontalLayout->addWidget(exitBtn);

        horizontalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        widget1 = new QWidget(LoginPage);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(40, 230, 461, 101));
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_6 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setPointSize(15);
        label_3->setFont(font1);

        horizontalLayout_2->addWidget(label_3);

        username = new QLineEdit(widget1);
        username->setObjectName(QStringLiteral("username"));
        username->setMinimumSize(QSize(0, 30));
        username->setMaximumSize(QSize(313, 16777215));
        username->setFont(font1);
        username->setStyleSheet(QStringLiteral("background-color: transparent"));

        horizontalLayout_2->addWidget(username);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(widget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout_3->addWidget(label_6);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        passwd = new QLineEdit(widget1);
        passwd->setObjectName(QStringLiteral("passwd"));
        passwd->setMinimumSize(QSize(0, 30));
        passwd->setFont(font1);
        passwd->setStyleSheet(QStringLiteral("background-color: transparent"));

        horizontalLayout_3->addWidget(passwd);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        retranslateUi(LoginPage);

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QWidget *LoginPage)
    {
        LoginPage->setWindowTitle(QApplication::translate("LoginPage", "Form", Q_NULLPTR));
        slogen->setText(QApplication::translate("LoginPage", "\346\254\242\350\277\216\344\275\277\347\224\250\346\231\272\350\203\275\345\256\266\345\261\205\347\263\273\347\273\237", Q_NULLPTR));
        loginBtn->setText(QApplication::translate("LoginPage", "\347\231\273\345\275\225", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("LoginPage", "\351\200\200\345\207\272", Q_NULLPTR));
        label_3->setText(QApplication::translate("LoginPage", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        username->setText(QApplication::translate("LoginPage", "admin", Q_NULLPTR));
        label_6->setText(QApplication::translate("LoginPage", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        passwd->setText(QApplication::translate("LoginPage", "123456", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
