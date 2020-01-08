#include "toolmenubar.h"

ToolMenuBar::ToolMenuBar(QWidget *parent) : QWidget(parent)
{

    initMenu();
}

void ToolMenuBar::initMenu()
{
    editMenu = new QPushButton("Write");
    paintMenu = new QPushButton("Paint");
    helpMenu = new QPushButton("mindMap");

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(editMenu);
    vLayout->addWidget(paintMenu);
    vLayout->addWidget(helpMenu);

    setLayout(vLayout);

}
