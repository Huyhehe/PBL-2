#include "Guitar.h"

Guitar::Guitar() {

}

Guitar::Guitar(string ID, string brand, string name, int quantity, int price, string warrantyTime) :Commodity(ID, name, quantity, price) {
    this->brand = brand;
    this->warrantyTime = warrantyTime;
}

Guitar::Guitar(const Guitar& guitar) {
    this->ID = guitar.ID;
    this->brand = guitar.brand;
    this->name = guitar.name;
    this->quantity = guitar.quantity;
    this->price = guitar.price;
    this->warrantyTime = guitar.warrantyTime;
}

Guitar::~Guitar(){}

void Guitar::setBrand(string brand) {
    this->brand = brand;
}

void Guitar::setWarrantyTime(string warrantyTime) {
    this->warrantyTime = warrantyTime;
}

string Guitar::getBrand() const {
    return brand;
}

string Guitar::getWarrantyTime() const {
    return warrantyTime;
}

ostream& operator<<(ostream& out, const Guitar& guitar) {
    out << "Ma Guitar: " << guitar.ID << endl;
    out << "Thuong Hieu: " << guitar.brand << endl;
    out << "Ten Guitar: " << guitar.name << endl;
    out << "So Luong trong Kho: " << guitar.quantity << endl;
    out << "Gia: " << guitar.price << endl;
    out << "Thoi gian bao hanh: " << guitar.warrantyTime << endl;
    return out;
}

const Guitar& Guitar::operator=(const Guitar& guitar) {
    this->ID = guitar.ID;
    this->brand = guitar.brand;
    this->name = guitar.name;
    this->quantity = guitar.quantity;
    this->price = guitar.price;
    this->warrantyTime = guitar.warrantyTime;
    return *this;
}
