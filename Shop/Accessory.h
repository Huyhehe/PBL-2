#pragma once
#include <string>
#include <iostream>
#include "Commodity.h"
using namespace std;

class Accessory : public Commodity {
    private:
        string typeOfCommodity;
        string warrantyTime;
    public:
        Accessory();
        Accessory(string, string, string, int, int, string);
        Accessory(const Accessory&);
        ~Accessory();
        void setWarrantyTime(string);
        string getWarrantyTime() const;
        string getTypeOfCommodity() const;
        void setTypeOfCommodoty(string);
        friend ostream& operator<<(ostream&, const Accessory&);
        const Accessory& operator=(const Accessory&);
};