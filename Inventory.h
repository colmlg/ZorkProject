#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include <vector>
#include <string>

class Inventory {
private:
public:
    std::vector <Item*> items;
    void addItem(Item* item);
    Item* takeItem(std::string itemName);
    std::string getItemNames();
    void selectItem(int index);
    void deselectItems();
};
#endif /* INVENTORY_H */
