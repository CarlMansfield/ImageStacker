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

#Include OpenCL libraries
win32:CONFIG(release, debug|release): LIBS += -Ld:/opencl/lib/x64/ -lOpenCL
else:win32:CONFIG(debug, debug|release): LIBS += -Ld:/opencl/lib/x64/ -lOpenCL

INCLUDEPATH += d:/opencl/include

DEPENDPATH += d:/opencl/include

macx {
QMAKE_MAC_SDK = macosx10.13
QMAKE_LFLAGS += -framework OpenCL
INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include

LIBS += $$PWD/../../../../usr/local/lib/libraw.dylib\
        $$PWD/../../../../usr/local/lib/libexiv2.dylib
}

win32: LIBS += -L$$PWD/libraw/lib/ -llibraw

win32 {
    INCLUDEPATH  +=    d:/dev/tools/exiv2/include \
                       d:/dev/tools/exiv2/bin
    LIBS         += -Ld:/dev/tools/exiv2/lib/ -lexiv2

}

INCLUDEPATH += $$PWD/libraw \

DEPENDPATH += $$PWD/libraw \
