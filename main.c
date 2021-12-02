#include <stdio.h>
#include "SDL.h"
#include "conio.h"
#include "Spaceship.h"
#include "ManageGame.h"
//#include "manageGame.c"

typedef struct MANAGEGAME ManageGame;
typedef struct SPACESHIP Spaceship;

int main(int argc, char** argv)
{
    ManageGame manager;                             //nouvelle structure ManageGame
    Spaceship ship;



    manager.manageGame = &manageGame; //référencement du prototype de pointeur de fonction (depuis le .h), vers la déclaration de la fonction (vers le .c)    manager.loopGame = &loopGame;

    manager.loadPicture = &loadPicture;
    manager.loadAlien = &loadAlien;
    manager.loadSpaceship = &loadSpaceship;
    manager.loadBackground = &loadBackground;
    manager.erasePicture = &erasePicture;
    manager.reloadShip = &reloadShip;
    manager.reloadScreen = &reloadScreen;
    manager.reloadAlienShip = &reloadAlienShip;

    manager.update = &update;

    manager.generateSpaceshipList = &generateSpaceshipList;
    manager.generateRawSpaceship = &generateRawSpaceship;
    manager.at = &at;
    manager.append = &append;
    manager.applyOnList = &applyOnList;
    manager.displayList = &displayList;
    manager.isEmpty = &isEmpty;
    manager.reverseAlienDirection = &reverseAlienDirection;
//    manager.size = &size;


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
