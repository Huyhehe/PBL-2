#pragma once
#include "Human.h"
#include <string>

using namespace std;

class Customer : public Human{
    private:
    public:
        Customer();
        Customer(string, string, string, string, string);
        ~Customer();
};