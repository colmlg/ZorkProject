#include "Item.h"
#include <iostream>
using std::string;
using std::cout;

Item::Item(string description, string imagePath) {
    this->description = description;
    icon = new QIcon(QString::fromStdString(imagePath));
}

string Item::getShortDescription() {
    return description;
}
