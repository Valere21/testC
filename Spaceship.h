#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "SDL.h"
typedef struct SPACESHIP Spaceship;



Spaceship manageSpaceship(Spaceship *managerSpaceship);

void generateList(Spaceship*);
void add(Spaceship *list);

void disposeAlienShip(Spaceship*);


struct SPACESHIP{

    int posX;
    int posY;
    int Alife;
    char direction;

    SDL_Surface *s_spaceship;
    SDL_Surface *s_alienship;

    Spaceship *listSpaceship;

    Spaceship (*manageSpaceship)(Spaceship*);       //référencement du prototype de pointeur de fonction (depuis le .h), vers la déclaration de la fonction (vers le .c)
    void (*generateList)(Spaceship*);
    void (*disposeAlienShip)(Spaceship*);


};

#endif // SPACESHIP_H
