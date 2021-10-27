#include <stdio.h>
#include "manageGame.h"


typedef struct MANAGEGAME ManageGame;


void loadbackground(ManageGame manager){

    manager.s_window = SDL_CreateWindow("SDL Programme", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    manager.s_renderer = SDL_CreateRenderer(manager.s_window, -1, SDL_RENDERER_ACCELERATED);

    manager.s_galaxyBackground = SDL_LoadBMP("galaxyBackground.bmp");


    //////////////////////////////
    SDL_SetRenderDrawBlendMode(manager.s_renderer, SDL_BLENDMODE_ADD);

    SDL_Point point = { 800 / 2, 600 / 2};
    SDL_Point point2 = { 800 / 3, 600 / 2};
    SDL_Point point3 = { 800 / 4, 600 / 2};

    SDL_Rect rectangle = { 800/ 2, 650 / 2, 300, 100 };
    rectangle.x = 800 / 2 - rectangle.w / 2;
    rectangle.y = 650 / 2 - rectangle.h / 2;

    SDL_Rect rectangle2 = { 800/ 2, 0, 30, 600 };
    rectangle2.x = 800 / 2 - rectangle2.w / 2;


    SDL_SetRenderDrawColor(manager.s_renderer, 4, 2, 42, 255); // On choisis la couleur de remplissage de la fenêtre (ici noir)
    SDL_RenderClear(manager.s_renderer); // On colorie toutes notre fenêtre en noir


    SDL_SetRenderDrawColor(manager.s_renderer, 255, 25, 25, 255);
    SDL_RenderDrawLine(manager.s_renderer, 0, 0, 800, 600);
    SDL_RenderDrawLine(manager.s_renderer, 0, 600, 800, 0);


    SDL_SetRenderDrawColor(manager.s_renderer, 45, 11, 45, 200);
    SDL_RenderFillRect(manager.s_renderer, &rectangle);

    SDL_SetRenderDrawColor(manager.s_renderer, 11, 25, 66, 200);
    SDL_RenderFillRect(manager.s_renderer, &rectangle2);



    SDL_SetRenderDrawColor(manager.s_renderer, 255, 0, 0, 255); // On choisis la couleur rouge
    SDL_RenderDrawPoint(manager.s_renderer, 250, 65);
    SDL_RenderDrawPoint(manager.s_renderer, point2.x, point2.y); // On dessiner un point
    SDL_RenderDrawPoint(manager.s_renderer, point3.x, point3.y); // On dessiner un point
    SDL_RenderDrawPoint(manager.s_renderer, point.x, point.y); // On dessiner un point

    SDL_RenderPresent(manager.s_renderer); // On mets a jour notre fenêtre

    SDL_Rect rectangleResult;
    SDL_bool flag;
    flag = SDL_IntersectRect(&rectangle, &rectangle2, &rectangleResult);
    if (flag == SDL_TRUE) printf("valeur flag true \n");
    else printf("valeur flag false \n");
    printf("%p\n", &rectangleResult);


    SDL_SetRenderDrawColor(manager.s_renderer, 150, 255, 0, 100);
    SDL_RenderFillRect(manager.s_renderer, &rectangleResult);
    SDL_RenderPresent(manager.s_renderer); // On mets a jour notre fenêtre

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

    //////////////////////////////



    //    SDL_SetWindowFullscreen(manager.s_galaxyBackground,SDL_WINDOW_FULLSCREEN);
    if (manager.s_galaxyBackground)
    {
        SDL_Rect rect = {100, 100, 100, 100}, dest = {0, 0, 0, 0};

        SDL_BlitSurface(manager.s_galaxyBackground,NULL,SDL_GetWindowSurface(manager.s_window),&dest); // Copie du sprite

        SDL_UpdateWindowSurface(manager.s_window); // Mise à jour de la fenêtre pour prendre en compte la copie du sprite
        SDL_Delay(2000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */

        //        SDL_FreeSurface(manager.s_galaxyBackground); // Libération de la ressource occupée par le sprite

    }
}


int initSDL(ManageGame manager){

    int codeError = 0;

    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        codeError = -1;
    }

    loadbackground(manager);

    return codeError;
}



void loopGame(){                            //Boucle de jeu

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
}



ManageGame manageGame(ManageGame manager){            //déclaration de fonction manageGame (qui sert de constructeur pour la struct ManageGame, aka rassembler les fonctions d'initialisations ex: initSDL.
    //Fonction quoi DOIT être appellé juste après chaque nouvelle instanciation, on est pas en C++.
    printf("hello world \n");
    initSDL(manager);

    return manager;
}






