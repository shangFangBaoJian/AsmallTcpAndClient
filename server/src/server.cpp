#include "server.h"
#include "ui_server.h"
#include <QtNetwork>

Server::Server(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);
    if(!tcpServer->listen(QHostAddress::LocalHost,6666))
    {
        qDebug() << tcpServer->errorString();
        close();
    }
    qDebug() << tcpServer->serverAddress() ;
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(sendMessage()));
}

void Server::sendMessage()
{
    //??????????
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);

    //????????????????????????
    out.setVersion(QDataStream::Qt_1_0);
    out << (quint16)0;
    out << tr("hellow TCP");
    out << (quint16)(block.size() - sizeof(quint16));
    out.device()->seek(0);


    //????????????
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection,SIGNAL(disconnected()),clientConnection,SLOT(deleteLater()));
    clientConnection->write(block);
    clientConnection->disconnectFromHost();

    //??????????
    ui->label->setText("send message successful!");
}

Server::~Server()
{
    delete ui;
}
