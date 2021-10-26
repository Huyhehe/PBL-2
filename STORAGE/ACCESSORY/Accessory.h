#pragma once
#include <string>
#include "../Commodity.h"
using namespace std;

class Accessory : public Commodity {
    public:
        Accessory(string, string, int, int);
        ~Accessory();
};