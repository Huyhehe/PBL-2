#include <iostream>
#include <string>
#include <fstream>
#include "CommodityManager.h"
#include "Date.h"
#include "Employee.h"
#include "EmployeeManager.h"
#include "ReceiptManager.h"

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
            if ((str == "" && i == 6) || (str == "" && i > 0 && i <= 6)) {
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
    }

    if (option == "Accessory") {
        Accessory* temp = new Accessory();
        int i = 0;
        while (!fileInput.eof()) {
            getline(fileInput, str);
            if ((str == "" && i == 6) || (str == "" && i > 0 && i <= 6)) {
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
    }
    fileInput.close();
}

void readData(EmployeeManager& manager, const string& fileName) {
    string str;
    ifstream fileInput;
    fileInput.open(fileName, ios::in);
    Employee* temp = new Employee();
    int i = 0;
    while (!fileInput.eof()) {
        getline(fileInput, str);
        if ((str == "" && i == 9) || (str == "" && i > 0 && i <= 9)) {
            i = 0;
            manager.push(*temp);
            delete temp;
            temp = new Employee();
            continue;
        }

        switch(i) {
            case 0:
                temp->setID(strip(getData(str)));
                i++;
                break;
            case 1:
                temp->setName(strip(getData(str)));
                i++;
                break;
            case 2: {
                Date date(stringToDate(strip(getData(str))));
                temp->setDateOfBirth(date);
                i++;
                break;
            }
            case 3:
                temp->setGender(strip(getData(str)));
                i++;
                break;
            case 4:
                temp->setPhoneNumber(strip(getData(str)));
                i++;
                break;
            case 5:
                temp->setEmail(strip(getData(str)));
                i++;
                break;
            case 6:
                temp->setAddress(strip(getData(str)));
                i++;
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
                i++;
                break;
            }
            case 8:
                temp->setSalary(stoi(strip(getData(str))));
                i++;
                break;
            default:
                break;
        }
    }
    fileInput.close();
}

void writeData(ReceiptManager& receiptManager, const string& fileName) {
    ofstream fileOutput;
    fileOutput.open(fileName, ios::out);
    for (int i = 0; i < receiptManager.getNumberOfReceipt(); i++) {
        fileOutput << "Ma hoa don: " << receiptManager[i].getID() << endl;
        fileOutput << "Ten khach hang: " << receiptManager[i].getCustomerName() << endl;
        fileOutput << "Hang hoa: " << endl;
        for (int j = 0; j < receiptManager[i].getCommodity().getNumberOfGuitar(); j++) {
            fileOutput << "\t" << receiptManager[i].getCommodity().getGuitar(j).getID();
            fileOutput << " -- " << "Guitar";
            fileOutput << " -- " << receiptManager[i].getCommodity().getGuitar(j).getBrand();
            fileOutput << " " << receiptManager[i].getCommodity().getGuitar(j).getName();
            fileOutput << " -- " << receiptManager[i].getCommodity().getGuitar(j).getQuantity();
            fileOutput << " -- " << receiptManager[i].getCommodity().getGuitar(j).getPrice() * receiptManager[i].getCommodity().getGuitar(j).getQuantity();
            fileOutput << endl;
        }
        for (int j = 0; j < receiptManager[i].getCommodity().getNumberOfAccessory(); j++) {
            fileOutput << "\t" << receiptManager[i].getCommodity().getAccessory(j).getID();
            fileOutput << " -- " << "Accessory";
            fileOutput << " -- " << receiptManager[i].getCommodity().getAccessory(j).getName();
            fileOutput << " -- " << receiptManager[i].getCommodity().getAccessory(j).getQuantity();
            fileOutput << " -- " << receiptManager[i].getCommodity().getAccessory(j).getPrice() * receiptManager[i].getCommodity().getAccessory(j).getQuantity();
            fileOutput << endl;
        }
        fileOutput << "Tong tien: " << receiptManager[i].getTotalMoney() << endl;
        fileOutput << "Ngay xuat hoa don: " << receiptManager[i].getDate().getDay();
        fileOutput << "/" <<receiptManager[i].getDate().getMonth();
        fileOutput << "/" << receiptManager[i].getDate().getYear();
        fileOutput << endl << endl;
    }
    fileOutput.close();
}

