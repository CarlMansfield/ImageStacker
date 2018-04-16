#-------------------------------------------------
#
# Project created by QtCreator 2016-05-16T03:11:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -Ld:/opencl/lib/x86/ -lOpenCL
else:win32:CONFIG(debug, debug|release): LIBS += -Ld:/opencl/lib/x86/ -lOpenCL

LIBS += d:/EDSDK/Library/EDSDK.lib

INCLUDEPATH += d:/opencl/include
INCLUDEPATH += d:/EDSDK/Header
DEPENDPATH += d:/opencl/include
