#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>

class QToolButton;

namespace Ui {
class MainPage;
}

class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = 0);
    ~MainPage();
    int air_1 = 1;
    QList<QToolButton *> btns;
    int heartState = 0;          // 热水器1的状态
    int heartState_2 = 0;        // 热水器2的状态
    int ledState = 0;            // led1的状态
    int ledState_2 = 0;          // led2的状态
    int ledState_3 = 0;          // led3的状态
    int ledState_4 = 0;          // led4的状态
    int curtainsState = 0;       // 窗帘1的状态
    int curtainsState_2 = 0;     // 窗帘2的状态
    int curtainsState_3 = 0;     // 窗帘3的状态
    int curtainsState_4 = 0;     // 窗帘4的状态
    int airState = 0;

private slots:
    void initForm();
    void initNav();
    void buttonClicked();
    void on_btnReturn_pressed();
    void on_btnMsg_pressed();

    void on_heartBtn_stateChanged(int arg1);

    void on_heartPushButton_3_clicked();

    void on_heartPushButton_4_clicked();

    void on_heartBtn_2_stateChanged(int arg1);

    void on_ledBtn_stateChanged(int arg1);

    void on_ledBtn_2_stateChanged(int arg1);

    void on_ledBtn_3_stateChanged(int arg1);

    void on_ledBtn_4_stateChanged(int arg1);

    void on_ledSlider_valueChanged(int value);

    void on_ledSlider_2_valueChanged(int value);

    void on_ledSlider_3_valueChanged(int value);

    void on_ledSlider_4_valueChanged(int value);

    void on_curtainsBtn_stateChanged(int arg1);

    void on_curtainsBtn_2_stateChanged(int arg1);

    void on_curtainsBtn_3_stateChanged(int arg1);

    void on_curtainsBtn_4_stateChanged(int arg1);

    void on_curtainsSlider_valueChanged(int value);

    void on_curtainsSlider_2_valueChanged(int value);

    void on_curtainsSlider_3_valueChanged(int value);

    void on_curtainsSlider_4_valueChanged(int value);

    void on_btnAirAdd_clicked();

    void on_btnAirSub_clicked();

    void on_pushButton_clicked();

    void on_airBtn_stateChanged(int arg1);

signals:
    void LogOffSignal();

private:
    Ui::MainPage *ui;
    int heart;
    int te;               // 记录空调的温度,赋予初值为25
};

#endif // MAINPAGE_H
