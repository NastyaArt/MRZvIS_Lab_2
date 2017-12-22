#-------------------------------------------------
#
# Project created by QtCreator 2017-12-20T13:06:42
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = MRZ_Lab_2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH +=   D:\Nastya\Programs\Libriaries\CImg-2.1.2_pre102517 \
        D:\Nastya\Programs\Libriaries\armadillo-8.200.1\include

LIBS += -lAdvapi32 -lgdi32 -luser32 -lshell32 \
    -LD:\Nastya\Programs\Libriaries\armadillo-8.200.1\examples\lib_win64 \
    -llapack_win64_MT \
    -lblas_win64_MT


SOURCES += main.cpp \
    jordanelmannet.cpp

HEADERS += \
    jordanelmannet.h
