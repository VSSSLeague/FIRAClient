#ifndef VISIONCLIENT_H
#define VISIONCLIENT_H

#include <clients/client.h>
#include <include/packet.pb.h>

class VisionClient : public Client
{
public:
    using Client::Client;

    // Internal getter
    fira_message::sim_to_ref::Environment getLastEnvironment();

private:
    // Environment management
    fira_message::sim_to_ref::Environment _lastEnvironment;
    QReadWriteLock _environmentMutex;

    // Network management
    void connectToNetwork();
    void disconnectFromNetwork();

    // Internal run
    void runClient();
};

#endif // VISIONCLIENT_H
