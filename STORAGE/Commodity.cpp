#include "Commodity.h"

Commodity::Commodity(string ID, string name, int quantity, int price) : ID(ID), name(name), quantity(quantity), price(price) {}
Commodity::~Commodity(){}
void Commodity::setID(string ID) {
    this->ID = ID;
}
void Commodity::setName(string name) {
    this->name = name;
}
void Commodity::setQuantity(int quantity) {
    this->quantity = quantity;
}
void Commodity::setPrice(int price) {
    this->price = price;
}
string Commodity::getID() {
    return ID;
}
string Commodity::getName() {
    return name;
}
int Commodity::getQuantity() {
    return quantity;
}
int Commodity::getPrice() {
    return price;
}