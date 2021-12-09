#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include "CommodityManager.h"
#include "Date.h"
#include "Employee.h"

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
