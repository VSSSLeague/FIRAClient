#ifndef ACTUATORCLIENT_H
#define ACTUATORCLIENT_H

#include <clients/client.h>
#include <include/packet.pb.h>

class ActuatorClient : public Client
{
public:
    using Client::Client;
    void sendCommand(bool isYellow, quint8 robotId, float wheelLeft, float wheelRight);

private:
    // Network management
    void connectToNetwork();
    void disconnectFromNetwork();

    // Internal run
    void runClient();
};

#endif // ACTUATORCLIENT_H
