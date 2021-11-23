#pragma once
#include <string>
using namespace std;

class Commodity {
    protected:
        string ID;
        string name;
        int quantity;
        int price;
    public:
        Commodity();
        Commodity(string, string, int, int);
        ~Commodity();
        void setID(string);
        void setName(string);
        void setQuantity(int);
        void setPrice(int);
        string getID();
        string getName();
        int getQuantity();
        int getPrice();
};