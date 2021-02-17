#include "refereeclient.h"

void RefereeClient::connectToNetwork() {
    // Creating socket pointer
    _clientSocket = new QUdpSocket();

    // Binding in defined network
    if(_clientSocket->bind(QHostAddress(_serverAddress), _serverPort, QUdpSocket::ShareAddress) == false) {
        std::cout << "[ERROR] Error while binding referee socket.\n";
        return ;
    }

    // Joining to multicast
    if(_clientSocket->joinMulticastGroup(QHostAddress(_serverAddress)) == false) {
        std::cout << "[ERROR] Error while joining multicast in referee socket.\n";
        return ;
    }
}

void RefereeClient::disconnectFromNetwork() {
    // Check if is open and close
    if(_clientSocket->isOpen()) {
        _clientSocket->close();
    }

    delete _clientSocket;
}

void RefereeClient::runClient() {
    while(_clientSocket->hasPendingDatagrams()) {
        // Creating auxiliary vars
        VSSRef::ref_to_team::VSSRef_Command command;
        QNetworkDatagram datagram;

        // Reading datagram from network
        datagram = _clientSocket->receiveDatagram();

        // Check if datagram is valid (sender valid)
        if(!datagram.isValid()) {
            continue;
        }

        // Parsing datagram data to protobuf
        if(command.ParseFromArray(datagram.data().data(), datagram.data().size()) == false) {
            std::cout << "[ERROR] Failure to parse protobuf data from datagram.\n";
            continue;
        }

        // Update last environment
        _foulMutex.lockForWrite();
        _lastFoulData = std::make_tuple<VSSRef::Foul, VSSRef::Color, VSSRef::Quadrant>(command.foul(), command.teamcolor(), command.foulquadrant());
        _foulMutex.unlock();
    }
}

VSSRef::Foul RefereeClient::getLastFoul() {
    _foulMutex.lockForRead();
    VSSRef::Foul lastFoul = std::get<0>(_lastFoulData);
    _foulMutex.unlock();

    return lastFoul;
}

VSSRef::Color RefereeClient::getLastFoulColor() {
    _foulMutex.lockForRead();
    VSSRef::Color lastFoulColor = std::get<1>(_lastFoulData);
    _foulMutex.unlock();

    return lastFoulColor;
}

VSSRef::Quadrant RefereeClient::getLastFoulQuadrant() {
    _foulMutex.lockForRead();
    VSSRef::Quadrant lastFoulQuadrant = std::get<2>(_lastFoulData);
    _foulMutex.unlock();

    return lastFoulQuadrant;
}
