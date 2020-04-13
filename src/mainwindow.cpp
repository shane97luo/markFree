#include "mainwindow.h"

#include <QMenuBar>
#include <QDebug>
#include <QFileDialog>
#include <QSizePolicy>
#include "./moduleNet/myupdate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    this->resize(800,600);
    this->setMinimumSize(200,150);

    initToolBar();

    QWidget *mainWidget = new QWidget;//总管理窗口
    projectWidget = new ProjectTreeWidget();//项目管理栏
    workplace = new WorkplaceWidget() ;//工作区间
    sideMenuBar = new ToolMenuBar();//左侧菜单

    workplace->setStyleSheet("background-color:lightYellow;");
    sideMenuBar->setStyleSheet("background-color:lightYellow;");

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(sideMenuBar);
    hLayout->addWidget(projectWidget);
    hLayout->addWidget(workplace);
    mainWidget->setLayout(hLayout);

    setCentralWidget(mainWidget);
    sideMenuBar->setFixedWidth(90);
    projectWidget->setFixedWidth(180);
    workplace->setMinimumWidth(600);

    initStatusBar();

    //setWindowOpacity(0.9);//调节透明度

}

MainWindow::~MainWindow()
{

}

void MainWindow::initStatusBar()
{
    mystatusBar = statusBar();//左侧菜单
    mystatusBar->setStyleSheet("background-color:lightYellow;");

    QLabel *lbl= new QLabel("status:");
    QLabel *lbl1= new QLabel("lbl1");
    QLabel *lbl2= new QLabel("lbl2");

    QLineEdit *lEerror = new QLineEdit();
    lEerror->setText("lE:");

    statusBar()->layout()->addWidget(lbl);
    statusBar()->layout()->addWidget(lbl1);
    statusBar()->layout()->addWidget(lbl2);
    statusBar()->layout()->addWidget(lEerror);

}

