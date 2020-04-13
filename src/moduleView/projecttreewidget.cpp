#include "projecttreewidget.h"

#include <QDebug>

#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QCommandLineParser>

ProjectTreeWidget::ProjectTreeWidget(QWidget *parent) : QWidget(parent)
{
    stackWidget = new QStackedWidget;

    viewComBox = new QComboBox;//
    QStringList viewList;
    viewList<<"Projects"<<"open files"<<"visual";
    viewComBox->addItems(viewList);

    //    connect(viewComBox,SIGNAL(currentIndexChanged(&indexView)),this,SLOT(changeView(index)));

    proTreeWidget = new QTreeWidget;
    connect(proTreeWidget,SIGNAL(itemPressed(QTreeWidgetItem *, int)),
            this,SLOT(slotItemPressed(QTreeWidgetItem *, int)));

    proTreeWidget->setColumnCount(1);
    proTreeWidget->setHeaderLabel(QString("驱动管理"));

    QString treeWidgetstyle = "QTreeWidget::item:hover{color: rgb(0,0,0);\
                              background-color: rgb(186,186,186); \
                              border: 2px gray;\
                                border-style: inset;}";
    proTreeWidget->setStyleSheet(treeWidgetstyle);

    QTreeWidgetItem *mouse = new QTreeWidgetItem(proTreeWidget,QStringList(QString("mouse")));
    QTreeWidgetItem *keyboard = new QTreeWidgetItem(proTreeWidget,QStringList(QString("keyBoard")));
    QTreeWidgetItem *screen = new QTreeWidgetItem(proTreeWidget,QStringList(QString("screen")));

    QTreeWidgetItem *mouse_1 = new QTreeWidgetItem(mouse,QStringList(QString("mouse_1")));
    QTreeWidgetItem *mouse_2 = new QTreeWidgetItem(mouse,QStringList(QString("mouse_2")));

    QTreeWidgetItem *keyboard_1 = new QTreeWidgetItem(keyboard,QStringList(QString("keyboard_1")));
    QTreeWidgetItem *keyboard_2 = new QTreeWidgetItem(keyboard,QStringList(QString("keyboard_2")));

    QTreeWidgetItem *screen_1 = new QTreeWidgetItem(screen,QStringList(QString("screen_1")));
    QTreeWidgetItem *screen_2 = new QTreeWidgetItem(screen,QStringList(QString("screen_2")));


    stackWidget->addWidget(proTreeWidget);
    initViewComBox();
    //垂直布局
    QVBoxLayout *vmainLayout = new QVBoxLayout;
    vmainLayout->addWidget(viewComBox);
    vmainLayout->addWidget(stackWidget);

    //设置布局
    this->setLayout(vmainLayout);

    proTreeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    //启用拖放
    proTreeWidget->setDragEnabled(true);
    //设置拖放
    setAcceptDrops(true);
    //    this->viewport()->setAcceptDrops(true);
    //设置显示将要被放置的位置
    //    proTreeWidget->setDropIndicatorShown(true);
    //    //设置拖放模式为移动项目，否则为复制项目
    //    proTreeWidget->setDragDropMode(QAbstractItemView::InternalMove);
    //    proTreeWidget->setAttribute(Qt::WA_PaintOutsidePaintEvent);

}

void ProjectTreeWidget::initViewComBox()
{

}

void ProjectTreeWidget::changeView(qint8 view)
{
    //change view
    qDebug()<<"view"<<view;

}


void ProjectTreeWidget::slotItemPressed(QTreeWidgetItem *item, int column)
{
    qDebug()<<column;
//    QTreeWidgetItem *item =proTreeWidget->currentItem();
//    if (item == NULL)
//        return;
    QTreeWidgetItem *parentItem = item->parent();
    if(parentItem==NULL)
        return;

    int row1 = proTreeWidget->indexOfTopLevelItem(parentItem);  //第一层index
    int row2 = item->parent()->indexOfChild(item);              //第二层index
    qDebug()<<"double"<<item->text(0)<<row1<<row2;

}

void ProjectTreeWidget::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<<"project enter event";
    QTreeWidgetItem *item =proTreeWidget->currentItem();
    if (item == NULL)
        return;
    QTreeWidgetItem *parentItem = item->parent();
    if(parentItem==NULL)
        return;

    int row1 = proTreeWidget->indexOfTopLevelItem(parentItem);  //第一层index
    int row2 = item->parent()->indexOfChild(item);              //第二层index
    qDebug()<<item->text(0)<<row1<<row2;



}
//void ProjectTreeWidget::dragMoveEvent(QDragMoveEvent *event)
//{
//    qDebug()<<"project move event";

//}
//void ProjectTreeWidget::dropEvent(QDropEvent *event)
//{
//    qDebug()<<"project drop event";
//}
//void ProjectTreeWidget::mousePressEvent(QMouseEvent *event)
//{
//    qDebug()<<"project mouse press";
//}
