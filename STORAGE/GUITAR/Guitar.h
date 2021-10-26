#pragma once
#include <string>
using namespace std;

class Guitar {
    private:
        string ID;
        string brand;
        string name;
        int quantity;
        int price;
        string warrantyTime;
    public:
        Guitar(string, string, string, int, int, string);
        ~Guitar();
        void Guitar_setInfo(string, string, string, int, int, string);
        string Guitar_getID();
        string Guitar_getBrand();
        string Guitar_getName();
        int Guitar_getQuantity();
        int Guitar_getPrice();
        string Guitar_getWarrantyTime();
};