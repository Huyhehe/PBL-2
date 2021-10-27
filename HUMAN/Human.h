#pragma once
#include <string>
using namespace std;

class Human {
    private:
        string ID;
        string name;
        string phoneNumber;
        string address;
        string email;
        string sex;
        int age;
    public:
        Human();
        Human(string, string, string, string, string, string, int);
        Human(string, string, string, string, string);
        ~Human();
        void setID(string);
        void setName(string);
        void setPhoneNumber(string);
        void setAddress(string);
        void setEmail(string);
        void setSex(string);
        void setAge(int);
        string getID();
        string getName();
        string getPhoneNumber();
        string getAddress();
        string getEmail();
        string getSex();
        int getAge(); 
};