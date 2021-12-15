#include <string>
#include "Receipt.h"

Receipt::Receipt() {
    this->ID = "Unknow";
    this->customerName = "Unknow";
}

Receipt::Receipt(string ID, string customerName, CommodityManager commodity, Date date)
    : ID(ID), customerName(customerName) {
    this->commodity = commodity;
    this->date = date;
}

Receipt::Receipt(const Receipt& receipt) {
    this->ID = receipt.ID;
    this->customerName = receipt.customerName;
    this->commodity = receipt.commodity;
    this->date = receipt.date;
}

Receipt::~Receipt() {

}

string Receipt::getID() const {
    return this->ID;
}

void Receipt::setID(string ID) {
    this->ID = ID;
}

string Receipt::getCustomerName() const {
    return this->customerName;
}

void Receipt::setCustomerName(string customerName) {
    this->customerName = customerName;
}

CommodityManager Receipt::getCommodity() const {
    return this->commodity;
}

CommodityManager& Receipt::getCommodityManager() {
    return this->commodity;
}

void Receipt::addCommodity(const Guitar& guitar, int quantity) {
    (this->commodity).pushWithQuantity(guitar, quantity);
}

void Receipt::addCommodity(const Accessory& accessory, int quantity) {
    (this->commodity).pushWithQuantity(accessory, quantity);
}

void Receipt::calculatorTotalMoney() {
    int totalMoney = 0;
    for (int i = 0; i < (this->commodity).getNumberOfGuitar(); i++) {
        totalMoney += (this->commodity).getGuitar(i).getPrice() * (this->commodity).getGuitar(i).getQuantity();
    }
    for (int i = 0; i < (this->commodity).getNumberOfAccessory(); i++) {
        totalMoney += (this->commodity).getAccessory(i).getPrice() * (this->commodity).getAccessory(i).getQuantity();
    }
    this->totalMoney = totalMoney;
}

void Receipt::setTotalMoney(int totalMoney) {
    this->totalMoney = totalMoney;
}

int Receipt::getTotalMoney() const {
    if (this->totalMoney == 0) {
    int totalMoney = 0;
        for (int i = 0; i < (this->commodity).getNumberOfGuitar(); i++) {
            totalMoney += (this->commodity).getGuitar(i).getPrice() * (this->commodity).getGuitar(i).getQuantity();
        }
        for (int i = 0; i < (this->commodity).getNumberOfAccessory(); i++) {
            totalMoney += (this->commodity).getAccessory(i).getPrice() * (this->commodity).getAccessory(i).getQuantity();
        }
        return totalMoney;
    }
    return this->totalMoney;
}

Date Receipt::getDate() const {
    return this->date;
}

void Receipt::setDate(const Date& date) {
    this->date = date;
}

ostream& operator<<(ostream& out, const Receipt& receipt) {
    out << "ID: " << receipt.ID << endl;
    out << "Ten Khach Hang: " << receipt.customerName << endl;
    out << "Hang hoa: " << endl;

    if (receipt.getCommodity().hasGuitar()) {
        for (int i = 0; i < receipt.getCommodity().getNumberOfGuitar(); i++) {
            out << receipt.getCommodity().getGuitar(i).getID() << " - ";
            out << receipt.getCommodity().getGuitar(i).getBrand() << " ";
            out << receipt.getCommodity().getGuitar(i).getName() << " - ";
            out << receipt.getCommodity().getGuitar(i).getQuantity() << " - ";
            out << receipt.getCommodity().getGuitar(i).getPrice() * receipt.getCommodity().getGuitar(i).getQuantity();
            out << endl;
        }
    }

    if (receipt.getCommodity().hasAccessory()) {
        for (int i = 0; i < receipt.getCommodity().getNumberOfAccessory(); i++) {
            out << receipt.getCommodity().getAccessory(i).getID() << " - ";
            out << receipt.getCommodity().getAccessory(i).getName() << " - ";
            out << receipt.getCommodity().getAccessory(i).getQuantity() << " - ";
            out << receipt.getCommodity().getAccessory(i).getPrice() * receipt.getCommodity().getAccessory(i).getQuantity();
            out << endl;
        }
    }

    out << "Tong Tien: " << receipt.getTotalMoney() << endl;
    out << "Ngay mua: " << receipt.date << endl;
    return out;
}

const Receipt& Receipt::operator=(const Receipt& receipt) {
    this->ID = receipt.ID;
    this->customerName = receipt.customerName;
    this->commodity = receipt.commodity;
    this->date = receipt.date;
    return *this;
}
