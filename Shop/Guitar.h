#pragma once
#include <iostream>
#include <string>
#include "Commodity.h"
using namespace std;

class Guitar : public Commodity{
    private:
        string brand;
        string warrantyTime;
    public:
        Guitar();
        Guitar(string, string, string, int, int, string);
        Guitar(const Guitar&);
        ~Guitar();
        void setBrand(string);
        void setWarrantyTime(string);
        string getBrand() const;
        string getWarrantyTime() const;
        friend ostream& operator<<(ostream&, const Guitar&);
        const Guitar& operator=(const Guitar&);
};