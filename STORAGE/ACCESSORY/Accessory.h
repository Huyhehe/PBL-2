#pragma once
#include <string>
using namespace std;

class Accessory {
    private:
        string ID;
        string name;
        int quantity;
        int price;
    public:
        Accessory(string, string, int, int);
        ~Accessory();
        void Accessory_setInfo(string, string, int, int);
        string Accessory_getID();
        string Accessory_getName();
        int Accessory_getQuantity();
        int Accessory_getPrice();
};