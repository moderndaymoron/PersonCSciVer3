#-------------------------------------------------
#
# Project created by QtCreator 2014-12-11T13:08:20
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PersonCSciVer3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    computerservice.cpp \
    computerrepository.cpp \
    person.cpp \
    personservice.cpp \
    personrepository.cpp \
    adddialog.cpp

HEADERS  += mainwindow.h \
    computer.h \
    computerservice.h \
    computerrepository.h \
    person.h \
    personservice.h \
    personrepository.h \
    adddialog.h

FORMS    += mainwindow.ui \
    adddialog.ui
