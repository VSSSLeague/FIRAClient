#include <QCoreApplication>

#include <clients/vision/visionclient.h>
#include <clients/actuator/actuatorclient.h>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    VisionClient *visionClient = new VisionClient("224.0.0.1", 10002);
    ActuatorClient *actuatorClient = new ActuatorClient("127.0.0.1", 20011);

    while(1) {
        visionClient->run();
        actuatorClient->sendCommand(true, 0, 30, 30);
    }

    visionClient->close();
    actuatorClient->close();

    return a.exec();
}
