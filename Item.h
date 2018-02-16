#ifndef ITEM_H_
#define ITEM_H_
#include <string>
#include <QIcon>

class Item {
private:
    std::string description;
    std::string longDescription;
    int weightGrams;
    float value;
    bool weaponCheck;

public:
    QIcon* icon;
    Item(std::string description, std::string imagePath = "");
    std::string getShortDescription();
    int getWeight();
    void setWeight(int weight);
    float getValue();
    void setValue(float value);
    int getWeaponCheck();
    void setWeaponCheck(int weaponCheck);
};

#endif /*ITEM_H_*/
