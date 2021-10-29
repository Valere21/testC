#include <Spaceship.h>
#include "manageGame.h"
typedef struct VAISSEAU Vaisseau;


Vaisseau spaceship(){
    Vaisseau spaceship = {42,42,42,'1'};
    return spaceship;
}

Vaisseau alien(){
    Vaisseau alien = {40,40,40,'0'};
    return alien;
}

Vaisseau vaisseau(int typeSpaceship){
    Vaisseau vaisseau;
    if (typeSpaceship == Spaceship)
        vaisseau = spaceship();

    else vaisseau = alien();
    return vaisseau;
}

