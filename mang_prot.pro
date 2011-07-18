######################################################################
# Automatically generated by qmake (2.01a) Tue Jun 7 12:21:12 2011
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

CONFIG += qt debug warn_on
OBJECTS_DIR = ./obj
MOC_DIR = ./moc

QT += sql

# Input
HEADERS += clientmodel.h \
           mainpresenter.h \
           databasemanager.h \
           defandpar.h \
           mainform.h \
           clientwindow.h \
           clientorder.h \
           clientpresenter.h \
           iviewform.h \
           iviewclientform.h\
           statisticWindow.h

SOURCES += clientmodel.cpp \
           mainpresenter.cpp \
           databasemanager.cpp \
           main.cpp \
           mainform.cpp \
           clientwindow.cpp \
           clientorder.cpp \
           clientpresenter.cpp\
           statisticwindow.cpp

QMAKE_CXXFLAGS += -DAPP_DATE=\\\"`date +'\"%a_%b_%d,_%Y\"'`\\\"
QMAKE_CXXFLAGS += -DAPP_VERSION=\\\"`git describe`\\\"


################################################################
