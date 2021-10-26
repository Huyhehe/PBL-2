#pragma once
#include <string>
#include "../Storage.h"
// #include "../Storage.cpp"
using namespace std;

class Guitar : public Storage{
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