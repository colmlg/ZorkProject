#include "Character.h"

void Character::addItem(Item* item) {
    itemsInCharacter.push_back(item);
}

string Character::longDescription() {
    if (itemsInCharacter.empty()) {
        return "Your inventory is empty.";
    }

    string itemList;
    for (vector<Item*>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++) {
        itemList += (*i)->getShortDescription() + "\n";
    }
    return itemList;
}

Item* Character::takeItem(string itemName) {
    for (int i = 0; i < itemsInCharacter.size(); i++) {
        Item* item = itemsInCharacter[i];
        if (item->getShortDescription() == itemName) {
            itemsInCharacter.erase(itemsInCharacter.begin() + i);
            return item;
        }
    }
    
    return NULL;
}
