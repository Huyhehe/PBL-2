#include "Human.h"

Human::Human(){}
Human::Human(string ID, string name, string phoneNumber, string address, string email, string sex, int age)
: ID(ID), name(name), phoneNumber(phoneNumber), address(address), email(email), sex(sex), age(age){}
Human::Human(string ID, string name, string phoneNumber, string address, string email)
: ID(ID), name(name), phoneNumber(phoneNumber), address(address), email(email){}
Human::~Human(){}

void Human::setID(string ID) {
    this->ID = ID;
}
void Human::setName(string name) {
    this->name = name;
}
void Human::setPhoneNumber(string phoneNumber) {
    this->phoneNumber = phoneNumber;
}
void Human::setAddress(string address) {
    this->address = address;
}
void Human::setEmail(string mail) {
    this->email = email;
}
void Human::setSex(string sex) {
    this->sex = sex;
}
void Human::setAge(int age) {
    this->age = age;
}

string Human::getID() {
    return ID;
}
string Human::getName() {
    return name;
}
string Human::getPhoneNumber() {
    return phoneNumber;
}
string Human::getAddress() {
    return address;
}
string Human::getEmail() {
    return email;
}
string Human::getSex() {
    return sex;
}
int Human::getAge() {
    return age;
}