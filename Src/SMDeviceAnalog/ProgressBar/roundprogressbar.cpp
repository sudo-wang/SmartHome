#include "roundprogressbar.h"
#include <QWidget>
RoundProgressBar::RoundProgressBar(QWidget *parent) :
   QWidget(parent, Qt::FramelessWindowHint)
{
    resize(167, 167);
    setAutoFillBackground(false);
    setAttribute(Qt::WA_TranslucentBackground, true);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0xff,0xff,0xff,0xff));
    setPalette(pal);
    bPressFlag = false;
    currentValue = 0;
    userdVaule = 0;

//    startValueLabel = new QLabel(tr("0%"), this);
//    startValueLabel->setFont(QFont("Arial", 11, QFont::Normal));
//    startValueLabel->setStyleSheet("color:#898989");

//    endValueLabel = new QLabel(tr("100%"),this);
//    endValueLabel->setFont(QFont("Arial", 11, QFont::Normal));
//    endValueLabel->setStyleSheet("color:#898989");

    dispayValueLabel = new QLabel(this);
    dispayValueLabel->setStyleSheet("color:#349BDA");

    updateTimer = new QTimer(this);
    updateTimer->setInterval(20);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(slotUpdateTimer()));
}

RoundProgressBar::~RoundProgressBar()
{
    if (updateTimer->isActive()) {
        updateTimer->stop();
    }
    currentValue = 0;
}

void RoundProgressBar::setValue(int value)
{
    userdVaule = value;
    if (!updateTimer->isActive()) {
        updateTimer->start();
    }
}

void RoundProgressBar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.fillRect(this->rect(), QColor(0, 0, 0, 0));
    QColor usedColor(165, 220, 62);
    QColor freeColor(215, 215, 215);
    painter.drawPixmap(QRect((width() - backGround.width())/2 , (height() - backGround.height())/2, backGround.width(), backGround.height()) , backGround);

    painter.translate(width() / 2, height() / 2);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.save();
    painter.rotate(42);
    painter.setPen(QPen(usedColor, 2));
    for (int i = 0; i < currentValue ; ++i) {
        painter.drawLine(0, 70, 0, 80);
        painter.rotate(2.8);
    }
    painter.setPen(QPen(freeColor, 3));
    for (int i = currentValue; i < 100 ; ++i) {
        painter.drawLine(0, 70, 0, 80);
        painter.rotate(2.8);
    }
    if (currentValue == 0) {
        dispayValueLabel->setFont(QFont("Arial", 12, QFont::Bold));
        dispayValueLabel->setText(tr("0℃"));
    }
    else {
        dispayValueLabel->setFont(QFont("Arial", 15, QFont::Bold));
        dispayValueLabel->setText(tr("%1℃").arg(currentValue));
    }
    QFontMetrics metrics(dispayValueLabel->font());
    int textwidth = metrics.width(dispayValueLabel->text());
    int textheight = metrics.height();
    dispayValueLabel->setGeometry((width() - textwidth)/2, (height() - textheight)/2 , textwidth, textheight);
    painter.restore();

    painter.translate(-width()/2, -height()/2);
    painter.setBrush(QColor(233, 233, 233));
    painter.setPen(QPen(QColor(233, 233, 233), 15));
    painter.drawEllipse(QRectF((width()/2 - 55), (height()/2 - 55), 110, 110));

    int angle = 230 - (double)currentValue * 2.8;
    QConicalGradient conicalGradient(width()/2, height()/2, angle);
    conicalGradient.setColorAt(0, QColor(45, 204, 112));
    conicalGradient.setColorAt(1.0, QColor(51, 152, 219));
    painter.setPen(QPen(QBrush(conicalGradient), 30));
    painter.drawEllipse(QRectF((width()/2 - 35), (height()/2 - 35), 70, 70));

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(249, 249, 249));
    painter.drawEllipse(QRectF((width()/2 - 30), (height()/2 - 30), 60, 60));
}

void RoundProgressBar::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
    updateTimer->start();
    currentValue = 0;
}

void RoundProgressBar::hideEvent(QHideEvent *event)
{
    Q_UNUSED(event);
    if (updateTimer->isActive()) {
        updateTimer->stop();
    }
    currentValue = 0;
}

void RoundProgressBar::slotUpdateTimer()
{
    if (currentValue == userdVaule) {
        updateTimer->stop();
        return;
    }

    if(currentValue < userdVaule)
        currentValue++;
    else if(currentValue > userdVaule)
        currentValue--;
    update();
}
