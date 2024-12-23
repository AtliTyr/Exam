QT += testlib sql network
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_funcforserver_test.cpp \
    ../echoServer/functions.cpp
HEADERS += \
    ../echoServer/functions.h
