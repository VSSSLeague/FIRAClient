#ifndef REFEREECLIENT_H
#define REFEREECLIENT_H

#include <clients/client.h>
#include <include/vssref_command.pb.h>

class RefereeClient : public Client
{
public:
    using Client::Client;

    // Internal getters
    VSSRef::Foul getLastFoul();
    VSSRef::Color getLastFoulColor();
    VSSRef::Quadrant getLastFoulQuadrant();

private:
    // Environment management
    std::tuple<VSSRef::Foul, VSSRef::Color, VSSRef::Quadrant> _lastFoulData;
    QReadWriteLock _foulMutex;

    // Network management
    void connectToNetwork();
    void disconnectFromNetwork();

    // Internal run
    void runClient();
};

#endif // REFEREECLIENT_H
