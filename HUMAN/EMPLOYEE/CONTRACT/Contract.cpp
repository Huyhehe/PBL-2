#include "Contract.h"
#include <iostream>
using namespace std;

Contract::Contract(string dateIn, string dateOut, bool isFullTime) : dateIn(dateIn), dateOut(dateOut), isFullTime(isFullTime) {}
Contract::~Contract() {};

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