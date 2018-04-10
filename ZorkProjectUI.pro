#-------------------------------------------------
#
# Project created by QtCreator 2018-02-12T16:14:17
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZorkProjectUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    battledialog.cpp \
    map.cpp \
    zorkgame.cpp \
    enemy.cpp \
    entity.cpp \
    inventory.cpp \
    item.cpp \
    mainwindow.cpp \
    player.cpp \
    room.cpp \
    weapon.cpp

HEADERS += \
    battledialog.h \
    map.h \
    zorkgame.h \
    constants.h \
    direction.h \
    enemy.h \
    entity.h \
    inventory.h \
    item.h \
    mainwindow.h \
    player.h \
    room.h \
    weapon.h

FORMS += \
        mainwindow.ui \
    battledialog.ui

RESOURCES += \
    images.qrc
