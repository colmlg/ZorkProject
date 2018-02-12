#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include <vector>
#include <string>

class Inventory {
private:
    std::vector <Item*> items;
public:
    void addItem(Item* item);
    Item* takeItem(std::string itemName);
    std::string getItemNames();
};
#endif /* INVENTORY_H */
