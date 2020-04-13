#ifndef MYPAINTWIDGET_H
#define MYPAINTWIDGET_H

#include <QWidget>

#include <QPainter>
#include <QPicture>
#include <QPen>

class MyPaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyPaintWidget(QWidget *parent = nullptr);
    ~MyPaintWidget();

protected:
    void paintEvent(QPaintEvent *event);

private:

signals:

};

#endif // MYPAINTWIDGET_H