void readData(ReceiptManager& rptManager, CommodityManager& storage, const string& fileName) {
    ifstream fileInput;
    fileInput.open(fileName, ios::in);
    Receipt *temp = new Receipt();
    int i = 0;
    string str;
    while (!fileInput.eof()) {
        if (i != 4)
            getline(fileInput, str);
        if ((str == "" && i == 6) || (str == "" && i > 0 && i <= 6)) {
            i = 0;
            rptManager.addReceipt(*temp, storage);
            delete temp;
            temp = new Receipt();
            continue;
        }

        switch(i) {
            case 0:
                temp->setID(strip(getData(str)));
                i++;
                break;
            case 1:
                temp->setCustomerName(strip(getData(str)));
                i++;
                break;
            case 2:
                i++;
                break;
            case 3: {
                while (str.find("Tong tien:") < 0 || str.find("Tong tien:") > str.length()) {
                    if (str.find("Guitar") >= 0 && str.find("Guitar") <= str.length()) {
                        string tempstr;
                        tempstr = str.substr(1, str.find(" ") - 1);
                        int start = str.find("--", str.find("--", str.find("--", 0) + 1) + 1);
                        int end = str.find("--", start + 1);
                        int quantity = stoi(str.substr(start+ 2, end - start - 3));
                        if (storage.indexOf(tempstr, "ID", "Guitar") != -1)
                            temp->addCommodity(storage.getGuitar(storage.indexOf(tempstr, "ID", "Guitar")), quantity);
                    }
                    if (str.find("Accessory") >= 0 && str.find("Accessory") <= str.length()) {
                        string tempstr;
                        tempstr = str.substr(1, str.find(" ") - 1);
                        int start = str.find("--", str.find("--", str.find("--", 0) + 1) + 1);
                        int end = str.find("--", start + 1);
                        int quantity = stoi(str.substr(start+ 2, end - start - 3));
                        if (storage.indexOf(tempstr, "ID", "Accessory") != -1)
                            temp->addCommodity(storage.getAccessory(storage.indexOf(tempstr, "ID", "Accessory")), quantity);
                    }
                    getline(fileInput, str);
                }
                i++;
                break;
            }
            case 4:
                temp->setTotalMoney(stoi(strip(getData(str))));
                i++;
                break;
            case 5: {
                Date date(stringToDate(strip(getData(str))));
                temp->setDate(date);
                i++;
                break;
            }
            default:
                break;
        }
    }
    fileInput.close();
}

int main() {
    //EmployeeManager emp;
    //Employee e1("88", "Hieu", Date(2, 1,2001), "092103", "nam", "Minhhd@", "33 namma", Contract(Date(9, 2, 3910), Date(2, 3, 19912), true));
    //Employee e2("88", "nam", Date(2, 1,2001), "092103", "nam", "Minhhd@", "33 namma", Contract(Date(9, 2, 3910), Date(2, 3, 19912), true));
    //Employee e3("882", "Hieu", Date(2, 1,2001), "092103", "nam", "Minhhd@", "33 namma", Contract(Date(9, 2, 3910), Date(2, 3, 19912), true));
    //emp.push(e1);
    //emp.push(e2);
    //emp.push(e3);
    //EmployeeManager newe;
    //newe = emp.findAllEmployee("88", "ID");
    //cout << newe;
    //CommodityManager storage;
    //readData(storage, "Guitar", "../Data/Guitar.txt");
    //readData(storage, "Accessory", "../Data/Accessory.txt");
    //cout << storage;

    //CommodityManager commodityManager;
    //Guitar g1(storage.getGuitar(1));
    //g1.setQuantity(1);
    //Accessory a1(storage.getAccessory(0));
    //a1.setQuantity(1);
    //Accessory a2(storage.getAccessory(1));
    //a2.setQuantity(2);
    //commodityManager.push(g1);
    //commodityManager.push(a1);
    //commodityManager.push(a2);
    //Receipt r1("1023123", "Hieu", commodityManager, Date(10, 12, 2021));
    //Guitar g2(storage.getGuitar(2));
    //g2.setQuantity(1);
    //commodityManager.push(g2);
    //Receipt r2("1022013", "Nam", commodityManager, Date(10, 12, 2020));
    //ReceiptManager manager;
    //manager.addReceipt(r1, storage);
    //manager.addReceipt(r2, storage);
    //writeData(manager, "../Data/Receipt.txt");
    //EmployeeManager empManager;
    //readData(empManager, "../Data/Employee.txt");


    //ReceiptManager rpt;
    //readData(rpt, storage, "../Data/Receipt.txt");
    //cout << rpt;

    //string str;
    //ofstream fo;
    //fo.open("../Data/test.txt");
    //fo << "\t10219 djdj";
    //fo.close();
    //ifstream fi;
    //fi.open("../Data/test.txt");
    //getline(fi, str);
    //cout << str.find('1') << " " << str.length();
    //cout << endl << str.substr(1, str.find(" "));
    //cout << endl;
    //cout << str;
    //fi.close();
    EmployeeManager emp;
    readData(emp, "../Data/Employee.txt");
    EmployeeManager temp = emp.findAllEmployee("Nguyen Kim", "Name");
    cout << temp;
    return 0;
}
