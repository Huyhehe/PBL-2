#include "Commodity.h"

Commodity::Commodity() {

}

Commodity::Commodity(string ID, string name, int quantity, int price)
    : ID(ID), name(name), quantity(quantity), price(price) {

}
Commodity::~Commodity(){

}

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
string Commodity::getID() const {
    return ID;
}
string Commodity::getName() const {
    return name;
}
int Commodity::getQuantity() const {
    return quantity;
}
int Commodity::getPrice() const {
    return price;
}
