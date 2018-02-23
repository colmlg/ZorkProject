#include "Item.h"
#include <iostream>
using std::string;
using std::cout;

Item::Item() {}

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

string Item::getLongDescription() {
	return longDescription;
}

bool Item::isConsumable() {
    return consumable;
}

string Item::getActionDescription() {
    return actionDescription;
}

Item::Item(ItemType type) {
	switch (type) {
	case book:
		description = "book";
		longDescription = "A mysterious glowing book.";
		consumable = true;
		actionDescription = "You are teleported to a new room.";
		icon = new QIcon(QString::fromStdString(":/images/items/Book_03.png"));
		break;

	case sword:
		description = "sword";
		longDescription = "A shiny metal sword.";
		consumable = false;
//		actionDescription = "You are teleported to a new room.";
		icon = new QIcon(QString::fromStdString(":/images/items/metal_sword.png"));
		break;

	case berry:
		description = "berry";
		longDescription = "A delicious looking berry.";
		consumable = true;
		actionDescription = "You eat the berry and feel a bit better. You have been healed for 10 points of health.";
		icon = new QIcon(QString::fromStdString(":/images/items/Berry_03.png"));
		break;
	}
}
