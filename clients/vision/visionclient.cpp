#include "visionclient.h"

void VisionClient::connectToNetwork() {
    // Creating socket pointer
    _clientSocket = new QUdpSocket();

    // Binding in defined network
    if(_clientSocket->bind(QHostAddress(_serverAddress), _serverPort, QUdpSocket::ShareAddress) == false) {
        std::cout << "[ERROR] Error while binding vision socket.\n";
        return ;
    }

    // Joining to multicast
    if(_clientSocket->joinMulticastGroup(QHostAddress(_serverAddress)) == false) {
        std::cout << "[ERROR] Error while joining multicast in vision socket.\n";
        return ;
    }
}

void VisionClient::disconnectFromNetwork() {
    // Check if is open and close
    if(_clientSocket->isOpen()) {
        _clientSocket->close();
    }

    delete _clientSocket;
}

void VisionClient::runClient() {
    while(_clientSocket->hasPendingDatagrams()) {
        // Creating auxiliary vars
        fira_message::sim_to_ref::Environment environment;
        QNetworkDatagram datagram;

        // Reading datagram from network
        datagram = _clientSocket->receiveDatagram();

        // Check if datagram is valid (sender valid)
        if(!datagram.isValid()) {
            continue;
        }

        // Parsing datagram data to protobuf
        if(environment.ParseFromArray(datagram.data().data(), datagram.data().size()) == false) {
            std::cout << "[ERROR] Failure to parse protobuf data from datagram.\n";
            continue;
        }

        // Update last environment
        _environmentMutex.lockForWrite();
        _lastEnvironment = environment;
        _environmentMutex.unlock();
    }
}

fira_message::sim_to_ref::Environment VisionClient::getLastEnvironment() {
    _environmentMutex.lockForRead();
    fira_message::sim_to_ref::Environment lastEnvironment = _lastEnvironment;
    _environmentMutex.unlock();

    return lastEnvironment;
}
