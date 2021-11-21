#ifndef MANAGEINFO_H
#define MANAGEINFO_H
#include <ManageGame.h>
#endif // MANAGEINFO_H


typedef struct MANAGEGAME ManageGame;
typedef struct MANAGEINFO ManageInfo;


ManageInfo *manageInfo(ManageInfo*);       //rÃ©fÃ©rencement du prototype de pointeur de fonction (depuis le .h), vers la dÃ©claration de la fonction (vers le .c)

void cleanRessources(SDL_Window*, SDL_Renderer*, SDL_Texture*);
void checkSDLTools(ManageGame manager, int tool);
void displayInfo(ManageGame *manager);

struct MANAGEINFO{

    ManageInfo *(*manageInfo)(ManageInfo*);       //rÃ©fÃ©rencement du prototype de pointeur de fonction (depuis le .h), vers la dÃ©claration de la fonction (vers le .c)

    void (*cleanRessources)(SDL_Window*, SDL_Renderer*, SDL_Texture*);
    void (*checkSDLTools)(ManageGame, int);
    void (*displayInfo)(ManageGame*);

};

