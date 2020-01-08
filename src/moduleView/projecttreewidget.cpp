#include "projecttreewidget.h"
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

    QStringList pro1List;
    proTreeWidget = new QTreeWidget;
    QTreeWidgetItem *pro1 = new QTreeWidgetItem();
    pro1->setText(0,"pei");

    QTreeWidgetItem *pro2 = new QTreeWidgetItem;
    pro2->setText(0,"door");

    QTreeWidgetItem *pro3 = new QTreeWidgetItem;
    pro3->setText(0,"mouse");

    QTreeWidgetItem *pro3_1 = new QTreeWidgetItem;
    pro3_1->setText(0,"mouse_1");

    QTreeWidgetItem *pro3_2 = new QTreeWidgetItem;
    pro3_2->setText(0,"mouse_2");


    pro3->insertChild(0,pro3_1);
    pro3->insertChild(0,pro3_2);


//    proTreeWidget->addTopLevelItem(pro1);
//    proTreeWidget->addTopLevelItem(pro2);
//    proTreeWidget->addTopLevelItem(pro3);

    proTreeWidget->insertTopLevelItem(0,pro1);
    proTreeWidget->insertTopLevelItem(0,pro2);
    proTreeWidget->insertTopLevelItem(0,pro3);


    stackWidget->addWidget(proTreeWidget);
    initViewComBox();
    //垂直布局
    QVBoxLayout *vmainLayout = new QVBoxLayout;
    vmainLayout->addWidget(viewComBox);
    vmainLayout->addWidget(stackWidget);

    //设置布局
    this->setLayout(vmainLayout);



}

void ProjectTreeWidget::initViewComBox()
{

}

