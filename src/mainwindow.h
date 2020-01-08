#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QLineEdit>

#include "mdiwidget.h"
#include "./moduleView/projecttreewidget.h"
#include "./moduleView/workplacewidget.h"
#include "./moduleView/toolmenubar.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initToolBar();
    void initStatusBar();

private:
    WorkplaceWidget * workplace;//工作区间
    ProjectTreeWidget * projectWidget;//项目管理栏
    ToolMenuBar *sideMenuBar; //左侧管理菜单
    QStatusBar *mystatusBar;

    QMenuBar *menubar;
    QMenu *filesMenu;
    QMenu *editsMenu;
    QMenu *insertsMenu;
    QMenu *stylesMenu;
    QMenu *viewsMenu;
    QMenu *helpsMenu;

    QToolBar* tb2;


public slots:
    void slotNewFile();
    void slotOpenFile();
    void slotOpenDir();
    void slotOpenRecent();
    void slotSaveFile();
    void slotSaveAs();
    void slotSaveAll();
    void slotClose();
    void slotCloseAll();
    void slotExit();
    void slotUpdate();


};
#endif // MAINWINDOW_H
