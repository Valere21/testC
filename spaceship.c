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

    managerSpaceship->listSpaceship = malloc(sizeof (Spaceship));
    Spaceship newShip;
    managerSpaceship->listSpaceship[1] = newShip;



    SDL_Log("%p 1",&managerSpaceship->listSpaceship);
    SDL_Log("%p 2",&managerSpaceship->listSpaceship[1]);

    if (managerSpaceship->listSpaceship){
        managerSpaceship->listSpaceship = NULL;
        managerSpaceship->listSpaceship = malloc(sizeof (Spaceship));
    }

    free (managerSpaceship->listSpaceship);


    //    for (int i = 0; i < 20; i++){
    //        if (&managerSpaceship->listSpaceship[i] == NULL){
    //            SDL_Log("HHHHHHELO0");
    //            Spaceship *newSpaceship = NULL;
    //            newSpaceship = malloc(sizeof (Spaceship));
    //            SDL_Log("%d", i);
    //            managerSpaceship->listSpaceship[i] = *newSpaceship;
    //            SDL_Log("%p", &managerSpaceship->listSpaceship[i]);
    //        }
    //    }



}








