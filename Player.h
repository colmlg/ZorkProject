#ifndef PLAYER_H_
#define PLAYER_H_
#include "Inventory.h"
#include "Entity.h"

class Player: public Entity {
public:
	Player();
    Inventory* inventory = new Inventory();

};

#endif /*PLAYER_H_*/
