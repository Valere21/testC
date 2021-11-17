#include "Spaceship.h"
#include "manageGame.h"
typedef struct SPACESHIP Spaceship;



Spaceship manageSpaceship(Spaceship *managerSpaceship){            //déclaration de fonction manageGame (qui sert de constructeur pour la struct ManageGame, aka rassembler les fonctions d'initialisations ex: initSDL.
    if (managerSpaceship == NULL) managerSpaceship = malloc(sizeof (Spaceship));
    generateList(managerSpaceship);
    return *managerSpaceship;
}

void disposeAlienShip(Spaceship *managerSpaceship){


}

void generateList(Spaceship *managerSpaceship){

    for (int i = 0; i < 20; i++){
        Spaceship *newShip = NULL;
        newShip = malloc(sizeof (Spaceship));
        SDL_Log("%p ",&managerSpaceship->listSpaceship[i]);
        managerSpaceship->listSpaceship[i] = *newShip;
    }
}








