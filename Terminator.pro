TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#WINDOWS
# put SFML file in the same location as project
LIBS += -L"C:\Users\mati1\OneDrive\Dokumenty\Terminator\SFML-2.5.1\lib" #change this
LIBS += -L"C:\Users\mati1\OneDrive\Dokumenty\Terminator\SFML-2.5.1\bin" #change this

#MAC
#LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "C:\Users\mati1\OneDrive\Dokumenty\Terminator\SFML-2.5.1\include" #change this
DEPENDPATH += "C:\Users\mati1\OneDrive\Dokumenty\Terminator\SFML-2.5.1\include" #change this


SOURCES += \
        Hero.cpp \
        background.cpp \
        bullet.cpp \
        button.cpp \
        health.cpp \
        main.cpp \
        map.cpp \
        meleeenemy.cpp \
        rangeenemy.cpp \
        terminator.cpp \
        wall.cpp

HEADERS += \
    Hero.h \
    background.h \
    bullet.h \
    button.h \
    health.h \
    map.h \
    meleeenemy.h \
    rangeenemy.h \
    terminator.h \
    wall.h
