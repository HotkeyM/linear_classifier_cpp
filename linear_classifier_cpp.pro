TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mnistset.cpp \
    classifier.cpp

HEADERS += \
    mnistset.h \
    classifier.h
