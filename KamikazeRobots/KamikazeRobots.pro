#-------------------------------------------------
#
# Project created by QtCreator 2013-04-04T21:20:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KamikazeRobots
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    unit.cpp \
    star.cpp \
    robot.cpp \
    power.cpp \
    points.cpp \
    image.cpp \
    field.cpp \
    door.cpp \
    countdown.cpp \
    bomb.cpp \
    battery.cpp

HEADERS  += mainwindow.h \
    Unit.h \
    Star.h \
    Robot.h \
    Power.h \
    Points.h \
    Image.h \
    Field.h \
    Door.h \
    CountDown.h \
    Bomb.h \
    Battery.h \
    IMAGEFILE.h

CONFIG += console

FORMS    += mainwindow.ui
