#ifndef WORKPLACEWIDGET_H
#define WORKPLACEWIDGET_H

#include <QMouseEvent>
#include <QDragMoveEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QMimeData>
#include <QDrag>


#include <QTreeWidget>
#include <QTreeWidgetItem>

#include <QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QDebug>

#include <QPainter>
#include <QPen>
#include <QBrush>

class WorkplaceWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WorkplaceWidget(QWidget *parent = nullptr);


    void paintEvent(QPaintEvent *event) override;

    void paintItem(QPainter *painter,int offset);

private:
    QTextEdit *textEdit;

    QPainter *myPainter;

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
//    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
//    void mousePressEvent(QMouseEvent *event) override;

signals:

public slots:
};

#endif // WORKPLACEWIDGET_H
