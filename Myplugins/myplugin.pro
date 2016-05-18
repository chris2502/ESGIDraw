TEMPLATE = lib
TARGET   = Plugin_Menu
CONFIG	+= plugin release
HEADERS += \
    myplugin.hpp \
    abstractmenu.hpp
SOURCES	+= \
    myplugin.cpp
QT += widgets
