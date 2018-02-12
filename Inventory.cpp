#include "Inventory.h"

void Inventory::addItem(Item* item) {
    items.push_back(item);
}

Item* Inventory::takeItem(string itemName) {
    for (int i = 0; i < items.size(); i++) {
        Item* item = items[i];
        if (item->getShortDescription() == itemName) {
            items.erase(items.begin() + i);
            return item;
        }
    }
    
    return NULL;
}

string Inventory::getItemNames() {
    int numberOfItems = items.size();
    if (numberOfItems == 0) {
        return "No items.";
    }
    
    string listOfItems;
    for (int i = 0; i < numberOfItems; i++) {
        listOfItems += items[i]->getShortDescription() + " ";
    }
    return listOfItems;
}