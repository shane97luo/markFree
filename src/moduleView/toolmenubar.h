#ifndef TOOLMENUBAR_H
#define TOOLMENUBAR_H

#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QVBoxLayout>

class ToolMenuBar : public QWidget
{
    Q_OBJECT
public:
    explicit ToolMenuBar(QWidget *parent = nullptr);

    void initMenu();
private:

    QPushButton *welcome;
    QPushButton *editMenu;
    QPushButton *paintMenu;
    QPushButton *helpMenu;


signals:

public slots:
};

#endif // TOOLMENUBAR_H
