#include "item.h"
#include "constants.h"
#include <iostream>
#include <sstream>

using std::string;
using std::cout;
using std::to_string;

Item::Item(){}
Item::~Item() {
	delete icon;
}

Item::Item(ItemType type) {
	switch (type) {
	case teleportBall:
		longDescription = "A mysterious glowing crystal ball. It looks as if it could help you...";
		shortDescription = "crstal ball";
		consumable = true;
		actionDescription = "A brilliant light shines from the ball, blinding you temporarily. When the light fades you find yourself standing on the other side of the chasm.";
		icon = new QIcon(QString::fromStdString(":/images/items/Crystal Ball_03.png"));
		break;

	case sword:
		longDescription = "A shiny metal sword.";
		shortDescription = "sword";
		consumable = false;
		actionDescription = "You are teleported to a new room.";
		icon = new QIcon(QString::fromStdString(":/images/items/metal_sword.png"));
		break;

	case berry:
		longDescription = "A delicious looking berry.";
		shortDescription = "berry";
		consumable = true;
		actionDescription = "You eat the berry and feel a bit better. You have been healed for " + to_string(Constants::berryHealAmount) + " points of health.";
		icon = new QIcon(QString::fromStdString(":/images/items/Berry_03.png"));
		break;

	case poisonBerry:
		longDescription = "A delicious looking berry.";
		shortDescription = "berry";
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

string Item::getShortDescription() {
	return shortDescription;
}
