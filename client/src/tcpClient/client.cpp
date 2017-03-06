#include "client.h"
#include "ui_client.h"
#include <QtNetwork>

Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(displayError(QAbstractSocket::SocketError)));
}

Client::~Client()
{
    delete ui;
}

void Client::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Client::newConnect()
{
    //初始化数据大小信息为0
    blockSize = 0;

    //取消已有的连接
//    tcpSocket->abort();
    tcpSocket->connectToHost(ui->hostLineEdit->text(),ui->portLineEdit->text().toUInt());
    qDebug() << ui->hostLineEdit->text();
}

void Client::readMessage()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_1_0);

    //如果 刚开始接收数据
    if(blockSize == 0)
    {
        //判断接受的数据数据是否大于两个字节，也就是文件大小信息所占的空间
        //如果是则保存到blockSize变量中，否则直接返回，继续接收数据
        if(tcpSocket->bytesAvailable()<(int)sizeof(quint16))
            return ;
        in << blockSize;
    }

    //如果没有全部得到数据，则返回，继续接收数据
    if(tcpSocket->bytesAvailable() < blockSize)
    {
        return ;
    }

    //将接收的数据放到变量中
    in >> message;
    qDebug() << message;
    ui->messageLabel->setText(message);
}

void Client::displayError(QAbstractSocket::SocketError)
{
    qDebug() << tcpSocket->errorString();
}

void Client::on_connectButton_clicked()
{
    newConnect();
}






































































