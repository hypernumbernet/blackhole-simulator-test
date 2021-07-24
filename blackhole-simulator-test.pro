QT += testlib
QT += gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++17

TEMPLATE = app

SOURCES +=  tst_myclassunittest.cpp \
    quaternionunittest.cpp \
    vector3unittest.cpp

HEADERS += \
    quaternionunittest.h \
    vector3unittest.h
