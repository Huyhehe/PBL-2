#pragma once
#include <string>
#include "../Commodity.h"
using namespace std;

class Guitar : public Commodity{
    private:
        string brand;
        string warrantyTime;
    public:
        Guitar(string, string, string, int, int, string);
        ~Guitar();
        void setBrand(string);
        void setWarrantyTime(string);
        string getBrand();
        string getWarrantyTime();
};