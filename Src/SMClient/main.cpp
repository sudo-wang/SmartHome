#include "loginpage.h"
#include <QApplication>
#include "config.h"
#include "appinit.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont(QFont("Microsoft Yahei", 10));
    AppInit::Instance()->start();

    LoginPage LP;
    LP.show();

    return a.exec();
}
