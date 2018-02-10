#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "Item.h"
#include <vector>
using namespace std;

class Character {
private:
    vector <Item> itemsInCharacter;
public:
    void addItem(Item item);

public:
    string longDescription();
};

#endif /*CHARACTER_H_*/
