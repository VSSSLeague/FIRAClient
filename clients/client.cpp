#include "client.h"

Client::Client(QString serverAddress, quint16 serverPort) {
    _serverAddress = serverAddress;
    _serverPort = serverPort;
    _isConnected = false;
}

void Client::run() {
    if(!_isConnected) {
        connectToNetwork();
        _isConnected = true;
    }

    runClient();
}

void Client::close() {
    if(_isConnected) {
        disconnectFromNetwork();
        _isConnected = false;
    }
}
