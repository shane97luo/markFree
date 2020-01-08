#ifndef MYUPDATE_H
#define MYUPDATE_H

#include <QWidget>
#include <QTcpSocket>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class MyUpdate : public QWidget
{
    Q_OBJECT
public:
    explicit MyUpdate(QWidget *parent = nullptr);
    void initGui();

private:
    QTcpSocket *tcpClient;

    QLabel *lblIP = new QLabel;
    QLabel *lblPort = new QLabel;

    QLineEdit *lEIP = new QLineEdit;
    QLineEdit *lEPort = new QLineEdit;

    QPushButton *btnConnect = new QPushButton("Connect",this);
    QPushButton *btnSend = new QPushButton("Send",this);


signals:

public slots:

    void ReadData();
//    void ReadError(QAbstractSocket::SocketError);
//    void slotConnect();
//    void slotSend();
//    void slotBtn();

};

#endif // MYUPDATE_H
