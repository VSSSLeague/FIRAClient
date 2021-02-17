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
system(echo "Compiling protobuf files" && cd include/proto && protoc --cpp_out=../ *.proto && cd ../..)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        clients/actuator/actuatorclient.cpp \
        clients/client.cpp \
        clients/referee/refereeclient.cpp \
        clients/replacer/replacerclient.cpp \
        clients/vision/visionclient.cpp \
        include/command.pb.cc \
        include/common.pb.cc \
        include/packet.pb.cc \
        include/replacement.pb.cc \
        include/vssref_command.pb.cc \
        include/vssref_common.pb.cc \
        include/vssref_placement.pb.cc \
        main.cpp \
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
    include/command.pb.h \
    include/common.pb.h \
    include/packet.pb.h \
    include/replacement.pb.h \
    include/vssref_command.pb.h \
    include/vssref_common.pb.h \
    include/vssref_placement.pb.h \
    utils/timer/timer.h
