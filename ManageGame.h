#ifndef MANAGEGAME_H
#define MANAGEGAME_H
#include <Spaceship.h>
//#include <ManageInfo.h>
#include "SDL.h"
#include <stdio.h>

typedef struct MANAGEGAME ManageGame;

enum pictureType {
    Background,
    Ship,
    Alien
};

    enum flagPicture {

        FULL_BACKGROUND,
        MINIMIZE_BACKGROUND,
        RELOAD_BACKGROUND,
        setupAlienSpaceship,
        spawnSpaceship,
        respawnSpaceship,
        };

enum toolSDL{
    WINDOW_TOOL_SDL,
    RENDERER_TOOL_SDL,
    SURFACE_TOOL_SDL,
    TEXTURE_TOOL_SDL
};

enum level {
    niveau1,
    niveau2,
    niveau3,
    niveauInfini
};

enum bool {
    false = 0,
    true = 1
};



ManageGame manageGame(ManageGame *manager);
ManageGame loopGame(ManageGame *manager);

void loadPicture(ManageGame *manager, int type, int flag);
void loadAlien(ManageGame *manager, int type);
void loadSpaceship(ManageGame *manager, int type);
void loadBackground(ManageGame *manager, int type);
void erasePicture(ManageGame*, SDL_Rect*);
void reloadScreen(ManageGame*, SDL_Rect *itemToMove);
void update(ManageGame *manager);

void generateList(ManageGame *manager);


struct MANAGEGAME{

    // fonctions

    ManageGame (*manageGame)(ManageGame*);       //rÃ©fÃ©rencement du prototype de pointeur de fonction (depuis le .h), vers la dÃ©claration de la fonction (vers le .c)
    ManageGame (*loopGame)();

    void (*loadPicture)(ManageGame*, int, int);
    void (*loadAlien)(ManageGame*, int);
    void (*loadSpaceship)(ManageGame*, int);
    void (*loadBackground)(ManageGame*, int);
    void (*erasePicture)(ManageGame*, SDL_Rect*);
    void (*reloadScreen)(ManageGame*, SDL_Rect*);
    void (*update)(ManageGame*);
    void (*generateList)(ManageGame*);

    // attribut

    int level;
    SDL_Window *s_window;
    SDL_Surface *s_surface;
    SDL_Surface *s_surface_ship;

    SDL_Renderer *s_renderer;

    SDL_Texture *s_textbg;
    SDL_Texture *s_textShip;
    SDL_Texture **s_textAlien;


//    ManageInfo *managerInfo;
    Spaceship *listAlienSpaceship;
    Spaceship *ship;
};


#endif // MANAGEGAME_H
















