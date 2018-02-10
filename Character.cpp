#include "Character.h"

void Character::addItem(Item item) {
    itemsInCharacter.push_back(item);
}

string Character::longDescription() {
    if (itemsInCharacter.empty()) {
        return "Your inventory is empty.";
    }

    string itemList;
    for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++) {
        itemList += (*i).getShortDescription() + "\n";
    }
    return itemList;
}

Item Character::getItem(string itemName) {
    for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++) {
        Item item = *i;
        if (item.getShortDescription() == itemName) {
            return item;
        }
    }
    
}
