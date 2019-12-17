#-------------------------------------------------
#
# Project created by QtCreator 2019-12-17T00:09:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = l
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    bank.cpp

HEADERS += \
        mainwindow.h \
    bank.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    ../../../tmp/VirtualBox Dropped Files/2019-12-17T07:55:31.957912000Z/cards.txt \
    ../../../tmp/VirtualBox Dropped Files/2019-12-17T07:55:31.957912000Z/base.txt \
    ../../../tmp/VirtualBox Dropped Files/2019-12-17T07:56:04.966472000Z/cards.txt \
    base.txt \
    cards.txt
