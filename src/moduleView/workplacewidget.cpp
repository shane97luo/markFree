#include "workplacewidget.h"

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
void WorkplaceWidget::dragMoveEvent(QDragMoveEvent *event)
{
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
void WorkplaceWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")) {
        QByteArray itemData = event->mimeData()->data("application/x-qabstractitemmodeldatalist");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        QLabel *newIcon = new QLabel(this);
        newIcon->setPixmap(pixmap);
        newIcon->move(event->pos() - offset);
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

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
void WorkplaceWidget::mousePressEvent(QMouseEvent *event)
{
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if (!child)
        return;

    QPixmap pixmap = *child->pixmap();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->pos() - child->pos());
    //! [1]

    //! [2]
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);
    //! [2]

    //! [3]
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());
    //! [3]

    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();

    child->setPixmap(tempPixmap);

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        child->show();
        child->setPixmap(pixmap);
    }

}


