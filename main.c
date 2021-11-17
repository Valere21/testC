#include <stdio.h>
#include "SDL.h"
#include "conio.h"
#include "Spaceship.h"
#include "manageGame.h"
//#include "manageGame.c"

typedef struct MAP Map;
typedef struct MANAGEGAME ManageGame;
typedef struct VAISSEAU Vaisseau;

struct MAP{
    int sizeMapXY[2];
    int posVsXY[2];
    char map[100][100];
};


enum posColLigne { col, ligne};

Map map(){
    Map map = {{100,100},{125,100},{}};
    return map;
}


int getSizeMap(Map map){

    for (int i =0; i < map.sizeMapXY[1]; i++){

    }


}

void drawMap(Map map){

    for (int i = 0; i < map.sizeMapXY[col]; i++){
        printf("");
    }

    for (int i =0; i < map.sizeMapXY[ligne]; i++){
        for (int j = 0; j < map.sizeMapXY[col]; j++){
            if (j == 0 || j == map.sizeMapXY[col]){
                //                printf("%*d", (i*j), '.');
                printf ("%-10s%5s*%15d*%25d\n","one","two", i, j);
                //                _printf_p("%1$s %2$s", "November", "10");
                //                printf("%1s", "%c", (char)i, '.');
                //                  printf("%1%c", (char)x);
                //"s\n", ".");
            }
        }
    }
}

int printVal(int i)
{
    printf("%d\n", i);
    return i;
}
void getInput(){

    int frappe;
    while(!kbhit())
    {
        frappe=getch();
        if(frappe=='d')
        {
            printf ("d");
        }
        else
            break;
    }
}

int main(int argc, char** argv)
{
    int a =  argc;
    a = 0;

    char **b = argv;
    *b = 0;

    Spaceship spaceship;

    spaceship.manageSpaceship = &manageSpaceship;
    spaceship.generateList = &generateList;
    spaceship.disposeAlienShip = &disposeAlienShip;

    ManageGame manager;                             //nouvelle structure ManageGame

    manager.manageGame = &manageGame; //référencement du prototype de pointeur de fonction (depuis le .h), vers la déclaration de la fonction (vers le .c)    manager.loopGame = &loopGame;
    manager.loadPicture = &loadPicture;
    manager.loadAlien = &loadAlien;
    manager.loadSpaceship = &loadSpaceship;
    manager.loadBackground = &loadBackground;
    manager.erasePicture = &erasePicture;
    manager.reloadScreen = &reloadScreen;

    manager = manager.manageGame(&manager);                    //initialisation de la nouvelle structure
    spaceship = spaceship.manageSpaceship(&spaceship);

    getInput();

    Map carte = map();
    drawMap(carte);

    //    Vaisseau va = vaisseau();
    //    Vaisseau vb = vaisseau();

    getInput();
    SDL_Quit();

    return 0;
}
