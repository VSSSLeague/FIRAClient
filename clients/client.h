#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <QMutex>
#include <QUdpSocket>
#include <QReadWriteLock>
#include <QNetworkDatagram>

class Client
{
public:
    Client(QString serverAddress, quint16 serverPort);

    // Run
    void run();
    void close();

protected:
    // Network data
    QUdpSocket *_clientSocket;
    QString _serverAddress;
    quint16 _serverPort;

    // Internal management
    bool _isConnected;

private:
    // Network management
    virtual void connectToNetwork() = 0;
    virtual void disconnectFromNetwork() = 0;

    // Internal run
    virtual void runClient() = 0;
};

#endif // CLIENT_H
