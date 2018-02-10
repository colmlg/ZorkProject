#include "Character.h"

void Character::addItem(Item item) {
    std::cout << "about to crash";
    itemsInCharacter.push_back(item);
    std::cout << "didnt crash!";
}

string Character::longDescription() {
    
    string itemList = "\n Item list:\n";
    for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
        itemList += "\t" + (*i).getLongDescription() + "\n";
    return itemList;
}



