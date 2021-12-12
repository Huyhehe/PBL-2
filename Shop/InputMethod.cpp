#include <iostream>
#include <string>
#include <fstream>
#include "CommodityManager.h"
#include "Date.h"
#include "Employee.h"
#include "EmployeeManager.h"

using namespace std;

string getData(const string& str) {
    return str.substr(str.find(":") + 1, str.length());
}

string strip(const string& str) {
    int i = 0;
    while (i < str.length()) {
        if(str[i] != ' ')
            break;
        i += 1;
    }
    if (i >= 1)
        return str.substr(i, str.length());
    return str;
}

Date stringToDate(string str) {
    string day = str.substr(0, str.find("/"));
    str = str.substr(str.find("/") + 1, str.length());
    string month = str.substr(0, str.find("/"));
    string year = str.substr(str.find("/") + 1, str.length());
    return Date(stoi(day), stoi (month), stoi(year));
}

void readData(CommodityManager& storage, const string& option, const string& fileName) {
    string str;
    ifstream fileInput;
    fileInput.open(fileName, ios::in);
    if (option == "Guitar") {
        Guitar* temp = new Guitar();
        int i = 0;
        while (!fileInput.eof()) {
            getline(fileInput, str);
            if (str == "") {
                i = 0;
                storage.push(*temp);
                delete temp;
                temp = new Guitar();
                continue;
            }

            switch(i) {
                case 0:
                    temp->setID(strip(getData(str)));
                    break;
                case 1:
                    temp->setBrand(strip(getData(str)));
                    break;
                case 2:
                    temp->setName(strip(getData(str)));
                    break;
                case 3:
                    temp->setQuantity(stoi(strip(getData(str))));
                    break;
                case 4:
                    temp->setPrice(stoi(strip(getData(str))));
                    break;
                case 5:
                    temp->setWarrantyTime(strip(getData(str)));
                default:
                    break;
            }

            i += 1;
        }

        if (storage.indexOf(*temp) == -1)
            storage.push(*temp);

        delete temp;
    }

    if (option == "Accessory") {
        Accessory* temp = new Accessory();
        int i = 0;
        while (!fileInput.eof()) {
            getline(fileInput, str);
            if (str == "") {
                i = 0;
                storage.push(*temp);
                delete temp;
                temp = new Accessory();
                continue;
            }

            switch(i) {
                case 0:
                    temp->setID(strip(getData(str)));
                    break;
                case 1:
                    temp->setTypeOfCommodoty(strip(getData(str)));
                    break;
                case 2:
                    temp->setName(strip(getData(str)));
                    break;
                case 3:
                    temp->setQuantity(stoi(strip(getData(str))));
                    break;
                case 4:
                    temp->setPrice(stoi(strip(getData(str))));
                    break;
                case 5:
                    temp->setWarrantyTime(strip(getData(str)));
                default:
                    break;
            }

            i += 1;
        }

        if (storage.indexOf(*temp) == -1)
            storage.push(*temp);

        delete temp;
    }
}

void readData(EmployeeManager& manager, const string& fileName) {
    string str;
    ifstream fileInput;
    fileInput.open(fileName, ios::in);
    Employee* temp = new Employee();
    int i = 0;
    while (!fileInput.eof()) {
        getline(fileInput, str);
        if (str == "") {
            i = 0;
            manager.push(*temp);
            delete temp;
            temp = new Employee();
            continue;
        }

        switch(i) {
            case 0:
                temp->setID(strip(getData(str)));
                break;
            case 1:
                temp->setName(strip(getData(str)));
                break;
            case 2: {
                Date date(stringToDate(strip(getData(str))));
                temp->setDateOfBirth(date);
                break;
            }
            case 3:
                temp->setGender(strip(getData(str)));
                break;
            case 4:
                temp->setPhoneNumber(strip(getData(str)));
                break;
            case 5:
                temp->setEmail(strip(getData(str)));
                break;
            case 6:
                temp->setAddress(strip(getData(str)));
                break;
            case 7: {
                Date dateIn(stringToDate(strip(getData(str))));
                getline(fileInput, str);
                Date dateOut(stringToDate(strip(getData(str))));
                getline(fileInput, str);
                bool isFullTime;
                if (strip(getData(str)) == "true")
                    isFullTime = true;
                else
                    isFullTime = false;
                temp->setContract(Contract(dateIn, dateOut, isFullTime));
                break;
            }
            case 8:
                temp->setSalary(stoi(strip(getData(str))));
                break;
            default:
                break;
        }

        i += 1;
   }
}

int main() {
    EmployeeManager emp;
    readData(emp, "../Data/Employee.txt");
    cout << emp;
    return 0;
}
