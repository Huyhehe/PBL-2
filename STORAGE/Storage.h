#pragma once
#include <string>
using namespace std;

class Storage {
    private:
        string ID;
        string name;
        int quantity;
        int price;
    public:
        Storage(string, string, int, int);
        ~Storage();
        void setID(string);
        void setName(string);
        void setQuantity(int);
        void setPrice(int);
        string getID();
        string getName();
        int getQuantity();
        int getPrice();
};