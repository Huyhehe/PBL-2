#include "Contract.h"

Contract::Contract() {

}

Contract::Contract(string dateIn, string dateOut, bool isFullTime) 
    : dateIn(dateIn), dateOut(dateOut), isFullTime(isFullTime) {

}

Contract::~Contract() {

}

void Contract::Contract_setDateIn(string dateIn) {
    this->dateIn = dateIn;
}

void Contract::Contract_setDateOut(string dateOut) {
    this->dateOut = dateOut;
}

void Contract::Contract_setIsFullTime(bool isFullTime) {
    this->isFullTime = isFullTime;
}

string Contract::Contract_getDateIn() {
    return dateIn;
}

string Contract::Contract_getDateOut() {
    return dateOut;
}

bool Contract::Contract_getIsFullTime() {
    return isFullTime;
}

bool Contract::operator==(const Contract& cont) {
    if (this->dateIn == cont.dateIn && this->dateOut == cont.dateOut && this->isFullTime == cont.isFullTime)
        return true;
    return false;
}

const Contract& Contract::operator=(const Contract& cont) {
    this->dateIn = cont.dateIn;
    this->dateOut = cont.dateOut;
    this->isFullTime = cont.isFullTime;
    return *this;
}

ostream& operator<<(ostream& out, const Contract& cont) {
    out << "Ngay bat dau lam viec: " << cont.dateIn << endl;
    out << "Ngay het hop dong: " << cont.dateOut << endl;
    if (cont.isFullTime) 
        out << "La nhan vien toan thoi gian." << endl;
    else 
        out << "La nhan vien ban thoi gian." << endl;
    return out;
}