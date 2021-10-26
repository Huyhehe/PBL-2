#include "Accessory.h"

Accessory::Accessory(string ID, string name, int quantity, int price) : ID(ID), name(name), quantity(quantity),
price(price) {}
Accessory::~Accessory(){}

void Accessory::Accessory_setInfo(string ID, string name, int quantity, int price) {
    this->ID = ID;
    this->name = name;
    this->quantity = quantity;
    this->price = price;
}

string Accessory::Accessory_getID() {
    return ID;
}
string Accessory::Accessory_getName() {
    return name;
}
int Accessory::Accessory_getQuantity() {
    return quantity;
}
int Accessory::Accessory_getPrice() {
    return price;
}