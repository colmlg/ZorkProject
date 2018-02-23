#ifndef ITEM_H_
#define ITEM_H_
#include <string>
#include <QIcon>
#include <functional>

enum ItemType {
	book, sword, berry
};

class Item {
protected:
    std::string description;
    std::string longDescription;
    bool consumable;

public:
    QIcon* icon;
    bool isSelected = false;
	Item();
	Item(ItemType);
    Item(std::string description, std::string imagePath, bool consumable = false, std::function<void()> action = NULL, std::string actionDescription = "");
    std::string getShortDescription();
    std::string getLongDescription();
    std::function<void()> action;
    bool isConsumable();
    std::string getActionDescription();
	std::string actionDescription;
};

#endif /*ITEM_H_*/
