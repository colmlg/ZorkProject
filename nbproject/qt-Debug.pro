# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = ZorkProject
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += Character.cpp Command.cpp CommandWords.cpp Inventory.cpp Item.cpp MainWindow.cpp MainWindowRoomInventory.cpp Parser.cpp Room.cpp ZorkUL.cpp main.cpp
HEADERS += Character.h Command.h CommandWords.h Inventory.h Item.h MainWindow.h Parser.h Room.h ZorkUL.h
FORMS +=
RESOURCES += images.qrc itemicons.qrc
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
