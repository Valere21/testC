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

    //    SDL_Log("Ship alien %p", manager->at(manager, 15));
    //    SDL_Log("Ship alien %p", manager->at(manager, 25));

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
    manager->s_textShip = SDL_CreateTextureFromSurface(manager->s_renderer, manager->s_surface_ship);
    SDL_QueryTexture(manager->s_textShip , NULL, NULL, &manager->ship->width, &manager->ship->height);
    manager->ship->width = manager->ship->width/4;
    manager->ship->height = manager->ship->height/4;

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

        SDL_DestroyTexture(manager->s_textShip);
        SDL_DestroyTexture(manager->s_textbg);
    }
}

void shoot(Spaceship* listAlien){

}

// GESTION DE LA LISTE CHAINEE


int size(Spaceship *ship){
    SDL_Log(("func size"));

    int index = 0;
    while(&ship[index] != NULL)
    {
        SDL_Log(("loop"));
        index++;
    }
    SDL_Log(("out"));
    return index;
}

enum bool isEmpty(Spaceship* listAlien){
    enum bool flag = false;
    if (listAlien){
        SDL_Log(("func isEmpty"));

        if (size(listAlien) == 0)
            flag = true;
    }
    else    {
        SDL_Log(("Not exisiting"));
    }
    return flag;
}

Spaceship* append(Spaceship* listAlien){

    SDL_Log(("Append"));

    Spaceship *newShip = malloc (sizeof (Spaceship));
    newShip->nextShip = listAlien;

    return listAlien;
}


Spaceship *prepend(Spaceship *listAlien)
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


void displayList(Spaceship listAlien)
{
    Spaceship *tmp = &listAlien;
    /* Tant que l'on n'est pas au bout de la liste */
    while(tmp != NULL)
    {
        /* On affiche */
        SDL_Log("%p", tmp);
        /* On avance d'une case */
        tmp = tmp->nextShip;
    }
}

Spaceship* at(ManageGame *manager, Spaceship** ship, int index){
    Spaceship *newShip = NULL;
    if (size(*ship) >= index){
        newShip = &manager->listAlienSpaceship[index];
    }
    return newShip;
}





