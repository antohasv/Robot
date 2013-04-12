#-------------------------------------------------
#
# Project created by QtCreator 2013-04-11T18:04:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QRobot
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
    Window.h \
    Unit.h \
    Star.h \
    Robot.h \
    Power.h \
    Points.h \
    IMAGEFILE.h \
    IMAGEFIE.h \
    Image.h \
    Field.h \
    Event.h \
    Door.h \
    CountDown.h \
    Bomb.h \
    Battery.h

FORMS    += mainwindow.ui
