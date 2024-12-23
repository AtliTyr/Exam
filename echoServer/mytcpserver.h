#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

#include <QList>
#include "functions.h"

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected(QTcpSocket*);
    void slotServerRead(QTcpSocket*);
private:
    QTcpServer * mTcpServer;
    QList<QTcpSocket*> clients;
    //int server_status;
};
#endif // MYTCPSERVER_H






