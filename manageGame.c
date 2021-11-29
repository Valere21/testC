#include <stdio.h>
#include "ManageGame.h"

typedef struct MANAGEGAME ManageGame;
typedef struct MANAGEINFO ManageInfo;

void cleanRessources(SDL_Window *w, SDL_Renderer *r, SDL_Texture *t){

    if (t != NULL)
        SDL_DestroyTexture(t);
    if (r != NULL)
        SDL_DestroyRenderer(r);
    if (w != NULL)
        SDL_DestroyWindow(w);
    SDL_Quit();
}

void checkSDLTools(ManageGame manager, int tool){

    switch (tool) {
    case WINDOW_TOOL_SDL:{
        if (manager.s_window == NULL){
            SDL_Log("ERREUR WINDOW > %s\n", SDL_GetError());
            cleanRessources(manager.s_window, NULL, NULL);
            free(manager.s_surface);
        }
        break;
    }

    case SURFACE_TOOL_SDL:{
        if (manager.s_surface == NULL){
            SDL_Log("ERREUR SURFACE > %s\n", SDL_GetError());
            cleanRessources(manager.s_window, manager.s_renderer, NULL);
        }
        break;
    }
    case TEXTURE_TOOL_SDL:{
        if (manager.s_textbg == NULL){
            SDL_Log("ERREUR TEXTURE > %s\n", SDL_GetError());
            cleanRessources(manager.s_window, manager.s_renderer, NULL);
        }
        break;
    }
    }
}

void displayInfo(ManageGame *manager){

    SDL_RendererInfo infoRenderer;
    SDL_GetRendererInfo(manager->s_renderer, &infoRenderer);

    if (infoRenderer.flags & SDL_RENDERER_ACCELERATED)
    {
        SDL_Log("Le rendu est gérer par la carte mère...");
    }
    if (infoRenderer.flags & SDL_RENDERER_SOFTWARE)
    {
        SDL_Log("Le rendu est gérer par la carte graphique...");
    }

    if (infoRenderer.flags & SDL_RENDERER_TARGETTEXTURE)
    {
        SDL_Log("Le rendu est autoriser sur des texture...");
    }

    fprintf(stdout,"Window bG %p \n", manager->s_window);

}

void reloadScreen(ManageGame* manager, SDL_Rect *itemToMove){

    manager->s_surface = SDL_LoadBMP("bg.bmp");
    checkSDLTools(*manager, WINDOW_TOOL_SDL);

    manager->s_textbg = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface);

    SDL_FreeSurface(manager->s_surface);
    checkSDLTools(*manager, TEXTURE_TOOL_SDL);

    SDL_RenderCopy(manager->s_renderer, manager->s_textbg, NULL, NULL);
    SDL_RenderPresent(manager->s_renderer);
}

void erasePicture(ManageGame *manager, SDL_Rect *rect){

    SDL_Log("erase");

    manager->s_surface = SDL_LoadBMP("bg.bmp");
    manager->s_textShip = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface);
    int largeur;
    int longueur;
    SDL_QueryTexture(manager->s_textShip, NULL, NULL, &largeur, &longueur);
    largeur = largeur/4;
    longueur = longueur/4;
    //    SDL_Rect dest = { SCREEN_WIDTH/2, SCREEN_HEIGHT/2, largeur, longueur};
    SDL_Rect dest = { rect->x, rect->y, rect->w, rect->h};
    SDL_RenderCopy(manager->s_renderer, manager->s_textShip, NULL, &dest);
    SDL_RenderPresent(manager->s_renderer);

    //    SDL_Delay(500);
}


void loadAlien(ManageGame *manager, int flag){

    manager->s_surface_ship = SDL_LoadBMP("spaceship.bmp");
    manager->s_textShip = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface_ship);
    SDL_QueryTexture(manager->s_textShip , NULL, NULL, &manager->listAlienSpaceship->width, &manager->listAlienSpaceship->height);
    manager->listAlienSpaceship->width = manager->listAlienSpaceship->width/4;
    manager->listAlienSpaceship->height = manager->listAlienSpaceship->height/4;

    SDL_Rect dest = { manager->listAlienSpaceship->posX, manager->listAlienSpaceship->posY, manager->listAlienSpaceship->width, manager->listAlienSpaceship->height};
    SDL_RenderCopy(manager->s_renderer, manager->s_textShip , NULL, &dest);
    SDL_RenderPresent(manager->s_renderer);

}

void loadSpaceship(ManageGame *manager, int pictureFlag){
    SDL_Log("ship %p", &manager->ship);

    manager->ship->moveLeft(manager);

}

