#include "Date.h"

Date::Date() {
    this->day = 0;
    this->month = 0;
    this->year = 0;
}

Date::Date(int day, int month, int year) {
    if (day <= 31 && day >= 1)
        this->day = day;
    else
        this->day = 0;
    if (month <= 12 && month >= 1)
        this->month = month;
    else
        this->month = 0;
    this->year = year;
}

Date::Date(const Date& date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
}

Date::~Date() {

}

string Date::getDay() const {
    string day = to_string(this->day);
    if (day.length() == 1)
        return "0" + day;
    return day;
}

void Date::setDay(int day) {
    if (day <= 0 && day > 31)
        return;
    this->day = day;
}

string Date::getMonth() const {
    string month = to_string(this->month);
    if (month.length() == 1)
        return "0" + month;
    return month;
}

void Date::setMonth(int month) {
    if (month < 1 && month > 12)
        return;
    this->month = month;
}

string Date::getYear() const {
    string year = to_string(this->year);
    switch (year.length()) {
        case 1:
            return "000" + year;
        case 2:
            return "00" + year;
        case 3:
            return "0" + year;
        default:
            return year;
    }
}

void Date::setYear(int year) {
    this->year = year;
}

string Date::getDate() const {
    return this->getDay() + "/" + this->getMonth() + "/" + this->getYear();
}

void Date::setDate(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

const Date& Date::operator=(const Date& date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
    return *this;
}

bool Date::operator>(const Date& date) {
    if (this->year > date.year)
        return true;
    if (this->year == date.year && this->month > date.month)
        return true;
    if (this->year == date.year && this->month == date.month && this->day > date.day)
        return true;
    return false;
}

bool Date::operator<(const Date& date) {
    if (this->year < date.year)
        return true;
    if (this->year == date.year && this->month < date.month)
        return true;
    if (this->year == date.year && this->month == date.month && this->day < date.day)
        return true;
    return false;
}

bool Date::operator==(const Date& date) {
    if (this->day == date.day && this->month == date.month && this->year == date.year)
        return true;
    return false;
}

ostream& operator<<(ostream& out, const Date& date) {
    cout << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
    return out;
}

Date stringToDate(string str) {
    string day = str.substr(0, str.find("/") - 0);
    if (day < "0" || day > "9")
        day = "0";
    str = str.substr(str.find("/") + 1, str.length() - str.find("/") - 1);
    string month = str.substr(0, str.find("/"));
    if (month < "0" || day > "9")
        month = "0";
    string year = str.substr(str.find("/") + 1, str.length() - str.find("/") - 1);
    if (year < "0" || year > "9")
        year = "0";
    return Date(stoi(day), stoi (month), stoi(year));
}
