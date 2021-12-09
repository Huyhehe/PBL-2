#include "Contract.h"

Contract::Contract() {

}

Contract::Contract(Date dateIn, Date dateOut, bool isFullTime) 
    : dateIn(dateIn), dateOut(dateOut), isFullTime(isFullTime) {

}

Contract::~Contract() {

}

void Contract::Contract_setDateIn(Date dateIn) {
    this->dateIn = dateIn;
}

void Contract::Contract_setDateOut(Date dateOut) {
    this->dateOut = dateOut;
}

void Contract::Contract_setIsFullTime(bool isFullTime) {
    this->isFullTime = isFullTime;
}

Date Contract::Contract_getDateIn() const {
    return this->dateIn;
}

Date Contract::Contract_getDateOut() const {
    return this->dateOut;
}

bool Contract::Contract_getIsFullTime() const {
    return this->isFullTime;
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