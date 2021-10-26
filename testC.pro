TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    manageGame.c \
    spaceship.c


INCLUDEPATH += C:/SDL2-2.0.16/x86_64-w64-mingw32/include/SDL2
     LIBS += -L C:/SDL2-2.0.16/x86_64-w64-mingw32/lib -lmingw32 -mwindows -mconsole -lSDL2main -lSDL2
     CXXFLAGS = -std=c++11

DISTFILES += \
    alien.bmp \
    vaisseaux.bmp

HEADERS += \
    Spaceship.h \
    manageGame.h
