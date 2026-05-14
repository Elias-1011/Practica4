TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        red.cpp\
        enrutador.cpp\
        main.cpp \
        utilidades.cpp

HEADERS += \
        red.h \
        enrutador.h \
        utilidades.h

DISTFILES += \
    red.txt
