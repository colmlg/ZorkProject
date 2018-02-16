#include "Item.h"
#include <iostream>
using std::string;
using std::cout;

Item::Item(string description, string imagePath) {
    this->description = description;
    icon = new QIcon(QString::fromStdString(imagePath));
}

void Item::setWeight(int weight) {
    if (weight > 9999 || weight < 0)
        cout << "weight invalid, must be 0<weight<9999";
    else
        weightGrams = weight;
}

void Item::setValue(float value) {
    if (value > 9999 || value < 0)
        cout << "value invalid, must be 0<value<9999";
    else
        this->value = value;
}

string Item::getShortDescription() {
    return description;
}
