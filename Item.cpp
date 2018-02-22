#include "Item.h"
#include <iostream>
using std::string;
using std::cout;

Item::Item(string description, string imagePath, bool consumable, std::function<void()> action, string actionDescription) {
    this->description = description;
    this->consumable = consumable;
    this->action = action;
    this->actionDescription = actionDescription;
    icon = new QIcon(QString::fromStdString(imagePath));
}

string Item::getShortDescription() {
    return description;
}

bool Item::isConsumable() {
    return consumable;
}

string Item::getActionDescription() {
    return actionDescription;
}
