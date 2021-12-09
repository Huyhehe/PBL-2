#pragma once
#include <string>
#include <iostream>
#include "Date.h"

using namespace std;

class Contract {
    private:
        Date dateIn;
        Date dateOut;
        bool isFullTime;
    public:
        Contract();
        Contract(Date, Date, bool);
        ~Contract();
        void Contract_setDateIn(Date);
        void Contract_setDateOut(Date);
        void Contract_setIsFullTime(bool);
        Date Contract_getDateIn() const;
        Date Contract_getDateOut() const;
        bool Contract_getIsFullTime() const;
        bool operator==(const Contract&);
        const Contract& operator=(const Contract&);
        friend ostream& operator<<(ostream&, const Contract&);
};