void loadBackground(ManageGame *manager, int flag){


    manager->level = 8;
    fprintf(stdout,"Level %d \n", manager->level);

    if (flag == FULL_BACKGROUND)
        manager->s_window = SDL_CreateWindow("Appli test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);

    else if (flag == MINIMIZE_BACKGROUND)
        manager->s_window = SDL_CreateWindow("Appli test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);


    checkSDLTools(*manager, WINDOW_TOOL_SDL);


    manager->s_renderer = SDL_CreateRenderer(manager->s_window, -1, SDL_RENDERER_TARGETTEXTURE);


    SDL_Rect dest = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

    manager->s_surface = SDL_LoadBMP("bg.bmp");
    checkSDLTools(*manager, SURFACE_TOOL_SDL);


    manager->s_textbg = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface);
    SDL_FreeSurface(manager->s_surface);

    checkSDLTools(*manager, TEXTURE_TOOL_SDL);


    if (SDL_QueryTexture(manager->s_textbg, NULL, NULL, &dest.w, &dest.h) != 0){
        SDL_Log("ERREUR > %s \n", SDL_GetError());
        cleanRessources(manager->s_window, manager->s_renderer, manager->s_textbg);
    }

    //    checkSDLTools(manager, RENDERER_TOOL_SDL);

    if (SDL_RenderCopy(manager->s_renderer, manager->s_textbg, NULL, NULL) != 0){
        SDL_Log("ERREUR > %s \n", SDL_GetError());
        manager->s_managerInfo->cleanRessources(manager->s_window, manager->s_renderer, manager->s_textbg);
    }


    SDL_RenderPresent(manager->s_renderer);

    //    SDL_Delay(1000);
    //    cleanRessources(manager.s_window, manager.s_renderer, manager.s_textbg);

}
void loadPicture(ManageGame *manager, int type, int flag){


    if (type == Background)
        loadBackground(manager, flag);
    if (type == Ship)
        loadSpaceship(manager, flag);
    if (type == Alien)
        loadAlien(manager, flag);
}



ManageGame initSDL(ManageGame *manager){

    manager->s_window = NULL;
    manager->s_surface = NULL;
    manager->s_renderer = NULL;

    manager->s_textbg = NULL;
    manager->s_textShip = NULL;
    manager->s_textAlien = NULL;

    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        manager->s_managerInfo->cleanRessources(NULL,NULL,NULL);
    }
    return *manager;
}

ManageGame manageGame(ManageGame *manager){            //déclaration de fonction manageGame (qui sert de constructeur pour la struct ManageGame, aka rassembler les fonctions d'initialisations ex: initSDL.
    //Fonction quoi DOIT être appellé juste après chaque nouvelle instanciation, on est pas en C++.

    initSDL(manager);
    printf("hello world \n");
    loadPicture(manager, Background, MINIMIZE_BACKGROUND);

    manager->listAlienSpaceship = manager->generateList(manager);
    return *manager;
}


Spaceship *generateList(ManageGame *manager){

    manager->listAlienSpaceship = NULL;
    for (int i = 0; i < 20; i++){
        manager->listAlienSpaceship = manager->append(manager->listAlienSpaceship);
    }
    SDL_Log("addr 1 %p", manager->listAlienSpaceship);
    return manager->listAlienSpaceship;
}


Spaceship* append(Spaceship* listAlienSpaceship){

    Spaceship *newShip;
    newShip = malloc (sizeof (Spaceship));
    if (newShip){
        newShip->posX = SCREEN_WIDTH/2;
        newShip->posY = SCREEN_HEIGHT*0.2;
        newShip->Alife = true;
        newShip->width = SCREEN_WIDTH/4;
        newShip->height = SCREEN_HEIGHT/4;
        newShip->nextShip = listAlienSpaceship;
    }
    return newShip;
}

void displayList(Spaceship *listAlien)
{
    while(listAlien){
        SDL_Log("height %d", listAlien->height);
        SDL_Log("width %d", listAlien->width);
        listAlien = listAlien->nextShip;
    }
}

Spaceship* at(ManageGame *manager, int index){
    Spaceship *newShip = NULL;

    return newShip;
}



// GESTION DU JEU

void update(ManageGame *manager){
    {
        SDL_Delay(1000);
        //        SDL_Scancode *scanner = NULL;
        //        scanner = malloc(sizeof (SDL_Scancode));

        SDL_bool run = SDL_TRUE;

        while (run) {
            SDL_Event event /*= malloc(sizeof (SDL_Event))*/;


            manager->s_time_previous = SDL_GetTicks();
            if (manager->s_time_actual - manager->s_time_previous > 30) /* Si 30 ms se sont écoulées */
            {
                //                manager->ship->moveLeft(manager); /* On bouge Zozor */
            }


            while (SDL_PollEvent(&event)){
                switch(event.type){
                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_CLOSE){
                        run = SDL_FALSE;

                        cleanRessources(manager->s_window, manager->s_renderer, manager->s_textbg);
                        cleanRessources(NULL, NULL, manager->s_textShip);
                        break;
                    }
                }
                switch(event.key.keysym.sym){
                case SDLK_SPACE:{
                    SDL_Log("addr 2 %p", manager->listAlienSpaceship);
                    displayList(manager->listAlienSpaceship);
                    break;
                }
                case SDLK_LEFT:{
                    manager->ship->moveLeft(manager);
                    break;
                }
                case SDLK_RIGHT:{
                    manager->ship->moveRight(manager);
                    break;
                }
                case SDLK_ESCAPE:{
                    SDL_Log("Return 0");
                    run = SDL_FALSE;
                    break;
                }
                }
            }
        }
        manager->s_managerInfo->cleanRessources(manager->s_window, NULL, NULL);
        SDL_Quit();
    }
}










