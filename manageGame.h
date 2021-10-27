#ifndef MANAGEGAME_H
#define MANAGEGAME_H
#include <Spaceship.h>
#include "SDL.h"
#include <stdio.h>

typedef struct MANAGEGAME ManageGame;

enum level {
    niveau1 = 0,
    niveau2 = 1,
    niveau3 = 2,
    niveauInfini = 3
};

enum bool {
    false = 0,
    true = 1
};

ManageGame manageGame(ManageGame);
void loopGame();

struct MANAGEGAME{

    int level;
    SDL_Window *s_window;
    SDL_Surface *s_galaxyBackground;
    SDL_Renderer *s_renderer;



    ManageGame (*manageGame)(ManageGame);       //référencement du prototype de pointeur de fonction (depuis le .h), vers la déclaration de la fonction (vers le .c)
    ManageGame (*loopGame)();
};


#endif // MANAGEGAME_H
