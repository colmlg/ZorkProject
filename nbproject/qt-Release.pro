# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux
TARGET = ZorkProject
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += Character.cpp Inventory.cpp Item.cpp MainWindow.cpp Room.cpp ZorkUL.cpp main.cpp
HEADERS += Character.h Inventory.h Item.h MainWindow.h Room.h ZorkUL.h
FORMS +=
RESOURCES += images.qrc itemicons.qrc
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
