# Qt libs to import
QT += network

# Project configs
TEMPLATE = app
DESTDIR  = ../bin
TARGET   = FIRAClient
VERSION  = 1.0.0

CONFIG += c++14 console
CONFIG -= app_bundle

# Temporary dirs
OBJECTS_DIR = tmp/obj
MOC_DIR = tmp/moc
UI_DIR = tmp/moc
RCC_DIR = tmp/rc

# Project libs
LIBS *= -lprotobuf -lQt5Core

# Compiling .proto files
system(echo "Compiling protobuf files" && cd proto && cmake . && make)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        clients/actuator/actuatorclient.cpp \
        clients/client.cpp \
        clients/referee/refereeclient.cpp \
        clients/replacer/replacerclient.cpp \
        clients/vision/visionclient.cpp \
        main.cpp \
        proto/command.pb.cc \
        proto/common.pb.cc \
        proto/packet.pb.cc \
        proto/replacement.pb.cc \
        proto/vssref_command.pb.cc \
        proto/vssref_common.pb.cc \
        proto/vssref_placement.pb.cc \
        utils/timer/timer.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    clients/actuator/actuatorclient.h \
    clients/client.h \
    clients/referee/refereeclient.h \
    clients/replacer/replacerclient.h \
    clients/vision/visionclient.h \
    proto/command.pb.h \
    proto/common.pb.h \
    proto/packet.pb.h \
    proto/replacement.pb.h \
    proto/vssref_command.pb.h \
    proto/vssref_common.pb.h \
    proto/vssref_placement.pb.h \
    utils/timer/timer.h
