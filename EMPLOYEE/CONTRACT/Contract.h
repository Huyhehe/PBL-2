#pragma once
#include <string>
using namespace std;

class Contract {
    private:
        string dateIn;
        string dateOut;
        bool isFullTime;
    public:
        Contract(string, string, bool);
        ~Contract();
        void Contract_setDateIn(string);
        void Contract_setDateOut(string);
        void Contract_setIsFullTime(bool);
        string Contract_getDateIn();
        string Contract_getDateOut();
        bool Contract_getIsFullTime();
};