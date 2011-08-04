TARGET = tests
TEMPLATE = app

CONFIG += qtestlib

QT += testlib
QT -= gui

INCLUDEPATH += . ../src

SOURCES += test_clientwindow.cpp

