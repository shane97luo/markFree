#include "workplacewidget_drag.h"

#include <QStackedWidget>
#include <QHBoxLayout>
#include <QPushButton>

WorkplaceWidget::WorkplaceWidget(QWidget *parent) : QWidget(parent)
{

    this->setWindowTitle("workplace");
    setAcceptDrops(true);

    myPainter = new QPainter(this);

    QString styleSheet;
    styleSheet = "{color: rgb(0,0,0);\
                   background-color: rgb(186,186,186); \
                   border: 2px gray;\
                   border-style: inset;}";
    this->setStyleSheet(styleSheet);

    QLabel *boatIcon = new QLabel(this);
    boatIcon->setPixmap(QPixmap(":/images/boat.png"));
    boatIcon->move(10, 10);
    boatIcon->show();
    boatIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *carIcon = new QLabel(this);
    carIcon->setPixmap(QPixmap(":/images/car.png"));
    carIcon->move(100, 10);
    carIcon->show();
    carIcon->setAttribute(Qt::WA_DeleteOnClose);


    this->show();
    //垂直布局
    //        QVBoxLayout *vbLayout = new QVBoxLayout;
    //        //水平布局
    //        QHBoxLayout *hbLayout = new QHBoxLayout;
    //        QTextEdit *txtEdit = new QTextEdit("Hello Qtq");
    //        QPushButton * btn = new QPushButton("click me\n 1");
    //        QPushButton * btn1 = new QPushButton("click me\n 2");
    //        QPushButton * btn2 = new QPushButton("click me\n 3");
    //        //添加窗体
    //        hbLayout->addWidget(btn1);
    //        hbLayout->addWidget(btn2);
    //        vbLayout->addWidget(txtEdit);
    //        vbLayout->addWidget(btn);
    //        //添加布局
    //        vbLayout->addLayout(hbLayout);
    //        //设置布局
    //        this->setLayout(vbLayout);

}


void WorkplaceWidget::paintEvent(QPaintEvent *event)
{
    QPainter myPainter(this);
    QPixmap pix(this->width(),this->height());
    pix.fill(Qt::red);
    QPainter pp(&pix);

    paintItem(&pp,30);

    paintItem(&myPainter,30);

}

void WorkplaceWidget::paintItem(QPainter *painter,int offset)
{

    QPen myPen("red");
    QBrush myBrush("blue");

    painter->setPen(myPen);
    painter->setBrush(myBrush);

    painter->drawLine(QPoint(offset,offset),QPoint(90+offset,90+offset));

    painter->drawRect(20,20,50,50);
    painter->drawPie(100,100,130,130,30*16,120*16);
    painter->drawArc(80,80,100,100,30*16,120*16);

}

void WorkplaceWidget::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<<"workplace enter event";
    if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }

}

//void WorkplaceWidget::dragMoveEvent(QDragMoveEvent *event)
//{
//    //    qDebug()<<"workplace move event";
//    if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")) {
//        if (event->source() == this) {
//            event->setDropAction(Qt::MoveAction);
//            event->accept();
//        } else {
//            event->acceptProposedAction();
//        }
//    } else {
//        event->ignore();
//    }
//}

void WorkplaceWidget::dropEvent(QDropEvent *event)
{
    qDebug()<<"workplace drope vent";
    qDebug()<<"left pos"<<QCursor::pos()<<event->pos();
    if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")) {
        //        QByteArray itemData = event->mimeData()->data("application/x-qabstractitemmodeldatalist");
        //        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        pixmap.load("./images/house.png");

        QLabel *newIcon = new QLabel(this);
        newIcon->resize(50,60);
        newIcon->setPixmap(pixmap);
        newIcon->move(event->pos());
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        /*
        virtual QMimeData *mimeData(const QList<QTreeWidgetItem *> &items) const;
        virtual QMimeData *mimeData(const QList<QTreeWidgetItem*> items) const;
        virtual bool dropMimeData(QTreeWidgetItem *parent, int index,
                                  const QMimeData *data, Qt::DropAction action);
*/

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

//void WorkplaceWidget::mousePressEvent(QMouseEvent *event)
//{
//    qDebug()<<"workplace mouse press";

//}

