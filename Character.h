#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "Inventory.h"
#include <vector>
using namespace std;

class Character {
private:
public:
    Inventory* inventory = new Inventory();
};

#endif /*CHARACTER_H_*/
