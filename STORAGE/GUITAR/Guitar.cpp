#include "Guitar.h"

Guitar::Guitar(string ID, string brand, string name, int quantity, int price, string warrantyTime) : ID(ID), brand(brand), name(name), quantity(quantity),
price(price), warrantyTime(warrantyTime) {}
Guitar::~Guitar(){}

void Guitar::Guitar_setInfo(string ID, string brand, string name, int quantity, int price, string warrantyTime) {
    this->ID = ID;
    this->brand = brand;
    this->name = name;
    this->quantity = quantity;
    this->price = price;
    this->warrantyTime = warrantyTime;
}

string Guitar::Guitar_getID() {
    return ID;
}
string Guitar::Guitar_getBrand() {
    return brand;
}
string Guitar::Guitar_getName() {
    return name;
}
int Guitar::Guitar_getQuantity() {
    return quantity;
}
int Guitar::Guitar_getPrice() {
    return price;
}
string Guitar::Guitar_getWarrantyTime() {
    return warrantyTime;
}