QT       -= gui

TARGET = Component_A
TEMPLATE = lib
CONFIG += c++11

DEFINES += \
            COMPONENT_A_LIBRARY \
            QT_DEPRECATED_WARNINGS

SOURCES += \
        component_a.cpp

HEADERS += \
        component_a.h \
        component_a_global.h 

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32 {
    CONFIG(debug, debug|release) {
        DESTDIR = debug
    } else {
        DESTDIR = release
    }
}
