#ifndef MANAGEGAME_H
#define MANAGEGAME_H
#include <Spaceship.h>
#include "SDL.h"
#include <stdio.h>

typedef struct MANAGEGAME ManageGame;

enum pictureType {
    Background,
    Spaceship,
    Alien
};

enum flagPicture {

    fullBackground,
    minimizeBackground,
    setupAlienSpaceship,
    spawnSpaceship,
    respawnSpaceship,
};

enum toolSDL{
    windowTool,
    rendererTool,
    surfaceTool,
    textureTool
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



ManageGame manageGame(ManageGame);
ManageGame loopGame(ManageGame manager);

enum bool LoadImage(int type);

struct MANAGEGAME{

    int level;
    SDL_Window *s_window;
    SDL_Surface *s_surface;
    SDL_Renderer *s_renderer;
    SDL_Texture *s_texture;
    SDL_Texture *s_textShip;
    SDL_Texture *s_textAlien;



    ManageGame (*manageGame)(ManageGame);       //référencement du prototype de pointeur de fonction (depuis le .h), vers la déclaration de la fonction (vers le .c)
    ManageGame (*loopGame)();
};


#endif // MANAGEGAME_H
