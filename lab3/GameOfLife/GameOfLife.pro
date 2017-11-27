#-------------------------------------------------
#
# Project created by QtCreator 2017-11-27T16:17:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameOfLife
TEMPLATE = app


SOURCES += main.cpp\
    renderarea.cpp \
    window.cpp

HEADERS  += \
    renderarea.h \
    window.h

FORMS    += mymainwindow.ui
