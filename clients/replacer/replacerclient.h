#ifndef REPLACERCLIENT_H
#define REPLACERCLIENT_H

#include <QVector2D>

#include <clients/client.h>
#include <include/vssref_placement.pb.h>
#include <include/vssref_common.pb.h>

class ReplacerClient : public Client
{
public:
    using Client::Client;
    void setTeamColor(VSSRef::Color teamColor);
    void placeRobot(quint8 playerId, float posX, float posY, float orientation);
    void sendFrame();

private:
    // Internal frame management
    QHash<quint8, QPair<QVector2D, float>> _robots;
    VSSRef::Color _teamColor;
    QMutex _frameMutex;

    // Network management
    void connectToNetwork();
    void disconnectFromNetwork();

    // Internal run
    void runClient();
};

#endif // REPLACERCLIENT_H
