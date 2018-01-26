#-------------------------------------------------
#
# Project created by QtCreator 2018-01-09 15:11:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameOfLife
TEMPLATE = app

SOURCES += main.cpp \
        mainwindow.cpp \
    	renderarea.cpp \
    	model.cpp \
    	controller.cpp

HEADERS  += mainwindow.h \
    		renderarea.h \
    		model.h \
    		controller.h

FORMS    += mainwindow.ui
