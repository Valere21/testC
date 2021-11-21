#include <stdio.h>
#include "SDL.h"
#include "conio.h"
#include "Spaceship.h"
#include "ManageGame.h"
//#include "manageGame.c"

typedef struct MANAGEGAME ManageGame;
typedef struct VAISSEAU Vaisseau;

int main(int argc, char** argv)
{
    ManageGame manager;                             //nouvelle structure ManageGame
    manager.generateList = &generateList;
    manager.manageGame = &manageGame; //référencement du prototype de pointeur de fonction (depuis le .h), vers la déclaration de la fonction (vers le .c)    manager.loopGame = &loopGame;
    manager.loadPicture = &loadPicture;
    manager.loadAlien = &loadAlien;
    manager.loadSpaceship = &loadSpaceship;
    manager.loadBackground = &loadBackground;
    manager.erasePicture = &erasePicture;
    manager.reloadScreen = &reloadScreen;
    manager.update = &update;

    manager.add = &add;
    manager.delete = &delete;
    manager.isEmpty = &isEmpty;


    Spaceship ship;
    ship.manageSpaceship = &manageSpaceship;
    ship.disposeAlienShip = &disposeAlienShip;
    ship.shoot = &shoot;
    ship.moveLeft = &moveLeft;
    ship.moveRight = &moveRight;

    manager = manager.manageGame(&manager);                    //initialisation de la nouvelle structure
    manager.ship = manageSpaceship(&manager, &ship);
    manager.update(&manager);

    SDL_Quit();

    return 0;
}
