#ifndef INVENTORY_H
#define INVENTORY_H
#include "item.h"
#include <vector>
#include <string>

class Inventory {
	friend class ZorkGame;
private:
    std::vector <Item*> items;
public:
	void addItem(Item* item);
    std::vector <Item*> getItems();
    void selectItem(int index);
    void deselectItems();
    int getNumberOfItems();
    void removeItem(int index);
	friend void moveSelectedItem(Inventory& fromInventory, Inventory& toInventory);
};
#endif /* INVENTORY_H */
