#ifndef MANAGEGAME_H
#define MANAGEGAME_H
#include <Spaceship.h>

enum level {
    niveau1 = 0,
    niveau2 = 1,
    niveau3 = 2,
    niveauInfini = 3
};

typedef struct VAISSEAU Vaisseau;

struct MANAGEGAME{


    Vaisseau mainSpaceShip;
    Vaisseau *ennemySpaceShip;

    int level;
};



#endif // MANAGEGAME_H
