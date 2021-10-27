#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "SDL.h"


enum spaceshipType {

    Spaceship = 0,
    Alien = 1
};

struct VAISSEAU{

    int posX;
    int posY;
    int life;
    char direction;

    SDL_Surface *s_spaceship;
    SDL_Surface *s_alienship;

};

#endif // SPACESHIP_H
