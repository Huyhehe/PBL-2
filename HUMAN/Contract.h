#pragma once
#include <string>
#include <iostream>

using namespace std;

class Contract {
    private:
        string dateIn;
        string dateOut;
        bool isFullTime;
    public:
        Contract();
        Contract(string, string, bool);
        ~Contract();
        void Contract_setDateIn(string);
        void Contract_setDateOut(string);
        void Contract_setIsFullTime(bool);
        string Contract_getDateIn();
        string Contract_getDateOut();
        bool Contract_getIsFullTime();
        bool operator==(const Contract&);
        const Contract& operator=(const Contract&);
        friend ostream& operator<<(ostream&, const Contract&);
};