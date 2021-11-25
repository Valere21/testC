#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "SDL.h"
typedef struct SPACESHIP Spaceship;
typedef struct MANAGEGAME ManageGame;



Spaceship *manageSpaceship(ManageGame *manager, Spaceship *managerSpaceship);


void shoot(Spaceship*);
void moveLeft(ManageGame*);
void moveRight(ManageGame*);
void disposeAlienShip(Spaceship*);

//Gère la liste chainée contenant les vaisseaux aliens

Spaceship *append(Spaceship* ship);
Spaceship *prepend(Spaceship* listAlien);
Spaceship* at(ManageGame *manager, Spaceship **ship, int);

void displayList(Spaceship listAlien);
void removeAt(Spaceship* ship, int index);

int size(Spaceship *ship);
enum bool isEmpty(Spaceship* ship);



struct SPACESHIP{

    // fonctions

    Spaceship *(*manageSpaceship)(ManageGame *, Spaceship*);       //référencement du prototype de pointeur de fonction (depuis le .h), vers la déclaration de la fonction (vers le .c)


    void (*disposeAlienShip)(Spaceship*);

    void (*moveLeft)(ManageGame*);
    void (*moveRight)(ManageGame*);
    void (*shoot)(Spaceship*);


    int  (*size)(Spaceship*);


    enum bool (*isEmpty)(Spaceship*);
    Spaceship (*append)(Spaceship*);
    Spaceship (*prepend)(Spaceship*);
    Spaceship (*at)(Spaceship**, int);

    void (*displayList)(Spaceship);
    void (*removeAt)(Spaceship*, int);





    // attribut
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
