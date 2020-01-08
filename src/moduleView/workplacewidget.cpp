#include "workplacewidget.h"

#include <QHBoxLayout>
#include <QPushButton>

WorkplaceWidget::WorkplaceWidget(QWidget *parent) : QWidget(parent)
{

    this->setWindowTitle("workplace");
    //垂直布局
    QVBoxLayout *vbLayout = new QVBoxLayout;
    //水平布局
    QHBoxLayout *hbLayout = new QHBoxLayout;
    QTextEdit *txtEdit = new QTextEdit("Hello Qtq");
    QPushButton * btn = new QPushButton("click me\n 1");
    QPushButton * btn1 = new QPushButton("click me\n 2");
    QPushButton * btn2 = new QPushButton("click me\n 3");
    //添加窗体
    hbLayout->addWidget(btn1);
    hbLayout->addWidget(btn2);
    vbLayout->addWidget(txtEdit);
    vbLayout->addWidget(btn);
    //添加布局
    vbLayout->addLayout(hbLayout);
    //设置布局
    this->setLayout(vbLayout);
}
