  #include "Spaceship.h"
#include "ManageGame.h"
typedef struct SPACESHIP Spaceship;

Spaceship *manageSpaceship(ManageGame *manager, Spaceship *ship){            //déclaration de fonction manageGame (qui sert de constructeur pour la struct ManageGame, aka rassembler les fonctions d'initialisations ex: initSDL.
    manager->ship = ship;
//    if (managerSpaceship == NULL) managerSpaceship = malloc(sizeof (Spaceship));
//    generateList(managerSpaceship);
    return manager->ship;
}

void disposeAlienShip(Spaceship *managerSpaceship){

}

void moveLeft(ManageGame *manager){

    SDL_Log("Left");


        manager->s_surface_ship = SDL_LoadBMP("spaceship.bmp");
//        manager->checkSDLTools(*manager, SURFACE_TOOL_SDL);

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

        for (int i = 0; i < 2; i++){

            dest.x -= 10;
            manager->ship->posX -= 10;
            reloadScreen(manager,&dest);
            manager->s_textShip  = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface_ship);
            SDL_QueryTexture(manager->s_textShip , NULL, NULL, &largeur, &longueur);
            SDL_RenderCopy(manager->s_renderer, manager->s_textShip , NULL, &dest);
            SDL_RenderPresent(manager->s_renderer);
                    SDL_DestroyTexture(manager->s_textShip );
                    checkSDLTools(*manager, WINDOW_TOOL_SDL);

        }

}

void moveRight(ManageGame* manager){
    SDL_Log("Right");


        manager->s_surface_ship = SDL_LoadBMP("spaceship.bmp");
//        manager->checkSDLTools(*manager, SURFACE_TOOL_SDL);

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

        for (int i = 0; i < 2; i++){

            dest.x += 10;
            manager->ship->posX += 10;
            //        erasePicture(manager,&dest);
            reloadScreen(manager,&dest);
            //        SDL_Surface *alien = SDL_LoadBMP("alien.bmp");
            manager->s_textShip  = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface_ship);
            SDL_QueryTexture(manager->s_textShip , NULL, NULL, &largeur, &longueur);
            SDL_RenderCopy(manager->s_renderer, manager->s_textShip , NULL, &dest);
            SDL_RenderPresent(manager->s_renderer);
                    SDL_DestroyTexture(manager->s_textShip );
                    checkSDLTools(*manager, WINDOW_TOOL_SDL);

        }
}

void shoot(Spaceship* ship){

}













