QT += widgets
TEMPLATE = lib
CONFIG	+= plugin
INCLUDEPATH += ../../src
HEADERS += \
    myplugin.hpp \
    DrawESGI/abstractmenu.hpp
SOURCES	+= \
    myplugin.cpp
TARGET	= plugin_menu
