#-------------------------------------------------
#
# Project created by QtCreator 2017-03-03T22:56:44
#
#-------------------------------------------------

QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcpClient
TEMPLATE = app

OBJECTS_DIR = ../build/$$TARGET/obj
MOC_DIR = ../build/$$TARGET/moc
DESTDIR = ../bin


SOURCES += main.cpp\
        client.cpp

HEADERS  += client.h

FORMS    += client.ui
