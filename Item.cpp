#include "Item.h"
#include <iostream>
using std::string;
using std::cout;

Item::Item(string description, int inWeight, float inValue) {
    this->description = description;
    setWeight(inWeight);
    value = inValue;
}

Item::Item(string description) {
    this->description = description;
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
