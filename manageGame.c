#include <stdio.h>
#include "manageGame.h"


typedef struct MANAGEGAME ManageGame;


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
    if (tool == windowTool){
        if (manager.s_window== NULL){
            SDL_Log("ERREUR > %s\n", SDL_GetError());
            cleanRessources(manager.s_window, NULL, NULL);
        }
    }
    if (tool == surfaceTool){
        if (manager.s_surface == NULL){
            SDL_Log("ERREUR > %s\n", SDL_GetError());
            cleanRessources(manager.s_window, manager.s_renderer, NULL);
        }
    }
    if (tool == textureTool){
        if (manager.s_texture == NULL){
            SDL_Log("ERREUR > %s\n", SDL_GetError());
            cleanRessources(manager.s_window, manager.s_renderer, NULL);
        }
    }
}

void loadSpaceship(ManageGame manager, int pictureFlag){

}

void loadAlien(ManageGame manager, int pictureFlag){


}

void loadbackground(ManageGame manager, int flag){

    if (flag == fullBackground)
        manager.s_window = SDL_CreateWindow("Appli test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_FULLSCREEN_DESKTOP);

    else if (flag == minimizeBackground)
        manager.s_window = SDL_CreateWindow("Appli test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

    checkSDLTools(manager, windowTool);


    manager.s_renderer = SDL_CreateRenderer(manager.s_window, -1, SDL_RENDERER_TARGETTEXTURE);


    SDL_Rect dest = { 0, 0, 640, 480};

    manager.s_surface = SDL_LoadBMP("bg.bmp");
    //    manager.s_textAlien = SDL_LoadBMP("alien.bmp");
    //    manager.s_textAlien = SDL_LoadBMP("alien.bmp");


    checkSDLTools(manager, surfaceTool);


    manager.s_texture = SDL_CreateTextureFromSurface(manager.s_renderer, manager.s_surface);
    SDL_FreeSurface(manager.s_surface);

    checkSDLTools(manager, textureTool);


    if (SDL_QueryTexture(manager.s_texture, NULL, NULL, &dest.w, &dest.h) != 0){
        SDL_Log("ERREUR > %s \n", SDL_GetError());
        cleanRessources(manager.s_window, manager.s_renderer, manager.s_texture);
    }

    if (SDL_RenderCopy(manager.s_renderer, manager.s_texture, NULL, NULL) != 0){
        SDL_Log("ERREUR > %s \n", SDL_GetError());
        cleanRessources(manager.s_window, manager.s_renderer, manager.s_texture);
    }


    SDL_RenderPresent(manager.s_renderer);
    SDL_Delay(5000);

    cleanRessources(manager.s_window, manager.s_renderer, manager.s_texture);

    //////////////////////////////




    SDL_RendererInfo infoRenderer;
    SDL_GetRendererInfo(manager.s_renderer, &infoRenderer);

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

}
void loadPicture(ManageGame manager, int type, int flag){


    if (type == Background)
        loadbackground(manager, flag);
    if (type == Spaceship)
        loadSpaceship(manager, flag);
    if (type == Alien)
        loadAlien(manager, flag);
}



ManageGame initSDL(ManageGame manager){


    manager.s_window = NULL;
    manager.s_surface = NULL;
    manager.s_renderer = NULL;

    manager.s_texture = NULL;
    manager.s_textShip = NULL;
    manager.s_textAlien = NULL;;


    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        cleanRessources(NULL,NULL,NULL);
    }

    return manager;
}



ManageGame loopGame(ManageGame manager){                            //Boucle de jeu

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
    return manager;

}



ManageGame manageGame(ManageGame manager){            //déclaration de fonction manageGame (qui sert de constructeur pour la struct ManageGame, aka rassembler les fonctions d'initialisations ex: initSDL.
    //Fonction quoi DOIT être appellé juste après chaque nouvelle instanciation, on est pas en C++.
    printf("hello world \n");
    manager = initSDL(manager);
    loadPicture(manager, Background, minimizeBackground);
    loadPicture(manager, Spaceship, spawnSpaceship);
    loadPicture(manager, Alien, setupAlienSpaceship);
    return manager;


}




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



