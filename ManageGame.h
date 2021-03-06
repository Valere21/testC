#ifndef MANAGEGAME_H
#define MANAGEGAME_H
#include <Spaceship.h>
#include "ManageInfo.h"
#include "SDL.h"
#include <stdio.h>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

typedef struct MANAGEINFO ManageInfo;
typedef struct MANAGEGAME ManageGame;

enum direction {
    left = 0,
    right = 1
};

enum pictureType {
    Background,
    Ship,
    Alien
};

    enum flagPicture {

        FULL_BACKGROUND,
        MINIMIZE_BACKGROUND,
        RELOAD_BACKGROUND,
        setupAlienSpaceship,
        spawnSpaceship,
        respawnSpaceship,
        };

enum toolSDL{
    WINDOW_TOOL_SDL,
    RENDERER_TOOL_SDL,
    SURFACE_TOOL_SDL,
    TEXTURE_TOOL_SDL
};

enum level {
    niveau1,
    niveau2,
    niveau3,
    niveauInfini
};

enum bool {
    false = 0,
    true = 1
};


//Gère le jeu

ManageGame manageGame(ManageGame *manager);


ManageGame loopGame(ManageGame *manager);

//Gère la SDL et l'interface
void loadPicture(ManageGame *manager, int type, int flag);
void loadAlien(ManageGame *manager, int flag);
void loadSpaceship(ManageGame *manager, int type);
void loadBackground(ManageGame *manager, int type);
void erasePicture(ManageGame*, SDL_Rect*);

void reloadScreen(ManageGame*);
void reloadShip(ManageGame*);
void reloadAlienShip(ManageGame*);
void reverseAlienDirection(Spaceship *ship);

void update(ManageGame *manager);

////////// antoine //////////


Spaceship** generateSpaceshipList(int ship_numbeer);
Spaceship*  generateRawSpaceship(int id);
Spaceship *at(Spaceship *first, int index);

void append(Spaceship **list, Spaceship *ship);
void applyOnList(Spaceship *first, void (*f)(Spaceship *));
void displayList(Spaceship **list);

int size (Spaceship **list);
enum bool isEmpty (Spaceship **list);


////////// ////////// //////////


struct MANAGEGAME{

    // méthode

    ManageGame (*manageGame)(ManageGame*);       //rÃ©fÃ©rencement du prototype de pointeur de fonction (depuis le .h), vers la dÃ©claration de la fonction (vers le .c)
    ManageGame (*loopGame)();

    void (*update)(ManageGame*);
    void (*loadAlien)(ManageGame*, int);
    void (*loadSpaceship)(ManageGame*, int);
    void (*loadBackground)(ManageGame*, int);
    void (*loadPicture)(ManageGame*, int, int);
    void (*erasePicture)(ManageGame*, SDL_Rect*);

    void (*reloadScreen)(ManageGame*);
    void (*reloadShip)(ManageGame*);
    void (*reloadAlienShip)(ManageGame*);
    void (*reverseAlienDirection)(Spaceship*);

    ////////// antoine //////////


    Spaceship** (*generateSpaceshipList)(int);
    Spaceship*  (*generateRawSpaceship)(int);
    Spaceship* (*at)(Spaceship*, int);

    int (*size)(Spaceship**);
    enum bool (*isEmpty)(Spaceship**);

    void (*displayList)(Spaceship**);
    void (*append)(Spaceship**, Spaceship*);
    void (*applyOnList)(Spaceship*, void (*)(Spaceship*));

    ////////// ////////// //////////



    // attribut
    int level;
    int s_time_previous;
    int s_time_actual;


    ManageInfo *s_managerInfo;

    SDL_Window *s_window;
    SDL_Surface *s_surface;
    SDL_Surface *s_surface_ship;

    SDL_Renderer *s_renderer;

    SDL_Texture *s_textbg;
    SDL_Texture *s_textShip;
    SDL_Texture *s_textAlien;

    Spaceship *ship;
    Spaceship **listAlienShip;

};


#endif // MANAGEGAME_H
















