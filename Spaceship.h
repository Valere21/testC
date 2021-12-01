#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "SDL.h"
typedef struct SPACESHIP Spaceship;
typedef struct MANAGEGAME ManageGame;



Spaceship *manageSpaceship(ManageGame *manager, Spaceship *managerSpaceship);


void shoot(Spaceship*);
void moveLeft(ManageGame*);
void moveRight(ManageGame*);
void disposeAlienShip(ManageGame*);

//Gère la liste chainée contenant les vaisseaux aliens

//Spaceship *append(Spaceship* ship);


void removeAt(Spaceship* ship, int index);




struct SPACESHIP{

    // fonctions

    Spaceship *(*manageSpaceship)(ManageGame *, Spaceship*);       //référencement du prototype de pointeur de fonction (depuis le .h), vers la déclaration de la fonction (vers le .c)


    void (*disposeAlienShip)(ManageGame*);

    void (*moveLeft)(ManageGame*);
    void (*moveRight)(ManageGame*);
    void (*shoot)(Spaceship*);




    Spaceship (*prepend)(Spaceship*);

    void (*removeAt)(Spaceship*, int);


    // attribut
    int id;
    int posX;
    int posY;

    int width;
    int height;

    int Alife;
    char direction;

    SDL_Surface *s_spaceship;
    SDL_Surface *s_alienship;

    Spaceship *nextShip;


};

#endif // SPACESHIP_H
