#ifndef CLIENT_H
#define CLIENT_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QDialog>
#endif

#include <QAbstractSocket>
#include <QTcpSocket>

namespace Ui {
class Client;
}

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

protected:
    void changeEvent(QEvent *e);

private slots:
    void newConnect();
    void readMessage();
    void displayError(QAbstractSocket::SocketError);

    void on_connectButton_clicked();

private:
    Ui::Client *ui;
    QTcpSocket *tcpSocket;
    QString message;
    //用来存放数据的大小信息
    quint16 blockSize;
};

#endif // CLIENT_H
