#include "Human.h"

Human::Human(){}
Human::Human(string ID, string name, string phoneNumber, string address, string email, string gender, int age)
    : ID(ID), name(name), phoneNumber(phoneNumber), address(address), email(email), gender(gender), age(age){}
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
void Human::setGender(string gender) {
    this->gender = gender;
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
string Human::getGender() {
    return gender;
}
int Human::getAge() {
    return age;
}