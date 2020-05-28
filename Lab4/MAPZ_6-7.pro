#-------------------------------------------------
#
# Project created by QtCreator 2020-05-13T16:09:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MAPZ_6-7
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



CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    abstractgen.cpp \
    builder.cpp \
    enemy.cpp \
    entity.cpp \
    playersingleton.cpp \
    resourse.cpp \
    statussingleton.cpp \
    facade.cpp \
    proxy.cpp \
    memento.cpp \
    strategy.cpp \
    command.cpp \
    observer.cpp



HEADERS += \
        mainwindow.h \
    abstractgen.h \
    builder.h \
    enemy.h \
    entity.h \
    enums.h \
    playersingleton.h \
    resourse.h \
    statussingleton.h \
    facade.h \
    proxy.h\
    memento.h \
    serialization.h \
    strategy.h \
    command.h \
    observer.h


FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Background/House.png \
    Monsters/Haunted Skull.png \
    Monsters/Skeleton.png

