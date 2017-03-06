#-------------------------------------------------
#
# Project created by QtCreator 2017-03-02T21:35:08
#
#-------------------------------------------------

QT       += core gui
QT  += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcpServer
TEMPLATE = app

MOC_DIR = ../build/$$TARGET/moc
OBJECTS_DIR = ../build/$$TARGET/obj
DESTDIR = ../bin


SOURCES += main.cpp\
        server.cpp

HEADERS  += server.h

FORMS    += server.ui
