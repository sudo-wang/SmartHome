#ifndef ROUNDPROGRESSBAR_H
#define ROUNDPROGRESSBAR_H

#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QLabel>

class RoundProgressBar : public QWidget
{
    Q_OBJECT

public:
    explicit RoundProgressBar(QWidget *parent = 0);
    ~RoundProgressBar();

    void setValue(int value);


protected:
    void paintEvent(QPaintEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);


private slots:
    void slotUpdateTimer();

private:

    QPoint beginDrag;
    bool bPressFlag;

    QPixmap backGround;
    int userdVaule;
    int currentValue;
//    QLabel *startValueLabel;
//    QLabel *endValueLabel;
    QLabel *dispayValueLabel;

    QTimer *updateTimer;

};

#endif // ROUNDPROGRESSBAR_H
