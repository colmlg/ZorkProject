#ifndef ITEM_H_
#define ITEM_H_
#include <string>
#include <QIcon>
#include <functional>

class Item {
private:
    std::string description;
    std::string longDescription;
    bool consumable;
    std::string actionDescription;

public:
    QIcon* icon;
    bool isSelected = false;
    Item(std::string description, std::string imagePath, bool consumable = false, std::function<void()> action = NULL, std::string actionDescription = "");
    std::string getShortDescription();
    std::string getLongDescription();
    std::function<void()> action;
    bool isConsumable();
    std::string getActionDescription();
};

#endif /*ITEM_H_*/
