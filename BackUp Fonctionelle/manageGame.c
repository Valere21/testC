#include <stdio.h>
#include "ManageGame.h"

typedef struct MANAGEGAME ManageGame;
typedef struct MANAGEINFO ManageInfo;


void reloadScreen(ManageGame* manager, SDL_Rect *itemToMove){

    manager->s_surface = SDL_LoadBMP("bg.bmp");
    manager->managerInfo->checkSDLTools(*manager, WINDOW_TOOL_SDL);

    manager->s_textbg = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface);
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
    //    SDL_Rect dest = { 640/2, 480/2, largeur, longueur};
    SDL_Rect dest = { rect->x, rect->y, rect->w, rect->h};
    SDL_RenderCopy(manager->s_renderer, manager->s_textShip, NULL, &dest);
    SDL_RenderPresent(manager->s_renderer);

    //    SDL_Delay(500);
}


void loadAlien(ManageGame *manager, int pictureFlag){

    SDL_Log("OK");

    manager->s_surface = SDL_LoadBMP("alien.bmp");

    manager->s_textShip = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface);
    int largeur;
    int longueur;
    SDL_QueryTexture(manager->s_textShip, NULL, NULL, &largeur, &longueur);
    largeur = largeur/4;
    longueur = longueur/4;
    SDL_Rect dest = { 640/2, 480/2, largeur, longueur};
    SDL_RenderCopy(manager->s_renderer, manager->s_textShip, NULL, &dest);
    SDL_RenderPresent(manager->s_renderer);


}

void loadSpaceship(ManageGame *manager, int pictureFlag){


//    SDL_Surface *alien = SDL_LoadBMP("spaceship.bmp");
    manager->s_surface_ship = SDL_LoadBMP("spaceship.bmp");
    manager->managerInfo->checkSDLTools(*manager, SURFACE_TOOL_SDL);





//    SDL_Texture *alien_texture = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface);
    manager->s_textShip = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface_ship);

    int largeur;
    int longueur;
    SDL_QueryTexture(manager->s_textShip , NULL, NULL, &largeur, &longueur);
    largeur = largeur/4;
    longueur = longueur/4;
//    SDL_Rect dest = { 150, 150, largeur, longueur};
    SDL_Rect dest = { manager->ship->posX, manager->ship->posY, largeur, longueur};
    SDL_RenderCopy(manager->s_renderer, manager->s_textShip , NULL, &dest);
    SDL_RenderPresent(manager->s_renderer);

    for (int i = 0; i < 25; i++){

        dest.x += 10;
        //        erasePicture(manager,&dest);
        reloadScreen(manager,&dest);
        //        SDL_Surface *alien = SDL_LoadBMP("alien.bmp");
        manager->s_textShip  = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface_ship);
        SDL_QueryTexture(manager->s_textShip , NULL, NULL, &largeur, &longueur);
        SDL_RenderCopy(manager->s_renderer, manager->s_textShip , NULL, &dest);
        SDL_RenderPresent(manager->s_renderer);
                SDL_DestroyTexture(manager->s_textShip );
                manager->managerInfo->checkSDLTools(*manager, WINDOW_TOOL_SDL);
//                manager->managerInfo->checkSDLTools(*manager, SURFACE_TOOL_SDL);
//                manager->managerInfo->checkSDLTools(*manager, TEXTURE_TOOL_SDL);
    }

}

