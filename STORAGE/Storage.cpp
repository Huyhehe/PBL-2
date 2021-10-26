#include "Storage.h"

Storage::Storage(string ID, string name, int quantity, int price) : ID(ID), name(name), quantity(quantity), price(price) {}
Storage::~Storage(){}
void Storage::setID(string ID) {
    this->ID = ID;
}
void Storage::setName(string name) {
    this->name = name;
}
void Storage::setQuantity(int quantity) {
    this->quantity = quantity;
}
void Storage::setPrice(int price) {
    this->price = price;
}
string Storage::getID() {
    return ID;
}
string Storage::getName() {
    return name;
}
int Storage::getQuantity() {
    return quantity;
}
int Storage::getPrice() {
    return price;
}