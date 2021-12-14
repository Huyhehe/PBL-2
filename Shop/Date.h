#pragma once
#include <iostream>
#include <string>

using namespace std;

class Date {
    private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int, int, int);
        Date(const Date&);
        ~Date();
        string getDay() const;
        void setDay(int);
        string getMonth() const;
        void setMonth(int);
        string getYear() const;
        void setYear(int);
        string getDate() const;
        void setDate(int, int, int);
        bool operator>(const Date&);
        bool operator<(const Date&);
        bool operator==(const Date&);
        const Date& operator=(const Date&);
        friend ostream& operator<<(ostream&, const Date&);
        friend Date stringToDate(string);
};

Date stringToDate(string);
