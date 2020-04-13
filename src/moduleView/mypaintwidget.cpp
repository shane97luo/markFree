#include "mypaintwidget.h"

MyPaintWidget::MyPaintWidget(QWidget *parent) : QWidget(parent)
{

}
MyPaintWidget::~MyPaintWidget()
{

}

void MyPaintWidget::paintEvent(QPaintEvent *event)
{
    QPainter myPainter(this);

    QPen myPen("red");
    QBrush myBrush("blue");

    myPainter.setPen(myPen);
    myPainter.setBrush(myBrush);

    myPainter.drawLine(QPoint(0,0),QPoint(this->width(),this->height()));

    myPainter.drawRect(20,20,50,50);
    myPainter.drawPie(100,100,130,130,30*16,120*16);
    myPainter.drawArc(80,80,100,100,30*16,120*16);

}
