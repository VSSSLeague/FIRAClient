#include "replacerclient.h"

void ReplacerClient::connectToNetwork() {
    // Creating socket pointer
    _clientSocket = new QUdpSocket();

    // Connecting to network
    _clientSocket->connectToHost(_serverAddress, _serverPort, QUdpSocket::WriteOnly, QUdpSocket::IPv4Protocol);
}

void ReplacerClient::disconnectFromNetwork() {
    // Check if is open and close
    if(_clientSocket->isOpen()) {
        _clientSocket->close();
    }

    delete _clientSocket;
}

void ReplacerClient::setTeamColor(VSSRef::Color teamColor) {
    _teamColor = teamColor;
}

void ReplacerClient::placeRobot(quint8 playerId, float posX, float posY, float orientation) {
    _frameMutex.lock();

    // Fill robot data
    QPair<QVector2D, float> robotData(QVector2D(posX, posY), orientation);

    // Set to hash
    _robots.insert(playerId, robotData);

    _frameMutex.unlock();
}

void ReplacerClient::sendFrame() {
    // Check if is connected and call run one time
    if(!_isConnected) {
        run();
    }

    // Creating packet
    VSSRef::team_to_ref::VSSRef_Placement placement;
    VSSRef::Frame *frame = new VSSRef::Frame();

    // Filling frame
    frame->set_teamcolor(_teamColor);

    _frameMutex.lock();
    QList<quint8> ids = _robots.keys();
    for(int i = 0; i < ids.size(); i++) {
        // Take data from hash
        QVector2D position = _robots.value(ids.at(i)).first;
        float orientation = _robots.value(ids.at(i)).second;

        VSSRef::Robot *robot = frame->add_robots();
        robot->set_robot_id(ids.at(i));
        robot->set_x(position.x());
        robot->set_y(position.y());
        robot->set_orientation(orientation);
    }
    _frameMutex.unlock();

    // Set frame
    placement.set_allocated_world(frame);

    // Sending data to network
    std::string buffer;
    placement.SerializeToString(&buffer);
    if(_clientSocket->write(buffer.c_str(), buffer.length()) == -1) {
        std::cout << "[ERROR] Failed to send packet in Replacer.\n";
    }

    // Cleaning hash
    _robots.clear();
}

void ReplacerClient::runClient() {
    // Empty (sendCommand is our run)
}
