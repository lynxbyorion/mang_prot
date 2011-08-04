TARGET = tests
TEMPLATE = app

CONFIG += qtestlib

QT += testlib gui sql

INCLUDEPATH += . ../src

HEADERS += test_clientwindow.h

SOURCES += test_clientwindow.cpp \
        clientwindow.cpp


