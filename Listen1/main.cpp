#include <QCoreApplication>
#include <QThread>
#include <stdio.h>
#include <QTNetwork/QTcpServer>
#include <QTNetwork/QTcpSocket>
#include <QDebug>
class  Listen1 : public QThread// 构造函数
{
public:
    Listen1(QObject *parent=0);
    QTcpServer *server;
    void run();
    void startListen();
private:
};
Listen1::Listen1(QObject *parent)
    :QThread(parent)
{
    server = new QTcpServer();
}

void Listen1::startListen()//启动服务器
{
    server->listen(QHostAddress::Any,6000);//listen函数
  // server->listen(QHostAddress("192.168.1.110"),6000);
}

void Listen1::run()//启动服务器
{
  //  server->listen(QHostAddress::Any,6000);//listen函数
  // server->listen(QHostAddress("192.168.1.110"),6000);
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Listen1 lis;//创建对象
    lis.startListen();
    lis.start();//启动线程
    //QTcpServer *server = new QTcpServer();
    //server->listen(QHostAddress::Any,6000);//listen函数

    return a.exec();
}
