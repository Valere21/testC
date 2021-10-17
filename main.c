#include "SDL.h"
#include "conio.h"
#include <stdio.h>

typedef struct VAISSEAU Vaisseau;

struct VAISSEAU{
    int posX;
    int posY;
    int life;
    char direction;
};

Vaisseau vaisseau(){
    Vaisseau vs = {5,5,100,1};
    return vs;
}



typedef struct MAP Map;
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
    /* Initialisation simple */
    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }
    else
    {
        SDL_Event event;

        SDL_Window * window = SDL_CreateWindow("SDL2 Displaying Image",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
        SDL_Surface * vaisseaux = SDL_LoadBMP("vaisseaux.bmp");
        //        vaisseaux->w = 150;
        //        vaisseaux->h = 150;




        SDL_Surface* pSprite = SDL_LoadBMP("vaisseaux.bmp");
        if ( pSprite )
        {
            SDL_Rect dest = { 640/2 - pSprite->w/2,480/2 - pSprite->h/2, 0, 0};
            dest.h = 50;
            dest.w = 50;

            SDL_BlitSurface(pSprite,NULL,SDL_GetWindowSurface(window),&dest); // Copie du sprite

            SDL_UpdateWindowSurface(window); // Mise à jour de la fenêtre pour prendre en compte la copie du sprite
            SDL_Delay(2000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */

            dest.x = 640/3 - pSprite->w/2;
            dest.y = 480/3 - pSprite->h/2;

            SDL_BlitSurface(pSprite,NULL,SDL_GetWindowSurface(window),&dest); // Copie du sprite
            
            SDL_UpdateWindowSurface(window); // Mise à jour de la fenêtre pour prendre en compte la copie du sprite


            SDL_FreeSurface(pSprite); // Libération de la ressource occupée par le sprite
        }



//        SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
//        SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, vaisseaux);
//        SDL_SetColorKey(vaisseaux, SDL_TRUE, SDL_MapRGB(vaisseaux->format, 50, 50, 0));

//        SDL_FreeSurface(vaisseaux);
//        SDL_Rect src = {0, 0, 0, 0};
//        SDL_Rect dst = { 0, 0, 400, 300 };
//        SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);

//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//        SDL_RenderClear(renderer);
//        SDL_RenderCopy(renderer, texture, &src, &dst);
//        SDL_RenderPresent(renderer);

//        for (int i = 0; i < 7; i++){


//            SDL_SetTextureColorMod(texture ,25, 157, 255);
//            SDL_RenderClear(renderer);
//            SDL_RenderCopy(renderer, texture, NULL, NULL); // Affiche ma texture sur touts l'écran
//            SDL_RenderPresent(renderer);
//            SDL_Delay(500); /* Attendre trois secondes, que l'utilisateur voie la fenêtre */




//            SDL_SetTextureColorMod(texture ,150, 0, 255);
//            SDL_RenderClear(renderer);
//            SDL_RenderCopy(renderer, texture, NULL, NULL);
//            SDL_RenderPresent(renderer);

//            SDL_Delay(500); /* Attendre trois secondes, que l'utilisateur voie la fenêtre */
//        }

//        //SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); Background color

//        SDL_WaitEvent(&event);
//        SDL_RenderClear(renderer);
//        SDL_DestroyTexture(texture);
//        SDL_FreeSurface(vaisseaux);
//        SDL_DestroyRenderer(renderer);
//        SDL_DestroyWindow(window);
    }

    getInput();

    Map carte = map();
    drawMap(carte);

    Vaisseau va = vaisseau();
    Vaisseau vb = vaisseau();

    getInput();
    SDL_Quit();

    return 0;
}


////if(window)
////{

////    SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voie la fenêtre */
////    SDL_DestroyTexture(texture);
////    SDL_FreeSurface(vaisseaux);
////    SDL_DestroyRenderer(renderer);
////    SDL_DestroyWindow(window);


////    //SDL_DestroyWindow(pWindow);
////}


////else
////{
////    fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
////}

