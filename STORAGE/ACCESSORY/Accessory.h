#pragma once
#include <string>
#include "../Storage.h"
using namespace std;

class Accessory : public Storage {
    public:
        Accessory(string, string, int, int);
        ~Accessory();
};