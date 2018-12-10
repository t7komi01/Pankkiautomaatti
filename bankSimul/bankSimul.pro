#-------------------------------------------------
#
# Project created by QtCreator 2018-12-03T09:32:01
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bankSimul
TEMPLATE = app
LIBS +="C:\BankSimul\build-bankSimul-Desktop_Qt_5_9_1_MinGW_32bit-Debug\debug\BankLibrary.dll"
LIBS +="C:\BankSimul\build-bankSimul-Desktop_Qt_5_9_1_MinGW_32bit-Debug\debug\DBConnect.dll"

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        banksimulmainwindow.cpp

HEADERS += \
        banksimulmainwindow.h \
    banklibrary.h \
    banklibrary_global.h \
    headers/banklibrary.h \
    headers/banklibrary_global.h \
    headers/dbconnect.h \
    headers/dbconnect_global.h

FORMS += \
        banksimulmainwindow.ui
