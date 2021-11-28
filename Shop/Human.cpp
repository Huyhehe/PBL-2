#include "Human.h"

Human::Human(){}
Human::Human(string ID, string name, int age, string phoneNumber, string email, string address, string gender)
    : ID(ID), name(name), phoneNumber(phoneNumber), email(email), address(address), gender(gender), age(age){}
Human::Human(string ID, string name, string phoneNumber, string email, string address)
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
void Human::setEmail(string email) {
    this->email = email;
}
void Human::setGender(string gender) {
    this->gender = gender;
}
void Human::setAge(int age) {
    this->age = age;
}

string Human::getID() const {
    return this->ID;
}
string Human::getName() const {
    return this->name;
}
string Human::getPhoneNumber() const {
    return this->phoneNumber;
}
string Human::getAddress() const {
    return this->address;
}
string Human::getEmail() const {
    return this->email;
}
string Human::getGender() const {
    return this->gender;
}
int Human::getAge() const {
    return this->age;
}