#include "Spaceship.h"
#include "ManageGame.h"
typedef struct SPACESHIP Spaceship;

Spaceship *manageSpaceship(ManageGame *manager, Spaceship *ship){            //déclaration de fonction manageGame (qui sert de constructeur pour la struct ManageGame, aka rassembler les fonctions d'initialisations ex: initSDL.
    manager->ship = ship;
    manager->ship->posX = 640/2;
    manager->ship->posY = 480*0.7;
    return manager->ship;
}

void disposeAlienShip(Spaceship *managerSpaceship){

}

void moveLeft(ManageGame *manager){

    SDL_Log("Left");

    SDL_Log("SIZE %d", manager->size(manager));
    SDL_Log("EMPTY %d", manager->isEmpty(manager));

    manager->s_surface_ship = SDL_LoadBMP("spaceship.bmp");
    SDL_DestroyTexture(manager->s_textShip);
    SDL_DestroyTexture(manager->s_textbg);

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

    for (int i = 0; i < 2; i++){

        dest.x -= 10;
        manager->ship->posX -= 10;
        reloadScreen(manager,&dest);
        manager->s_textShip  = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface_ship);
        SDL_QueryTexture(manager->s_textShip , NULL, NULL, &largeur, &longueur);
        SDL_RenderCopy(manager->s_renderer, manager->s_textShip , NULL, &dest);
        SDL_RenderPresent(manager->s_renderer);
        SDL_DestroyTexture(manager->s_textShip );
//        checkSDLTools(*manager, WINDOW_TOOL_SDL);

        SDL_DestroyTexture(manager->s_textShip);
        SDL_DestroyTexture(manager->s_textbg);
    }

}

void moveRight(ManageGame* manager){
    SDL_Log("Right");


    manager->s_surface_ship = SDL_LoadBMP("spaceship.bmp");

    //        SDL_DestroyRenderer(manager->s_renderer);

    //  manager->checkSDLTools(*manager, SURFACE_TOOL_SDL);

    //    SDL_Texture *alien_texture = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface);

    manager->s_textShip = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface_ship);

    SDL_QueryTexture(manager->s_textShip , NULL, NULL, &manager->ship->width, &manager->ship->height);
    manager->ship->width = manager->ship->width/4;
    manager->ship->height = manager->ship->height/4;

    SDL_Log("pos y ship %d", manager->ship->posY);
    SDL_Log("adr ship %p", &manager->ship);



    SDL_Rect dest = { manager->ship->posX, manager->ship->posY, manager->ship->width, manager->ship->height};
    SDL_RenderCopy(manager->s_renderer, manager->s_textShip , NULL, &dest);
    SDL_RenderPresent(manager->s_renderer);

    for (int i = 0; i < 2; i++){

        dest.x += 10;
        manager->ship->posX += 10;
        reloadScreen(manager,&dest);
        manager->s_textShip  = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface_ship);
        SDL_QueryTexture(manager->s_textShip , NULL, NULL, &manager->ship->width, &manager->ship->height);
        SDL_RenderCopy(manager->s_renderer, manager->s_textShip , NULL, &dest);
        SDL_RenderPresent(manager->s_renderer);
        SDL_DestroyTexture(manager->s_textShip );
//        checkSDLTools(*manager, WINDOW_TOOL_SDL);

        SDL_DestroyTexture(manager->s_textShip);
        SDL_DestroyTexture(manager->s_textbg);
    }
}

void shoot(Spaceship* ship){

}