void MainWindow::initToolBar()
{
    //    QToolBar* tb = addToolBar("Tool Bar");//add
    //    tb->setMovable(false);

    menubar = menuBar();

    //file menu
    //SP_TitleBarMenuButton
    filesMenu = new QMenu("File(&F)");

    QIcon fileIcon = style()->standardIcon(QStyle::SP_FileIcon);
    QAction * newAct = new QAction(fileIcon,"新建", nullptr);
    connect(newAct,SIGNAL(triggered()),this,SLOT(slotNewFile()));

    QIcon dirOpenIcon = style()->standardIcon(QStyle::SP_DirOpenIcon);
    QAction * openAct = new QAction(dirOpenIcon ,"打开", nullptr);
    connect(openAct,SIGNAL(triggered()),this,SLOT(slotOpenFile()));

    QIcon dirOpenIcon1 = style()->standardIcon(QStyle::SP_DirOpenIcon);
    QAction * openDirAct = new QAction(dirOpenIcon1 ,QString::fromLocal8Bit("open from file"), nullptr);
    connect(openDirAct,SIGNAL(triggered()),this,SLOT(slotOpenDir()));

    QIcon dirOpenIcon2 = style()->standardIcon(QStyle::SP_DirOpenIcon);
    QAction * openRecentAct = new QAction(dirOpenIcon2 ,"recently file", nullptr);
    connect(openRecentAct,SIGNAL(triggered()),this,SLOT(slotOpenRecent()));

    QIcon dirLinkIcon = style()->standardIcon(QStyle::SP_DirLinkIcon);
    QAction * saveAct = new QAction(dirLinkIcon,"保存", nullptr);
    connect(saveAct,SIGNAL(triggered()),this,SLOT(slotSaveFile()));

    QAction * saveAsAct = new QAction("Save as", nullptr);
    connect(saveAsAct,SIGNAL(triggered()),this,SLOT(slotSaveAs()));

    QAction * saveAllAct = new QAction("全部保存", nullptr);
    connect(saveAllAct,SIGNAL(triggered()),this,SLOT(slotSaveAll()));

    QIcon dirCloseIcon = style()->standardIcon(QStyle::SP_DirClosedIcon);
    QAction * closeAct = new QAction(dirCloseIcon,"关闭", nullptr);
    connect(closeAct,SIGNAL(triggered()),this,SLOT(slotClose()));

    QAction * closeAllAct = new QAction("关闭全部", nullptr);
    connect(closeAllAct,SIGNAL(triggered()),this,SLOT(slotCloseAll()));

    QAction * exitAct = new QAction("推出", nullptr);
    connect(exitAct,SIGNAL(triggered()),this,SLOT(slotExit()));

    filesMenu->addAction(newAct);
    filesMenu->addSeparator();
    filesMenu->addAction(openAct);
    filesMenu->addAction(openDirAct);
    filesMenu->addAction(openRecentAct);
    filesMenu->addSeparator();
    filesMenu->addAction(saveAct);
    filesMenu->addAction(saveAsAct);
    filesMenu->addAction(saveAllAct);
    filesMenu->addSeparator();
    filesMenu->addAction(closeAct);
    filesMenu->addAction(closeAllAct);
    filesMenu->addAction(exitAct);
    menubar->addMenu(filesMenu);

    //edit menu
    editsMenu = new QMenu("Edit(&E)");
    QAction* copyAct = new QAction("复制(&C)",nullptr);

    QAction* cutAct = new QAction("剪切(&X)",nullptr);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"));
//    connect(cutAct, &QAction::triggered, &WorkplaceWidget::textEdit, &QPlainTextEdit::cut);

    QAction* pasteAct = new QAction("粘贴(&P)",nullptr);
    QAction* searchAct = new QAction("查找(&F)",nullptr);

    //
//    QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));
//    QToolBar *editToolBar = addToolBar(tr("Edit"));

    editsMenu->addAction(copyAct);
    editsMenu->addAction(cutAct);
    editsMenu->addAction(pasteAct);
    editsMenu->addAction(searchAct);
    menubar->addMenu(editsMenu);

    //edit menu
    insertsMenu = new QMenu("Insert(&I)");
    QAction* insertImgAct = new QAction("插入图片",nullptr);
    QAction* insertMindmapAct = new QAction("插入脑图",nullptr);

    insertsMenu->addAction(insertImgAct);
    insertsMenu->addAction(insertMindmapAct);
    menubar->addMenu(insertsMenu);


    //style menu
    stylesMenu = new QMenu("Style(&S)");
    QAction* fontAct = new QAction("字体",nullptr);
    stylesMenu->addAction(fontAct);

    helpsMenu = new QMenu("Help(&H)");
    //QMenu* helpMenu = new QMenu("帮助",nullptr);
    QAction* helpAct = new QAction("帮助",nullptr);
    QAction* contactAct = new QAction("contact me",nullptr);
    QAction* updateAct = new QAction("check update",nullptr);
    connect(updateAct,SIGNAL(triggered()),this,SLOT(slotUpdate()));

    QAction* documentAct = new QAction("文档",nullptr);

    helpsMenu->addAction(helpAct);
    helpsMenu->addAction(documentAct);
    helpsMenu->addAction(contactAct);
    helpsMenu->addAction(updateAct);

    menubar->addMenu(helpsMenu);

}

void MainWindow::slotNewFile()
{
    qDebug()<<"new file";
}

void MainWindow::slotOpenFile()
{
    qDebug()<<"open file";
    QString file = QFileDialog::getOpenFileName(this,
                                                "选择打开文件",
                                                QDir::currentPath(),
                                                nullptr,
                                                nullptr,
                                                nullptr);
    if(!file.isEmpty())
    {
        qDebug()<<"file:"<<file;
    }
}

void MainWindow::slotOpenDir()
{
    qDebug()<<"open dir";
    QString dir = QFileDialog::getExistingDirectory(this,
                                                    "选择查找路径",
                                                    QDir::currentPath(),
                                                    QFileDialog::ShowDirsOnly);
    if(!dir.isEmpty())
    {
        qDebug()<<"dir:"<<dir;
    }
}

void MainWindow::slotOpenRecent()
{
    qDebug()<<"open file";
    QString dir = QFileDialog::getExistingDirectory(this,
                                                    "选择查找路径",
                                                    QDir::currentPath(),
                                                    QFileDialog::ShowDirsOnly);
    if(!dir.isEmpty())
    {
        qDebug()<<"dir:"<<dir;
    }
}

void MainWindow::slotSaveFile()
{
    qDebug()<<"save file";
}

void MainWindow::slotSaveAs()
{
    qDebug()<<"saveAs file";
}

void MainWindow::slotSaveAll()
{
    qDebug()<<"saveAll file";
}

void MainWindow::slotClose()
{
    qDebug()<<"close file";
}

void MainWindow::slotCloseAll()
{
    qDebug()<<"closeAll file";
}

void MainWindow::slotExit()
{
    this->close();
}


void MainWindow::slotUpdate()
{
    qDebug()<<"check:";
    MyUpdate *updateWidget = new MyUpdate();
    updateWidget->show();

}
