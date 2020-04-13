#ifndef MYPAINTWIDGET_H
#define MYPAINTWIDGET_H

#include <QWidget>

class MyPaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyPaintWidget(QWidget *parent = nullptr);
    ~MyPaintWidget();

signals:

};

#endif // MYPAINTWIDGET_H
