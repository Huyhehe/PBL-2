#include "Guitar.h"

Guitar::Guitar(string ID, string brand, string name, int quantity, int price, string warrantyTime) :Commodity(ID, name, quantity, price) {
    this->brand = brand;
    this->warrantyTime = warrantyTime;
}
Guitar::~Guitar(){}

void Guitar::setBrand(string brand) {
    this->brand = brand;
}

void Guitar::setWarrantyTime(string warrantyTime) {
    this->warrantyTime = warrantyTime;
}

string Guitar::getBrand() {
    return brand;
}

string Guitar::getWarrantyTime() {
    return warrantyTime;
}