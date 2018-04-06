#ifndef ITEM_H_
#define ITEM_H_
#include <string>
#include <QIcon>
#include <functional>

enum ItemType {
	book, sword, berry, poisonBerry
};

class Item {
protected:
	std::string longDescription;
	std::string shortDescription;
	std::string actionDescription;
	bool consumable;
	bool selected = false;

public:
	virtual ~Item();
	Item();
	Item(ItemType);
    QIcon* icon;
	std::function<void()> action;
    std::string getShortDescription();
    std::string getLongDescription();
	std::string getActionDescription();
    bool isConsumable();
	bool isSelected();
	void setSelected(bool selected);
    virtual bool isWeapon();
};

#endif /*ITEM_H_*/
