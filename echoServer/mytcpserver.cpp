#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include<QString>

MyTcpServer::~MyTcpServer()
{

    mTcpServer->close();
    //server_status=0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        //server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    //   if(server_status==1){
    /*mTcpSocket = mTcpServer->nextPendingConnection();
    mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
    connect(mTcpSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
    connect(mTcpSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);*/
    // }

    QTcpSocket* mTcpSocket = mTcpServer->nextPendingConnection();
    mTcpSocket->write("Hello, World!!! I am echo server!\r\n");

    clients.push_back(mTcpSocket);

    connect(mTcpSocket,
            &QTcpSocket::readyRead,
            this,
            [=]() {
                auto it = std::find(clients.begin(), clients.end(), mTcpSocket);
                this->slotServerRead(*it);
            } );
    connect(mTcpSocket,
            &QTcpSocket::disconnected,
            this,
            [=]() {
                auto it = std::find(clients.begin(), clients.end(), mTcpSocket);
                this->slotClientDisconnected(*it);
            } );
}

void MyTcpServer::slotServerRead(QTcpSocket* sock){
    QString res = "";

    if(sock->bytesAvailable()>0)
    {
        QByteArray array = sock->readAll();
        qDebug()<<array<<"\n";
        array.chop(2);
        res.append(array);
    }

    //res = parsing(res);
    res = processInput(res);
    res.append("\r\n");

    if(res.at(0) == '!') {
        sock->write(res.toUtf8());
    } else {
        for(auto it = clients.begin(); it != clients.end(); it++) {
            (*it)->write(res.toUtf8());
        }
    }
}

void MyTcpServer::slotClientDisconnected(QTcpSocket* sock){
    sock->close();
    clients.erase(std::find(clients.begin(), clients.end(), sock));
}
