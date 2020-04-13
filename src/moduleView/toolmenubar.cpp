#include "toolmenubar.h"
#include <QStyle>
ToolMenuBar::ToolMenuBar(QWidget *parent) : QWidget(parent)
{
    initMenu();
}

void ToolMenuBar::initMenu()
{
    welcome = new QPushButton("Hello world");
    editMenu = new QPushButton("Write");
    paintMenu = new QPushButton("Paint");
    helpMenu = new QPushButton("mindMap");

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(welcome);
    vLayout->addWidget(editMenu);
    vLayout->addWidget(paintMenu);
    vLayout->addWidget(helpMenu);

    vLayout->setStretch(0,1);
    vLayout->setStretch(1,1);
    vLayout->setStretch(2,1);
    vLayout->setStretch(3,1);

    setLayout(vLayout);

}
