QT += testlib
QT += gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++17

TEMPLATE = app

SOURCES +=  tst_myclassunittest.cpp \
    ../blackhole-simulator/bhs.cpp \
    biquaternionunittest.cpp \
    octonionunittest.cpp \
    quaternionunittest.cpp \
    spacetimetest.cpp \
    vector3unittest.cpp \
    cliffordunittest.cpp

HEADERS += \
    ../blackhole-simulator/hnn/clifford_common.h \
    ../blackhole-simulator/hnn/clifford13.h \
    ../blackhole-simulator/hnn/clifford31.h \
    biquaternionunittest.h \
    octonionunittest.h \
    quaternionunittest.h \
    spacetimetest.h \
    vector3unittest.h\
    cliffordunittest.h
