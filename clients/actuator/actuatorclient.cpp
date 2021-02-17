#include "actuatorclient.h"

void ActuatorClient::connectToNetwork() {
    // Creating socket pointer
    _clientSocket = new QUdpSocket();

    // Connecting to network
    _clientSocket->connectToHost(_serverAddress, _serverPort, QUdpSocket::WriteOnly, QUdpSocket::IPv4Protocol);
}

void ActuatorClient::disconnectFromNetwork() {
    // Check if is open and close
    if(_clientSocket->isOpen()) {
        _clientSocket->close();
    }

    delete _clientSocket;
}

void ActuatorClient::setTeamColor(VSSRef::Color teamColor) {
    _teamColor = teamColor;
}

void ActuatorClient::sendCommand(quint8 robotId, float wheelLeft, float wheelRight) {
    // Check if is connected and call run one time
    if(!_isConnected) {
        run();
    }

    // Creating packet
    fira_message::sim_to_ref::Packet packet;
    fira_message::sim_to_ref::Command *command = packet.mutable_cmd()->add_robot_commands();

    // Filling command with data
    command->set_yellowteam((_teamColor == VSSRef::Color::YELLOW) ? true : false);
    command->set_id(robotId);
    command->set_wheel_left(wheelLeft);
    command->set_wheel_right(wheelRight);

    // Sending data to network
    std::string buffer;
    packet.SerializeToString(&buffer);
    if(_clientSocket->write(buffer.c_str(), buffer.length()) == -1) {
        std::cout << "[ERROR] Failed to send packet in Actuator.\n";
    }
}

void ActuatorClient::runClient() {
    // Empty (sendCommand is our run)
}