void loadBackground(ManageGame *manager, int flag){


    manager->level = 8;
    fprintf(stdout,"Level %d \n", manager->level);

    if (flag == FULL_BACKGROUND)
        manager->s_window = SDL_CreateWindow("Appli test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_FULLSCREEN_DESKTOP);

    else if (flag == MINIMIZE_BACKGROUND)
        manager->s_window = SDL_CreateWindow("Appli test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);


    manager->managerInfo->checkSDLTools(*manager, WINDOW_TOOL_SDL);


    manager->s_renderer = SDL_CreateRenderer(manager->s_window, -1, SDL_RENDERER_TARGETTEXTURE);


    SDL_Rect dest = { 0, 0, 640, 480};

    manager->s_surface = SDL_LoadBMP("bg.bmp");
    manager->managerInfo->checkSDLTools(*manager, SURFACE_TOOL_SDL);


    manager->s_textbg = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface);
    SDL_FreeSurface(manager->s_surface);

    manager->managerInfo->checkSDLTools(*manager, TEXTURE_TOOL_SDL);


    if (SDL_QueryTexture(manager->s_textbg, NULL, NULL, &dest.w, &dest.h) != 0){
        SDL_Log("ERREUR > %s \n", SDL_GetError());
        cleanRessources(manager->s_window, manager->s_renderer, manager->s_textbg);
    }

    //    checkSDLTools(manager, RENDERER_TOOL_SDL);

    if (SDL_RenderCopy(manager->s_renderer, manager->s_textbg, NULL, NULL) != 0){
        SDL_Log("ERREUR > %s \n", SDL_GetError());
        cleanRessources(manager->s_window, manager->s_renderer, manager->s_textbg);
    }


    SDL_RenderPresent(manager->s_renderer);

    //    SDL_Delay(1000);
    //    cleanRessources(manager.s_window, manager.s_renderer, manager.s_textbg);

    displayInfo(manager);
}
void loadPicture(ManageGame *manager, int type, int flag){


    if (type == Background)
        loadBackground(manager, flag);
    if (type == Ship)
        loadSpaceship(manager, flag);
    if (type == Alien)
        loadAlien(manager, flag);
}


ManageGame initSDL(ManageGame manager){

    manager.s_window = NULL;
    manager.s_surface = NULL;
    manager.s_renderer = NULL;

    manager.s_textbg = NULL;
    manager.s_textShip = NULL;
    manager.s_textAlien = NULL;


    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        cleanRessources(NULL,NULL,NULL);
    }

    return manager;
}

ManageGame manageGame(ManageGame *manager){            //déclaration de fonction manageGame (qui sert de constructeur pour la struct ManageGame, aka rassembler les fonctions d'initialisations ex: initSDL.
    //Fonction quoi DOIT être appellé juste après chaque nouvelle instanciation, on est pas en C++.

    manager->managerInfo = manageInfo(manager->managerInfo);
    manager->ship = malloc(sizeof (Spaceship));
    manager->ship->posX = 640/2;
    manager->ship->posY = 480*0.8;

    initSDL(*manager);


    printf("hello world \n");
    loadPicture(manager, Background, MINIMIZE_BACKGROUND);
    fprintf(stdout,"Window %p \n", manager->s_window);
    loadSpaceship(manager,spawnSpaceship);


    return *manager;
}


ManageGame loopGame(ManageGame *manager){                            //Boucle de jeu

    SDL_Event events;
    enum bool isOpen = { true };
    while (isOpen)
    {
        while (SDL_PollEvent(&events))      //Boucle d'événements
        {
            switch( events.type )
            {
            case SDL_QUIT:isOpen = false;   //Quit event
                break;
            }
        }
    }
    return *manager;
}

void generateList(ManageGame *manager){

    //    managerSpaceship->listSpaceship = NULL;
    manager->listAlienSpaceship = malloc(sizeof (Spaceship));

    SDL_Log("create list");
    for (int i = 0; i < 20; i++){
        Spaceship *newShip; {};
        newShip = malloc(sizeof (Spaceship));
        manager->listAlienSpaceship[i] = *newShip;
        SDL_Log("%", &manager->listAlienSpaceship[i]);
    }
}

void update(){
    {
        SDL_Log("Update");
        SDL_Delay(1000);
        SDL_Event *events = NULL;
        events = malloc(sizeof (SDL_Event));
        SDL_bool run = SDL_TRUE;

        while (run && events != NULL) {
            while (SDL_PollEvent(events) && events){
                switch(events->type){
                case SDL_WINDOWEVENT:
                    if (events->window.event == SDL_WINDOWEVENT_CLOSE)
                        run = SDL_FALSE;
                    break;
                case SDL_KEYUP:{
                    SDL_Log("Up");
                    break;
                }
                }
            }
        }
    }
}





// Vielle version du load spaceship

//void loadSpaceship(ManageGame *manager, int pictureFlag){

//    if (manager->s_window == NULL) SDL_Log("NULL + %d", pictureFlag);

//    SDL_Log("Window %p", manager->s_window);
//    manager->managerInfo->checkSDLTools(*manager, WINDOW_TOOL_SDL);

//    SDL_Rect dest = { 0,   0, 640, 480};

//    manager->s_surface = SDL_LoadBMP("spaceship.bmp");
//    manager->managerInfo->checkSDLTools(*manager, SURFACE_TOOL_SDL);

//    manager->s_textbg = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface);
//    SDL_FreeSurface(manager->s_surface);

//    manager->managerInfo->checkSDLTools(*manager, TEXTURE_TOOL_SDL);


//    if (SDL_QueryTexture(manager->s_textbg, NULL, NULL, &dest.w, &dest.h) != 0){
//        SDL_Log("ERREUR > %s \n", SDL_GetError());
//        cleanRessources(manager->s_window, manager->s_renderer, manager->s_textbg);
//    }

