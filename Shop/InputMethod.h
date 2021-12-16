#pragma once
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
                    i++;
                    break;
                case 1:
                    temp->setBrand(strip(getData(str)));
                    i++;
                    break;
                case 2:
                    temp->setName(strip(getData(str)));
                    i++;
                    break;
                case 3:
                    temp->setQuantity(stoi(strip(getData(str))));
                    i++;
                    break;
                case 4:
                    temp->setPrice(stoi(strip(getData(str))));
                    i++;
                    break;
                case 5:
                    temp->setWarrantyTime(strip(getData(str)));
                    i++;
                default:
                    break;
            }
        }
        delete temp;
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
                    i++;
                    break;
                case 1:
                    temp->setTypeOfCommodoty(strip(getData(str)));
                    i++;
                    break;
                case 2:
                    temp->setName(strip(getData(str)));
                    i++;
                    break;
                case 3:
                    temp->setQuantity(stoi(strip(getData(str))));
                    i++;
                    break;
                case 4:
                    temp->setPrice(stoi(strip(getData(str))));
                    i++;
                    break;
                case 5:
                    temp->setWarrantyTime(strip(getData(str)));
                    i++;
                default:
                    break;
            }
        }
        delete temp;
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
    delete temp;
    fileInput.close();
}

void readData(ReceiptManager& rptManager, const string& fileName) {
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
            rptManager.push(*temp);
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
                    if (str.find("+ Guitar") >= 0 && str.find("+ Guitar") <= str.length()) {
                        Guitar *guitar = new Guitar();
                        getline(fileInput, str);
                        if (str == "")
                            break;
                        guitar->setID(strip(getData(str)));
                        getline(fileInput, str);
                        if (str == "")
                            break;
                        guitar->setBrand(strip(getData(str)));
                        getline(fileInput, str);
                        if (str == "")
                            break;
                        guitar->setName(strip(getData(str)));
                        getline(fileInput, str);
                        if (str == "")
                            break;
                        guitar->setQuantity(stoi(strip(getData(str))));
                        getline(fileInput, str);
                        if (str == "")
                            break;
                        guitar->setPrice(stoi(strip(getData(str))));
                        getline(fileInput, str);
                        if (str == "")
                            break;
                        guitar->setWarrantyTime(strip(getData(str)));
                        temp->getCommodityManager().pushWithQuantity(*guitar, guitar->getQuantity());
                    }
                    if (str.find("Accessory") >= 0 && str.find("Accessory") <= str.length()) {
                        Accessory *accessory= new Accessory();
                        getline(fileInput, str);
                        if (str == "")
                            break;
                        accessory->setID(strip(getData(str)));
                        getline(fileInput, str);
                        if (str == "")
                            break;
                        accessory->setTypeOfCommodoty(strip(getData(str)));
                        getline(fileInput, str);
                        if (str == "")
                            break;
                        accessory->setName(strip(getData(str)));
                        getline(fileInput, str);
                        if (str == "")
                            break;
                        accessory->setQuantity(stoi(strip(getData(str))));
                        getline(fileInput, str);
                        if (str == "")
                            break;
                        accessory->setPrice(stoi(strip(getData(str))));
                        getline(fileInput, str);
                        if (str == "")
                            break;
                        accessory->setWarrantyTime(strip(getData(str)));
                        temp->getCommodityManager().pushWithQuantity(*accessory, accessory->getQuantity());
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

void writeData(ReceiptManager& receiptManager, const string& fileName) {
    ofstream fileOutput;
    fileOutput.open(fileName, ios::out);
    for (int i = 0; i < receiptManager.getNumberOfReceipt(); i++) {
        fileOutput << "Ma hoa don: " << receiptManager[i].getID() << endl;
        fileOutput << "Ten khach hang: " << receiptManager[i].getCustomerName() << endl;
        fileOutput << "Hang hoa: " << endl;
        for (int j = 0; j < receiptManager[i].getCommodity().getNumberOfGuitar(); j++) {
            fileOutput << "\t" << "+ Guitar" << endl;
            fileOutput << "\tMa guitar: " << receiptManager[i].getCommodity().getGuitar(j).getID() << endl;
            fileOutput << "\tTen thuong hieu: " << receiptManager[i].getCommodity().getGuitar(j).getBrand() << endl;
            fileOutput << "\tTen guitar: " << receiptManager[i].getCommodity().getGuitar(j).getName() << endl;
            fileOutput << "\tSo luong guitar: " << receiptManager[i].getCommodity().getGuitar(j).getQuantity() << endl;
            fileOutput << "\tGia: " << receiptManager[i].getCommodity().getGuitar(j).getPrice() << endl;
            fileOutput << "\tThoi gian bao hanh: " << receiptManager[i].getCommodity().getGuitar(j).getWarrantyTime() << endl;
            fileOutput << endl;
        }
        for (int j = 0; j < receiptManager[i].getCommodity().getNumberOfAccessory(); j++) {
            fileOutput << "\t" << "+ Accessory" << endl;
            fileOutput << "\tMa phu kien: " << receiptManager[i].getCommodity().getAccessory(j).getID() << endl;
            fileOutput << "\tLoai phu kien: " << receiptManager[i].getCommodity().getAccessory(j).getTypeOfCommodity() << endl;
            fileOutput << "\tTen phu kien: " << receiptManager[i].getCommodity().getAccessory(j).getName() << endl;
            fileOutput << "\tSo luong phu kien: " << receiptManager[i].getCommodity().getAccessory(j).getQuantity() << endl;
            fileOutput << "\tGia: " << receiptManager[i].getCommodity().getAccessory(j).getPrice() << endl;
            fileOutput << "\tThoi gian bao hanh: " << receiptManager[i].getCommodity().getAccessory(j).getWarrantyTime() << endl;
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

void writeData(EmployeeManager& manager, const string& fileName) {
    ofstream fileOutput;
    fileOutput.open(fileName, ios::out);
    for (int i = 0; i < manager.getNumberOfEmployee(); i++) {
        fileOutput << "Ma nhan vien: " << manager[i].getID() << endl;
        fileOutput << "Ho ten nhan vien: " << manager[i].getName() << endl;
        fileOutput << "Ngay sinh: " << manager[i].getDateOfBirth().getDate() << endl;
        fileOutput << "Gioi tinh: " << manager[i].getGender() << endl;
        fileOutput << "So dien thoai: " << manager[i].getPhoneNumber() << endl;
        fileOutput << "Email: " << manager[i].getEmail() << endl;
        fileOutput << "Dia chi: " << manager[i].getAddress() << endl;
        fileOutput << "Ngay bat dau lam viec: " << manager[i].getContract().Contract_getDateIn().getDate() << endl;
        fileOutput << "Ngay het hop dong lam viec: " << manager[i].getContract().Contract_getDateOut().getDate() << endl;
        if (manager[i].getContract().Contract_getIsFullTime())
            fileOutput << "La nhan vien toan thoi gian: " << "true" << endl;
        else
            fileOutput << "La nhan vien toan thoi gian: " << "false" << endl;
        fileOutput << "Tien luong: " << manager[i].getSalary() << endl;
        fileOutput << endl;
    }
    fileOutput.close();
}

void writeData(CommodityManager& storage, const string& commodity, const string& fileName) {
    ofstream fileOutput;
    fileOutput.open(fileName, ios::out);
    if (commodity == "Guitar") {
        for (int i = 0; i < storage.getNumberOfGuitar(); i++) {
            fileOutput << "Ma guitar: " << storage.getGuitar(i).getID() << endl;
            fileOutput << "Thuong Hieu: " << storage.getGuitar(i).getBrand() << endl;
            fileOutput << "Ten guitar: " << storage.getGuitar(i).getName() << endl;
            fileOutput << "So luong: " << storage.getGuitar(i).getQuantity() << endl;
            fileOutput << "Gia: " << storage.getGuitar(i).getPrice() << endl;
            fileOutput << "Thoi gian bao hanh: " << storage.getGuitar(i).getWarrantyTime() << endl;
            fileOutput << endl;
        }
    }

    if (commodity == "Accessory") {
        for (int i = 0; i < storage.getNumberOfAccessory(); i++) {
            fileOutput << "Ma phu kien: " << storage.getAccessory(i).getID() << endl;
            fileOutput << "Loai phu kien: " << storage.getAccessory(i).getTypeOfCommodity() << endl;
            fileOutput << "Ten phu kien: " << storage.getAccessory(i).getName() << endl;
            fileOutput << "So luong:" << storage.getAccessory(i).getQuantity() << endl;
            fileOutput << "Gia: " << storage.getAccessory(i).getPrice() << endl;
            fileOutput << "Thoi gian bao hanh: " << storage.getAccessory(i).getWarrantyTime() << endl;
            fileOutput << endl;
        }
    }
}
