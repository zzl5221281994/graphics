#-------------------------------------------------
#
# Project created by QtCreator 2018-03-07T22:53:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = graphics
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
    base/vector2.cpp \
    base/vector3.cpp \
    base/rgb.cpp \
    base/image.cpp \
    base/graphic_algorithm.cpp

HEADERS += \
        mainwindow.h \
    base/vector2.h \
    base/vector3.h \
    base/rgb.h \
    base/image.h \
    base/include.h \
    base/graphic_algorithm.h \
    base/constant.h \
    base/math.h \
    base/point.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    base/test.txt
