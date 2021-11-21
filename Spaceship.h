#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "SDL.h"
typedef struct SPACESHIP Spaceship;
typedef struct MANAGEGAME ManageGame;



Spaceship *manageSpaceship(ManageGame *manager, Spaceship *managerSpaceship);

void add(Spaceship *list);
void disposeAlienShip(Spaceship*);

void moveLeft(ManageGame*);
void moveRight(ManageGame*);
void shoot(Spaceship*);

struct SPACESHIP{

    // fonctions

    Spaceship *(*manageSpaceship)(ManageGame *, Spaceship*);       //référencement du prototype de pointeur de fonction (depuis le .h), vers la déclaration de la fonction (vers le .c)
//    void (*generateList)(Spaceship*);
    void (*disposeAlienShip)(Spaceship*);

    void (*moveLeft)(ManageGame*);
    void (*moveRight)(ManageGame*);
    void (*shoot)(Spaceship*);


    // attribut
    int posX;
    int posY;

    int width;
    int height;

    int Alife;
    char direction;

    SDL_Surface *s_spaceship;
    SDL_Surface *s_alienship;


};

#endif // SPACESHIP_H
