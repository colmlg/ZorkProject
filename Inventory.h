#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include <vector>
using std::string;

class Inventory {
private:
    vector <Item*> items;
public:
    void addItem(Item* item);
    Item* takeItem(string itemName);
    string getItemNames();
};
#endif /* INVENTORY_H */
