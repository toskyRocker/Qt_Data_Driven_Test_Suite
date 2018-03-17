
QT += \
        testlib \
        xml \
        core \


CONFIG += \
        c++11 \
        console \
        testcase \


CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TEMPLATE = app

SOURCES += \
            main.cpp \
            component_a_unittest.cpp \
            jsonfileparser.cpp \
            testcaseinfo.cpp

HEADERS += \
        component_a_unittest.h \
        jsonfileparser.h \
        testcaseinfo.h \
        component_a_unittest_definitions.h

win32 {
    CONFIG(debug, debug|release) {
        DESTDIR = debug
    } else {
        DESTDIR = release
    }
}

COMPONENT_A = $$OUT_PWD/../Component_A/$$DESTDIR

INCLUDEPATH += ../Component_A




win32:LIBS += -L$$COMPONENT_A -lComponent_A

DESTINATION = $$OUT_PWD/$$DESTDIR
win32:DESTINATION ~= s,/,\\,g

dest_dependencies.path = $$DESTINATION
dest_dependencies.files += $$COMPONENT_A/Component_A.dll

