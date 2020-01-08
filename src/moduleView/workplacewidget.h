#ifndef WORKPLACEWIDGET_H
#define WORKPLACEWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QLabel>

class WorkplaceWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WorkplaceWidget(QWidget *parent = nullptr);

private:
    QTextEdit *textEdit;

signals:

public slots:
};

#endif // WORKPLACEWIDGET_H
