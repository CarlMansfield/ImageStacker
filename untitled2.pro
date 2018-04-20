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
        mainwindow.cpp \
    image.cpp

HEADERS  += mainwindow.h\
    image.h

FORMS    += mainwindow.ui

#Include OpenCL libraries
win32:CONFIG(release, debug|release): LIBS += -Ld:/opencl/lib/x86/ -lOpenCL
else:win32:CONFIG(debug, debug|release): LIBS += -Ld:/opencl/lib/x86/ -lOpenCL

INCLUDEPATH += d:/opencl/include

DEPENDPATH += d:/opencl/include



win32: LIBS += -L$$PWD/libraw/lib/ -llibraw

INCLUDEPATH += $$PWD/libraw
DEPENDPATH += $$PWD/libraw
