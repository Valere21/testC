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
    int a =  argc;
    a = 0;

    char **b = argv;
    *b = 0;
    const int value = 5;
    Spaceship spaceship;

    spaceship.manageSpaceship = &manageSpaceship;
    spaceship.disposeAlienShip = &disposeAlienShip;

    spaceship.shoot = &shoot;
    spaceship.moveLeft = &moveLeft;
    spaceship.moveRight = &moveRight;

    ManageGame manager;     //nouvelle structure ManageGame

    manager.generateList = &generateList;
    manager.manageGame = &manageGame; //référencement du prototype de pointeur de fonction (depuis le .h), vers la déclaration de la fonction (vers le .c)    manager.loopGame = &loopGame;
    manager.loadPicture = &loadPicture;
    manager.loadAlien = &loadAlien;
    manager.loadSpaceship = &loadSpaceship;
    manager.loadBackground = &loadBackground;
    manager.erasePicture = &erasePicture;
    manager.reloadScreen = &reloadScreen;
    manager.update = &update;


//    ManageInfo managerInfo;



    SDL_Log("Hello");
    manager = manager.manageGame(&manager);                    //initialisation de la nouvelle structure
//    manager.managerInfo->manageInfo = &manageInfo;
    spaceship = *spaceship.manageSpaceship(&spaceship);
    manager.update();
    SDL_Quit();

    return 0;
}
