#-------------------------------------------------
#
# Project created by QtCreator 2013-02-07T18:34:57
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Finke
TEMPLATE = app


SOURCES += main.cpp\
        finke.cpp \
    model/database.cpp \
    configuration.cpp

HEADERS  += finke.h \
    model/database.h \
    configuration.h

FORMS    += finke.ui
