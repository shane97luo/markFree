/*
 * sidebar project management tree view
 *  author      shaneluo
 *  time        11.27.2019
 *  version     v-0.1
 *  email       shaneluo97@foxmail.com
 *
 */

#ifndef PROJECTTREEWIDGET_H
#define PROJECTTREEWIDGET_H

#include <QTreeWidget>
#include <QFileSystemModel>
#include <QFileIconProvider>
#include <QStackedWidget>
#include <QTreeWidget>
#include <QWidget>
#include <QComboBox>

class ProjectTreeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ProjectTreeWidget(QWidget *parent = nullptr);

    void initViewComBox();

private:
    QStackedWidget *stackWidget;
    QTreeWidget * proTreeWidget;
    QComboBox * viewComBox;//视图选择

signals:

public slots:
};

#endif // PROJECTTREEWIDGET_H
