#ifndef ACTUATORCLIENT_H
#define ACTUATORCLIENT_H

#include <clients/client.h>
#include <include/vssref_common.pb.h>
#include <include/packet.pb.h>

class ActuatorClient : public Client
{
public:
    using Client::Client;
    void setTeamColor(VSSRef::Color teamColor);
    void sendCommand(quint8 robotId, float wheelLeft, float wheelRight);

private:
    // Internal
    VSSRef::Color _teamColor;

    // Network management
    void connectToNetwork();
    void disconnectFromNetwork();

    // Internal run
    void runClient();
};

#endif // ACTUATORCLIENT_H
