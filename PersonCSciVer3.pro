#-------------------------------------------------
#
# Project created by QtCreator 2014-12-11T13:08:20
#
#-------------------------------------------------

QT       += core gui sql
QT		 += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PersonCSciVer3
TEMPLATE = app


SOURCES += main.cpp\
    computer.cpp \
    computerservice.cpp \
    computerrepository.cpp \
    person.cpp \
    personservice.cpp \
    personrepository.cpp \
    adddialog.cpp \
    mainwindow.cpp \
    formconnectiondialog.cpp \
    aboutdialog.cpp \
    specificviewdialog.cpp

HEADERS  += \
    computer.h \
    computerservice.h \
    computerrepository.h \
    person.h \
    personservice.h \
    personrepository.h \
    adddialog.h \
    mainwindow.h \
    formconnectiondialog.h \
    aboutdialog.h \
    specificviewdialog.h

FORMS    += \
    adddialog.ui \
    mainwindow.ui \
    formconnectiondialog.ui \
    aboutdialog.ui \
    specificviewdialog.ui

RESOURCES += \
    logos.qrc
