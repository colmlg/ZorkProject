#ifndef ITEM_H_
#define ITEM_H_
#include <string>
#include <QIcon>

class Item {
private:
    std::string description;
    std::string longDescription;


public:
    QIcon* icon;
    bool isSelected = false;
    Item(std::string description, std::string imagePath = "");
    std::string getShortDescription();
};

#endif /*ITEM_H_*/
