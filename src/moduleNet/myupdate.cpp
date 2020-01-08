#include "myupdate.h"

MyUpdate::MyUpdate(QWidget *parent) : QWidget(parent)
{
    initGui();

    tcpClient = new QTcpSocket(this);
    tcpClient->abort();

    connect(tcpClient, SIGNAL(readyRead()), this, SLOT(ReadData()));
    connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)), \
            this, SLOT(ReadError(QAbstractSocket::SocketError)));

    tcpClient->connectToHost(lEIP->text(), lEPort->text().toInt());
    if (tcpClient->waitForConnected(1000))  // 连接成功则进入if{}
    {
        btnConnect->setText("断开");
        btnSend->setEnabled(true);
    }

}

void MyUpdate::initGui()
{
    QHBoxLayout *hBox1 = new QHBoxLayout;
    hBox1->addWidget(lblIP);
    hBox1->addWidget(lEIP);
    lblIP->setText("IP:");
    lEIP->setText("IP:");

    QHBoxLayout *hBox2 = new QHBoxLayout;
    hBox2->addWidget(lblPort);
    hBox2->addWidget(lEPort);
    lblPort->setText("IP:");
    lEPort->setText("IP:");

    QVBoxLayout *vBox = new QVBoxLayout;

    vBox->addLayout(hBox1);
    vBox->addLayout(hBox2);

    setLayout(vBox);

}

void MyUpdate::ReadData()
{

    QByteArray buffer = tcpClient->readAll();
    if(!buffer.isEmpty())
    {
//        ui->edtRecv->append(buffer);
    }

}
