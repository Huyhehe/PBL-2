#include "Accessory.h"

Accessory::Accessory() {

}

Accessory::Accessory(string ID, string typeOfCommodity, string name, int quantity, int price, string warrantyTime)
    : Commodity(ID, name, quantity, price) {
    this->warrantyTime = warrantyTime;
    this->typeOfCommodity = typeOfCommodity;
}

Accessory::Accessory(const Accessory& accessory) {
    this->ID = accessory.ID;
    this->typeOfCommodity = accessory.typeOfCommodity;
    this->name = accessory.name;
    this->quantity = accessory.quantity;
    this->price = accessory.price;
    this->warrantyTime = accessory.warrantyTime;
}

Accessory::~Accessory(){

}

string Accessory::getFullName() const {
    return this->getTypeOfCommodity() + this->getName();
}

string Accessory::getWarrantyTime() const {
    return this->warrantyTime;
}

void Accessory::setWarrantyTime(string warrantyTime) {
    this->warrantyTime = warrantyTime;
}

string Accessory::getTypeOfCommodity() const {
    return this->typeOfCommodity;
}

void Accessory::setTypeOfCommodoty(string typeOfCommodity) {
    this->typeOfCommodity = typeOfCommodity;
}

ostream& operator<<(ostream& out, const Accessory& accessory) {
    out << "Ma Phu Kien: " << accessory.ID << endl;
    out << "Loai Phu Kien: " << accessory.typeOfCommodity << endl;
    out << "Ten Phu Kien: " << accessory.name << endl;
    out << "So Luong trong Kho: " << accessory.quantity << endl;
    out << "Gia: " << accessory.price << endl;
    out << "Thoi gian bao hanh: " << accessory.warrantyTime << endl;
    return out;
}

const Accessory& Accessory::operator=(const Accessory& accessory) {
    this->ID = accessory.ID;
    this->typeOfCommodity = accessory.typeOfCommodity;
    this->name = accessory.name;
    this->quantity = accessory.quantity;
    this->price = accessory.price;
    this->warrantyTime = accessory.warrantyTime;
    return *this;
}
