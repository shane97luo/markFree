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

#include <QMouseEvent>
#include <QDragMoveEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QMimeData>
#include <QDrag>


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

    qint8 indexView;//当前视图

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
//    void dragMoveEvent(QDragMoveEvent *event) override;
//    void dropEvent(QDropEvent *event) override;
//    void mousePressEvent(QMouseEvent *event) override;



signals:

public slots:

    void changeView(qint8 view);
    void slotItemPressed(QTreeWidgetItem *item, int column);
};

#endif // PROJECTTREEWIDGET_H
