#include "Spaceship.h"
#include "ManageGame.h"
typedef struct SPACESHIP Spaceship;

Spaceship *manageSpaceship(ManageGame *manager, Spaceship *ship){            //déclaration de fonction manageGame (qui sert de constructeur pour la struct ManageGame, aka rassembler les fonctions d'initialisations ex: initSDL.
    manager->ship = ship;
    manager->ship->posX = SCREEN_WIDTH/2;
    manager->ship->posY = SCREEN_HEIGHT*0.7;
    return manager->ship;
}

void disposeAlienShip(ManageGame *manager){

    manager->s_surface_ship = SDL_LoadBMP("alien.bmp");
    SDL_DestroyTexture(manager->s_textShip);
    SDL_DestroyTexture(manager->s_textbg);



    SDL_QueryTexture(manager->s_textShip , NULL, NULL, &manager->ship->height, &manager->ship->width);

    manager->ship->width /= 4;
    manager->ship->height /= 4;

    //    SDL_Rect dest = { manager->ship->posX, manager->ship->posY, manager->ship->width, manager->ship->height};
    SDL_Rect dest = { 0, manager->ship->posY, manager->ship->width, manager->ship->height};
    SDL_Log("%d", manager->ship->posX);
    SDL_RenderCopy(manager->s_renderer, manager->s_textShip , NULL, &dest);
    SDL_RenderPresent(manager->s_renderer);
    for (int i = 0; i < 1; i++){

        dest.x -= 10;
        manager->ship->posX -= 10;
        reloadScreen(manager);
        manager->s_textShip  = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface_ship);
        SDL_QueryTexture(manager->s_textShip , NULL, NULL, &manager->ship->height, &manager->ship->width);
        SDL_RenderCopy(manager->s_renderer, manager->s_textShip , NULL, &dest);
        SDL_RenderPresent(manager->s_renderer);
        SDL_DestroyTexture(manager->s_textShip );
        //        checkSDLTools(*manager, WINDOW_TOOL_SDL);

        SDL_DestroyTexture(manager->s_textShip);
        SDL_DestroyTexture(manager->s_textbg);
    }
}

void moveLeft(ManageGame *manager){

    manager->s_surface_ship = SDL_LoadBMP("spaceship.bmp");
    SDL_DestroyTexture(manager->s_textShip);
    SDL_DestroyTexture(manager->s_textbg);

    manager->s_textShip = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface_ship);
    SDL_QueryTexture(manager->s_textShip , NULL, NULL, &manager->ship->height, &manager->ship->width);

    manager->ship->width /= 4;
    manager->ship->height /= 4;

    SDL_Rect dest = { manager->ship->posX, manager->ship->posY, manager->ship->width, manager->ship->height};
    SDL_RenderCopy(manager->s_renderer, manager->s_textShip , NULL, &dest);
    SDL_RenderPresent(manager->s_renderer);

    for (int i = 0; i < 1; i++){

        dest.x -= 10;
        manager->ship->posX -= 10;
        reloadScreen(manager);
        manager->s_textShip  = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface_ship);
        SDL_QueryTexture(manager->s_textShip , NULL, NULL, &manager->ship->height, &manager->ship->width);
        SDL_RenderCopy(manager->s_renderer, manager->s_textShip , NULL, &dest);
        SDL_RenderPresent(manager->s_renderer);
        SDL_DestroyTexture(manager->s_textShip );
        //        checkSDLTools(*manager, WINDOW_TOOL_SDL);

        SDL_DestroyTexture(manager->s_textShip);
        SDL_DestroyTexture(manager->s_textbg);
    }
}

void moveRight(ManageGame* manager){

    manager->s_surface_ship = SDL_LoadBMP("spaceship.bmp");
    manager->s_textShip = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface_ship);
    SDL_QueryTexture(manager->s_textShip , NULL, NULL, &manager->ship->width, &manager->ship->height);
    manager->ship->width = manager->ship->width/4;
    manager->ship->height = manager->ship->height/4;

    SDL_Rect dest = { manager->ship->posX, manager->ship->posY, manager->ship->width, manager->ship->height};
    SDL_RenderCopy(manager->s_renderer, manager->s_textShip , NULL, &dest);
    SDL_RenderPresent(manager->s_renderer);

    for (int i = 0; i < 1; i++){
        dest.x += 10;
        manager->ship->posX += 10;
        reloadScreen(manager);
        manager->s_textShip  = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface_ship);
        SDL_QueryTexture(manager->s_textShip , NULL, NULL, &manager->ship->width, &manager->ship->height);
        SDL_RenderCopy(manager->s_renderer, manager->s_textShip , NULL, &dest);
        if (manager->s_renderer){
            SDL_RenderPresent(manager->s_renderer);
        }
        SDL_DestroyTexture(manager->s_textShip );
        SDL_DestroyTexture(manager->s_textbg);
    }
}

void shoot(Spaceship* listAlien){

}

// GESTION DE LA LISTE CHAINEE






Spaceship *prepend(Spaceship *listAlien, ManageGame *list)
{
    Spaceship *newShip = malloc (sizeof (Spaceship));
    newShip->nextShip = NULL;

    if(listAlien == NULL)
    {
        /* Si la liste est videé il suffit de renvoyer l'élément créé */
        return newShip;
    }
    else
    {
        /* Sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on
        indique que le dernier élément de la liste est relié au nouvel élément */
        Spaceship* temp = listAlien;
        while(temp->nextShip != NULL)
        {
            temp = temp->nextShip;
        }
        temp->nextShip = newShip;
        return listAlien;
    }
}






