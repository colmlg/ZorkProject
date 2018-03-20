#include "Item.h"
#include "Constants.h"
#include <iostream>
#include <sstream>

using std::string;
using std::cout;
using std::to_string;

Item::Item(){}

Item::Item(ItemType type) {
	switch (type) {
	case book:
		longDescription = "A mysterious glowing book.";
		consumable = true;
		actionDescription = "You are teleported to a new room.";
		icon = new QIcon(QString::fromStdString(":/images/items/Book_03.png"));
		break;

	case sword:
		longDescription = "A shiny metal sword.";
		consumable = false;
		actionDescription = "You are teleported to a new room.";
		icon = new QIcon(QString::fromStdString(":/images/items/metal_sword.png"));
		break;

	case berry:
		longDescription = "A delicious looking berry.";
		consumable = true;
		actionDescription = "You eat the berry and feel a bit better. You have been healed for " + to_string(Constants::berryHealAmount) + " points of health.";
		icon = new QIcon(QString::fromStdString(":/images/items/Berry_03.png"));
		break;

	case poisonBerry:
		longDescription = "A delicious looking berry.";
		consumable = true;
		actionDescription = "Ouch, the berry turned out to be poisonous! You have been dealt " + to_string(Constants::poisonBerryDamage) + " damage.";
		icon = new QIcon(QString::fromStdString(":/images/items/Berry_02.png"));
		break;
	}
}

string Item::getLongDescription() {
	return longDescription;
}

bool Item::isConsumable() {
    return consumable;
}

bool Item::isSelected() {
	return selected;
}

void Item::setSelected(bool selected) {
	this->selected = selected;
}

string Item::getActionDescription() {
    return actionDescription;
}

bool Item::isWeapon() {
    return false;
}