//    if (SDL_RenderCopy(manager->s_renderer, manager->s_textbg, NULL, NULL) != 0){
//        SDL_Log("ERREUR > %s \n", SDL_GetError());
//        cleanRessources(manager->s_window, manager->s_renderer, manager->s_textbg);
//    }


//    SDL_RenderPresent(manager->s_renderer);

//    SDL_Delay(2000);

//    fprintf(stdout,"great \n");
//    int *w = NULL;
//    int *h = NULL;
//    w = malloc(sizeof (int));
//    *w = 2000;
//    h = malloc(sizeof (int));
//    *h = 200;

//    SDL_QueryTexture(manager->s_textbg, NULL, NULL, w, h);
//    SDL_RenderCopy(manager->s_renderer, manager->s_textbg, &dest, NULL);
//    SDL_RenderPresent(manager->s_renderer);

//}


//Icone

//    SDL_Texture* pTexture = SDL_CreateTexture(manager.s_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 100, 100);

//    SDL_SetRenderTarget(manager.s_renderer, pTexture);

//    SDL_Surface* surface = SDL_CreateRGBSurface(0, 32, 32, 32, 0, 0, 0, 0);
//    SDL_Rect dst = { 0, 0, 32, 32 };


//    SDL_FillRect(surface, &dst, SDL_MapRGBA(surface->format, 0, 0, 255, 255));
//    SDL_SetWindowIcon( manager.s_window, surface);


//    SDL_SetRenderDrawColor(manager.s_renderer, 0, 0, 0, 255);
//    SDL_RenderClear(manager.s_renderer);



// Dessin

//    SDL_SetRenderDrawBlendMode(manager.s_renderer, SDL_BLENDMODE_ADD);

//    SDL_Point point = { 800 / 2, 600 / 2};
//    SDL_Point point2 = { 800 / 3, 600 / 2};
//    SDL_Point point3 = { 800 / 4, 600 / 2};

//    SDL_Rect rectangle = { 800/ 2, 650 / 2, 300, 100 };
//    rectangle.x = 800 / 2 - rectangle.w / 2;
//    rectangle.y = 650 / 2 - rectangle.h / 2;

//    SDL_Rect rectangle2 = { 800/ 2, 0, 30, 600 };
//    rectangle2.x = 800 / 2 - rectangle2.w / 2;


//    SDL_SetRenderDrawColor(manager.s_renderer, 4, 2, 42, 255); // On choisis la couleur de remplissage de la fenêtre (ici noir)
//    SDL_RenderClear(manager.s_renderer); // On colorie toutes notre fenêtre en noir


//    SDL_SetRenderDrawColor(manager.s_renderer, 255, 25, 25, 255);
//    SDL_RenderDrawLine(manager.s_renderer, 0, 0, 800, 600);
//    SDL_RenderDrawLine(manager.s_renderer, 0, 600, 800, 0);


//    SDL_SetRenderDrawColor(manager.s_renderer, 45, 11, 45, 200);
//    SDL_RenderFillRect(manager.s_renderer, &rectangle);

//    SDL_SetRenderDrawColor(manager.s_renderer, 11, 25, 66, 200);
//    SDL_RenderFillRect(manager.s_renderer, &rectangle2);



//    SDL_SetRenderDrawColor(manager.s_renderer, 255, 0, 0, 255); // On choisis la couleur rouge
//    SDL_RenderDrawPoint(manager.s_renderer, 250, 65);
//    SDL_RenderDrawPoint(manager.s_renderer, point2.x, point2.y); // On dessiner un point
//    SDL_RenderDrawPoint(manager.s_renderer, point3.x, point3.y); // On dessiner un point
//    SDL_RenderDrawPoint(manager.s_renderer, point.x, point.y); // On dessiner un point

//    SDL_RenderPresent(manager.s_renderer); // On mets a jour notre fenêtre

//    SDL_Rect rectangleResult;
//    SDL_bool flag;
//    flag = SDL_IntersectRect(&rectangle, &rectangle2, &rectangleResult);
//    if (flag == SDL_TRUE) printf("valeur flag true \n");
//    else printf("valeur flag false \n");
//    printf("%p\n", &rectangleResult);

//    SDL_SetRenderDrawColor(manager.s_renderer, 150, 255, 0, 100);
//    SDL_RenderFillRect(manager.s_renderer, &rectangleResult);
//    SDL_RenderPresent(manager.s_renderer); // On mets a jour notre fenêtre

