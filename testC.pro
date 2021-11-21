TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    manageGame.c \
    manageInfo.c \
    spacehip.c


INCLUDEPATH += C:\QtProject\testC\SDL2-2.0.16\x86_64-w64-mingw32\include\SDL2
     LIBS += -L C:\QtProject\testC\SDL2-2.0.16\x86_64-w64-mingw32\lib -lmingw32 -mwindows -mconsole -lSDL2main -lSDL2
     CXXFLAGS = -std=c++11

DISTFILES += \
    alien.png \
    bg.bmp \
    spaceship.bmp

HEADERS += \
    ManageGame.h \
    ManageInfo.h \
    Spaceship.h
