TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    basic_types.cpp \
    user_defined_type.cpp \
    test_boost.cpp \
    error_handling.cpp

QMAKE_CXXFLAGS += -std=c++11
