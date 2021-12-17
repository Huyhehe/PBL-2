#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
//#include <windows.h>
#include "ReceiptManager.h"
#include "CommodityManager.h"
#include "EmployeeManager.h"
#include "InputMethod.h"

using namespace std;

string toString(int x);
//string setColor(int color);
void employeeBoard(EmployeeManager&, string);
void accessoryBoard(CommodityManager&, string);
void guitarBoard(CommodityManager&, string);
void accessoryMenu(EmployeeManager&, CommodityManager&, ReceiptManager&);
void guitarMenu(EmployeeManager&, CommodityManager&, ReceiptManager&);
void storageMenu(EmployeeManager&, CommodityManager&, ReceiptManager&);
void guestMenu(EmployeeManager&, CommodityManager&, ReceiptManager&);
void employeeMenu(EmployeeManager&, CommodityManager&, ReceiptManager&);
void receiptMenu(EmployeeManager&, CommodityManager&, ReceiptManager&);
void manageMenu(EmployeeManager&, CommodityManager&, ReceiptManager&);
void mainMenu(EmployeeManager&, CommodityManager&, ReceiptManager&);


void mainMenu(EmployeeManager& manager, CommodityManager& storage, ReceiptManager& receiptStored) {
    string choice;
    system("cls");
    //system("Color 07");
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                   GUITAR STORE                   +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                    MAIN MENU                     +" << endl
         << "+ 1. Quan ly                                       +" << endl
         << "+ 2. In hoa don                                    +" << endl
         << "+ 3. Thoat                                         +" << endl
         << "+                                                  +" << endl
         << "+                                                  +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Nhap lua chon: ";
    cin >> choice;
    cin.ignore();
    if (choice.length() > 1 || choice < "1" || choice > "3") {
        do {
            cout << "Lua chon khong hop le, vui long chon lai: ";
            cin >> choice;
            cin.ignore();
        } while(choice.length() > 1 || choice < "1" || choice > "3");
    }
    int intChoice = 0;
    if (choice == "1") {
        intChoice = 1;
    }
    if (choice == "2") {
        intChoice = 2;
    }
    if (choice == "3") {
        intChoice = 3;
    }
    switch(intChoice) {
        case 1: {
            system("cls");
            manageMenu(manager, storage, receiptStored);
            break;
        }
        case 2: {
            system("cls");
            receiptMenu(manager, storage, receiptStored);
        }
        case 3: {
            system("cls");
            cout << "DA THOAT!";
            break;
        }
        default: break;
    }
}

void manageMenu(EmployeeManager& manager, CommodityManager& storage, ReceiptManager& receiptStored) {
    system("cls");
    system("Color 07");
    string choice;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                   GUITAR STORE                   +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                     QUAN LY                      +" << endl
         << "+ 1. Nhan vien                                     +" << endl
         << "+ 2. Kho                                           +" << endl
         << "+ 3. Quay lai                                      +" << endl
         << "+ 4. Thoat                                         +" << endl
         << "+                                                  +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Nhap lua chon: ";
    cin >> choice;
    cin.ignore();
    if (choice.length() > 1 || choice < "1" || choice > "4") {
        do {
            cout << "Lua chon khong hop le, vui long chon lai: ";
            cin >> choice;
            cin.ignore();
        } while(choice.length() > 1 || choice < "1" || choice > "4");
    }
    int intChoice = 0;
    if (choice == "1") {
        intChoice = 1;
    }
    if (choice == "2") {
        intChoice = 2;
    }
    if (choice == "3") {
        intChoice = 3;
    }
    if (choice == "4") {
        intChoice = 4;
    }
    switch(intChoice) {
        case 1: {
            system("cls");
            employeeMenu(manager, storage, receiptStored);
            break;
        }
        case 2: {
            system("cls");
            storageMenu(manager, storage, receiptStored);
            break;
        }
        case 3: {
            //go back
            system("cls");
            mainMenu(manager, storage, receiptStored);
            break;
        }
        case 4: {
            system("cls");
            cout << "DA THOAT!";
            break;
        }
        default: {
            break;
        }
    }
}

bool checkContinue(string continueOption) {
    if (continueOption != "Y" && continueOption != "y" && continueOption != "N" && continueOption != "n") {
        do {
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            cin >> continueOption;
            cin.ignore();
        } while (continueOption != "Y" && continueOption != "y" && continueOption != "N" && continueOption != "n");
    }
    if (continueOption == "Y" || continueOption == "y") {
        return 1;
    }
    else if (continueOption == "N" || continueOption == "n"){
        return 0;
    }
    return 0;
}

void receiptMenu(EmployeeManager& manager, CommodityManager& storage, ReceiptManager& receiptStored) {
    tryAgain:
    system("cls");
    //system("Color 0A");
    string choice;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                   GUITAR STORE                   +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                    HOA DON                       +" << endl
         << "+ 1. Xem toan bo hoa don                           +" << endl
         << "+ 2. Them hoa don                                  +" << endl
         << "+ 3. Xoa hoa don                                   +" << endl
         << "+ 4. Tim kiem hoa don                              +" << endl
         << "+ 5. Quay lai                                      +" << endl
         << "+ 6. Thoat                                         +" << endl
         << "+                                                  +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Nhap lua chon: ";
    cin >> choice;
    cin.ignore();
    if (choice.length() > 1 || choice < "1" || choice > "6") {
        do {
            cout << "Lua chon khong hop le, vui long chon lai: ";
            cin >> choice;
            cin.ignore();
        } while(choice.length() > 1 || choice < "1" || choice > "6");
    }
    int intChoice = 0;
    if (choice == "1") {
        intChoice = 1;
    }
    if (choice == "2") {
        intChoice = 2;
    }
    if (choice == "3") {
        intChoice = 3;
    }
    if (choice == "4") {
        intChoice = 4;
    }
    if (choice == "5") {
        intChoice = 5;
    }
    if (choice == "6") {
        intChoice = 6;
    }
    switch(intChoice) {
        case 1: {
            system("cls");
            receiptStored.sort("Date");
            cout << receiptStored;
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 2: {
            system("cls");
            receiptStored.addReceipt(storage);
            receiptStored.sort("Data");
            cout << "Them hoa don thanh cong!" << endl;
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 3: {
            system("cls");
            string str;
            string option;
            int choice;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+                   GUITAR STORE                   +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+         LUA CHON THONG TIN TIM KIEM DE XOA       +" << endl
                 << "+ 1. Ma hoa don                                    +" << endl
                 << "+ 2. Ten khach hang                                +" << endl
                 << "+ 3. Ngay xuat hoa don                             +" << endl
                 << "+                                                  +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "Nhap lua chon: ";
            getline(cin, str);
            while ((str < "1" || str > "9") || (stoi(str) < 1 || stoi(str) > 3)) {
                cout << "lua chon khong phu hop, vui long thu lai: ";
                getline(cin, str);
            }
            choice = stoi(str);
            switch(choice) {
                case 1:
                    option = "ID";
                    break;
                case 2:
                    option = "Customer Name";
                    break;
                case 3:
                    option = "Date";
                    break;
            }
            cout << "Nhap thong tin: ";
            getline(cin, str);
            cout << receiptStored.findAllReceipt(str, option);
            cout << "Nhap ma hoa don can xoa: ";
            getline(cin, str);
            receiptStored.remove(receiptStored[receiptStored.indexOf(str)]);
            cout << "Xoa hoa don thanh cong!" << endl;
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 4: {
            system("cls");
            string str;
            string option;
            int choice;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+                   GUITAR STORE                   +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+            LUA CHON THONG TIN TIM KIEM           +" << endl
                 << "+ 1. Ma hoa don                                    +" << endl
                 << "+ 2. Ten khach hang                                +" << endl
                 << "+ 3. Ngay xuat hoa don                             +" << endl
                 << "+                                                  +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "Nhap lua chon: ";
            getline(cin, str);
            while ((str < "1" || str > "9") || (stoi(str) < 1 || stoi(str) > 3)) {
                cout << "lua chon khong phu hop, vui long thu lai: ";
                getline(cin, str);
            }
            choice = stoi(str);
            switch(choice) {
                case 1:
                    option = "ID";
                    break;
                case 2:
                    option = "Customer Name";
                    break;
                case 3:
                    option = "Date";
                    break;
            }
            cout << "Nhap thong tin: ";
            getline(cin, str);
            system("cls");
            cout << receiptStored.findAllReceipt(str, option);
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 5: {
            //go back
            system("cls");
            mainMenu(manager, storage, receiptStored);
            break;
        }
        case 6: {
            system("cls");
            cout << "DA THOAT!";
            break;
        }
        default: {
            break;
        }
    }
}

void employeeMenu(EmployeeManager& manager, CommodityManager& storage, ReceiptManager& receiptStored) {
    tryAgain:
    system("cls");
    //system("Color 07");
    string choice;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                   GUITAR STORE                   +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                    NHAN VIEN                     +" << endl
         << "+ 1. Them nhan vien                                +" << endl
         << "+ 2. Xoa nhan vien                                 +" << endl
         << "+ 3. Chinh sua thong tin nhan vien                 +" << endl
         << "+ 4. Thong tin cua tat ca nhan vien                +" << endl
         << "+ 5. Tim kiem nhan vien                            +" << endl
         << "+ 6. Quay lai                                      +" << endl
         << "+ 7. Thoat                                         +" << endl
         << "+                                                  +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Nhap lua chon: ";
    cin >> choice;
    cin.ignore();
    if (choice.length() > 1 || choice < "1" || choice > "7") {
        do {
            cout << "Lua chon khong hop le, vui long chon lai: ";
            cin >> choice;
            cin.ignore();
        } while(choice.length() > 1 || choice < "1" || choice > "7");
    }
    int intChoice = 0;
    if (choice == "1") {
        intChoice = 1;
    }
    if (choice == "2") {
        intChoice = 2;
    }
    if (choice == "3") {
        intChoice = 3;
    }
    if (choice == "4") {
        intChoice = 4;
    }
    if (choice == "5") {
        intChoice = 5;
    }
    if (choice == "6") {
        intChoice = 6;
    }
    if (choice == "7") {
        intChoice = 7;
    }
    switch(intChoice) {
        case 1: {
            system("cls");
            //system("Color 0A");
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+                   GUITAR STORE                   +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+                  THEM NHAN VIEN                  +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cin >> manager;
            cin.ignore();
            manager.sort("Last Name");
            cout << "Them nhan vien thanh cong" << endl
                 << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            }
            break;
        }
        case 2: {
            system("cls");
            string str;
            string option;
            int choice;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+                   GUITAR STORE                   +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+         LUA CHON THONG TIN TIM KIEM DE XOA       +" << endl
                 << "+ 1. Ma nhan vien                                  +" << endl
                 << "+ 2. Ho va ten Nhan Vien                           +" << endl
                 << "+ 3. Ten nhan vien                                 +" << endl
                 << "+ 4. Ngay sinh                                     +" << endl
                 << "+ 5. Gioi tinh                                     +" << endl
                 << "+ 6. So dien thoai                                 +" << endl
                 << "+ 7. Email                                         +" << endl
                 << "+ 8. Dia chi                                       +" << endl
                 << "+ 9. Ngay bat dau lam viec                         +" << endl
                 << "+ 10. Ngay het hop dong lam viec                   +" << endl
                 << "+ 11. Tien luong                                   +" << endl
                 << "+                                                  +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "Nhap lua chon: ";
            getline(cin, str);
            while ((str < "1" || str > "9") || (stoi(str) < 1 || stoi(str) > 11)) {
                cout << "lua chon khong phu hop, vui long thu lai: ";
                getline(cin, str);
            }
            choice = stoi(str);
            switch(choice) {
                case 1:
                    option = "ID";
                    break;
                case 2:
                    option = "Full Name";
                    break;
                case 3:
                    option = "Name";
                    break;
                case 4:
                    option = "Date Of Birth";
                    break;
                case 5:
                    option = "Gender";
                    break;
                case 6:
                    option = "Phone";
                    break;
                case 7:
                    option = "Email";
                    break;
                case 8:
                    option = "Address";
                    break;
                case 9:
                    option = "Date In";
                    break;
                case 10:
                    option = "Date Out";
                    break;
                case 11:
                    option = "Salary";
                    break;
            }
            cout << "Nhap thong tin: ";
            getline(cin, str);
            manager.deleteEmployee(str, option);
            //system("cls");
            //cout << "Xoa nhan vien thanh cong!" << endl
            //     << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 3: {
            system("cls");
            string str;
            string option;
            int choice;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+                   GUITAR STORE                   +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+      LUA CHON THONG TIN TIM KIEM DE CHINH SUA    +" << endl
                 << "+ 1. Ma nhan vien                                  +" << endl
                 << "+ 2. Ho va ten Nhan Vien                           +" << endl
                 << "+ 3. Ten nhan vien                                 +" << endl
                 << "+ 4. Ngay sinh                                     +" << endl
                 << "+ 5. Gioi tinh                                     +" << endl
                 << "+ 6. So dien thoai                                 +" << endl
                 << "+ 7. Email                                         +" << endl
                 << "+ 8. Dia chi                                       +" << endl
                 << "+ 9. Ngay bat dau lam viec                         +" << endl
                 << "+ 10. Ngay het hop dong lam viec                   +" << endl
                 << "+ 11. Tien luong                                   +" << endl
                 << "+                                                  +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "Nhap lua chon: ";
            getline(cin, str);
            while ((str < "1" || str > "9") || (stoi(str) < 1 || stoi(str) > 11)) {
                cout << "lua chon khong phu hop, vui long thu lai: ";
                getline(cin, str);
            }
            choice = stoi(str);
            switch(choice) {
                case 1:
                    option = "ID";
                    break;
                case 2:
                    option = "Full Name";
                    break;
                case 3:
                    option = "Name";
                    break;
                case 4:
                    option = "Date Of Birth";
                    break;
                case 5:
                    option = "Gender";
                    break;
                case 6:
                    option = "Phone";
                    break;
                case 7:
                    option = "Email";
                    break;
                case 8:
                    option = "Address";
                    break;
                case 9:
                    option = "Date In";
                    break;
                case 10:
                    option = "Date Out";
                    break;
                case 11:
                    option = "Salary";
                    break;
            }
            cout << "Nhap thong tin: ";
            getline(cin, str);
            manager.updateData(str, option);
            manager.sort("Last Name");
            //system("cls");
            //cout << "Chinh sua thong tin nhan vien thanh cong!" << endl
            //     << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 4: {
            system("cls");
            employeeBoard(manager, "../Data/Employee.txt");
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 5: {
            system("cls");
            string str;
            string option;
            int choice;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+                   GUITAR STORE                   +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+            LUA CHON THONG TIN TIM KIEM           +" << endl
                 << "+ 1. Ma nhan vien                                  +" << endl
                 << "+ 2. Ho va ten Nhan Vien                           +" << endl
                 << "+ 3. Ten nhan vien                                 +" << endl
                 << "+ 4. Ngay sinh                                     +" << endl
                 << "+ 5. Gioi tinh                                     +" << endl
                 << "+ 6. So dien thoai                                 +" << endl
                 << "+ 7. Email                                         +" << endl
                 << "+ 8. Dia chi                                       +" << endl
                 << "+ 9. Ngay bat dau lam viec                         +" << endl
                 << "+ 10. Ngay het hop dong lam viec                   +" << endl
                 << "+ 11. Tien luong                                   +" << endl
                 << "+                                                  +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "Nhap lua chon: ";
            getline(cin, str);
            while ((str < "1" || str > "9") || (stoi(str) < 1 || stoi(str) > 11)) {
                cout << "lua chon khong phu hop, vui long thu lai: ";
                getline(cin, str);
            }
            choice = stoi(str);
            switch(choice) {
                case 1:
                    option = "ID";
                    break;
                case 2:
                    option = "Full Name";
                    break;
                case 3:
                    option = "Name";
                    break;
                case 4:
                    option = "Date Of Birth";
                    break;
                case 5:
                    option = "Gender";
                    break;
                case 6:
                    option = "Phone";
                    break;
                case 7:
                    option = "Email";
                    break;
                case 8:
                    option = "Address";
                    break;
                case 9:
                    option = "Date In";
                    break;
                case 10:
                    option = "Date Out";
                    break;
                case 11:
                    option = "Salary";
                    break;
            }
            cout << "Nhap thong tin: ";
            getline(cin, str);
            EmployeeManager emp;
            if (option != "Name")
                emp = manager.findAllEmployee(str, option);
            else
                emp = manager.findAllLastName(str);
            if (emp.getNumberOfEmployee() == 0)
                cout << "Khong tim thay nhan vien co thong tin tuong ung!";
            else
                employeeBoard(emp, "../Data/Employee.txt");
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }

        }
        case 6: {
            //go back
            system("cls");
            manageMenu(manager, storage, receiptStored);
            break;
        }
        case 7: {
            system("cls");
            cout << "DA THOAT!";
            break;
        }
        default: {
            break;
        }
    }
}

void storageMenu(EmployeeManager& manager, CommodityManager& storage, ReceiptManager& receiptStored) {
    system("cls");
    //system("Color 07");
    string choice;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                   GUITAR STORE                   +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                       KHO                        +" << endl
         << "+ 1. Guitar                                        +" << endl
         << "+ 2. Phu kien                                      +" << endl
         << "+ 3. Quay lai                                      +" << endl
         << "+ 4. Thoat                                         +" << endl
         << "+                                                  +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Nhap lua chon: ";
    cin >> choice;
    cin.ignore();
    if (choice.length() > 1 || choice < "1" || choice > "4") {
        do {
            cout << "Lua chon khong hop le, vui long chon lai: ";
            cin >> choice;
            cin.ignore();
        } while(choice.length() > 1 || choice < "1" || choice > "4");
    }
    int intChoice = 0;
    if (choice == "1") {
        intChoice = 1;
    }
    if (choice == "2") {
        intChoice = 2;
    }
    if (choice == "3") {
        intChoice = 3;
    }
    if (choice == "4") {
        intChoice = 4;
    }
    switch(intChoice) {
        case 1: {
            system("cls");
            guitarMenu(manager, storage, receiptStored);
            break;
        }
        case 2: {
            system("cls");
            accessoryMenu(manager, storage, receiptStored);
            break;
        }
        case 3: {
            //go back
            system("cls");
            manageMenu(manager, storage, receiptStored);
            break;
        }
        case 4: {
            system("cls");
            cout << "DA THOAT!";
            break;
        }
        default: {
            break;
        }
    }
}

void guitarMenu(EmployeeManager& manager, CommodityManager& storage, ReceiptManager& receiptStored) {
    tryAgain:
    system("cls");
    //system("Color 07");
    string choice;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                   GUITAR STORE                   +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                      GUITAR                      +" << endl
         << "+ 1. Xem tat ca                                    +" << endl
         << "+ 2. Tim kiem                                      +" << endl
         << "+ 3. Them vao kho                                  +" << endl
         << "+ 4. Xoa khoi kho                                  +" << endl
         << "+ 5. Chinh sua thong tin guitar                    +" << endl
         << "+ 6. Quay lai                                      +" << endl
         << "+ 7. Thoat                                         +" << endl
         << "+                                                  +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Nhap lua chon: ";
    cin >> choice;
    cin.ignore();
    if (choice.length() > 1 || choice < "1" || choice > "7") {
        do {
            cout << "Lua chon khong hop le, vui long chon lai: ";
            cin >> choice;
            cin.ignore();
        } while(choice.length() > 1 || choice < "1" || choice > "7");
    }
    int intChoice = 0;
    if (choice == "1") {
        intChoice = 1;
    }
    if (choice == "2") {
        intChoice = 2;
    }
    if (choice == "3") {
        intChoice = 3;
    }
    if (choice == "4") {
        intChoice = 4;
    }
    if (choice == "5") {
        intChoice = 5;
    }
    if (choice == "6") {
        intChoice = 6;
    }
    if (choice == "7") {
        intChoice = 7;
    }
    switch(intChoice) {
        case 1: {
            system("cls");
            guitarBoard(storage, "../Data/Guitar.txt");
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 2: {
            system("cls");
            string str;
            string option;
            int choice;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+                   GUITAR STORE                   +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+         LUA CHON THONG TIN MUON TIM KIEM         +" << endl
                 << "+ 1. Ma guitar                                     +" << endl
                 << "+ 2. Ten thuong hieu                               +" << endl
                 << "+ 3. Ten guitar                                    +" << endl
                 << "+ 4. So luong guitar co trong kho                  +" << endl
                 << "+ 5. Gia guitar                                    +" << endl
                 << "+                                                  +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "Nhap lua chon: ";
            getline(cin, str);
            while ((str < "1" || str > "9") || (stoi(str) < 1 || stoi(str) > 6)) {
                cout << "lua chon khong phu hop, vui long thu lai: ";
                getline(cin, str);
            }
            choice = stoi(str);
            switch(choice) {
                case 1:
                    option = "ID";
                    break;
                case 2:
                    option = "Brand";
                    break;
                case 3:
                    option = "Name";
                    break;
                case 4:
                    option = "Quantity";
                    break;
                case 5:
                    option = "Price";
                    break;
                default:
                    break;
            }
            cout << "Nhap thong tin tim kiem: ";
            getline(cin, str);
            CommodityManager commodity;
            if (option != "Name" && option != "Brand")
                commodity = storage.findAllCommodity(str, option, "Guitar");
            else
                commodity = storage.findAllName(str, "Guitar");
            if (commodity.getNumberOfGuitar() == 0)
                cout << "Khong tim thay guitar co thong tin trung khop!" << endl;
            else
                guitarBoard(commodity, "../Data/Guitar.txt");
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 3: {
            system("cls");
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+                   GUITAR STORE                   +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+               THEM GUITAR VAO KHO                +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            storage.addGuitar();
            storage.sort("Guitar", "Full Name");
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 4: {
            system("cls");
            string str;
            string option;
            int choice;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+                   GUITAR STORE                   +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+      LUA CHON THONG TIN MUON TIM KIEM DE XOA     +" << endl
                 << "+ 1. Ma guitar                                     +" << endl
                 << "+ 2. Ten thuong hieu                               +" << endl
                 << "+ 3. Ten guitar                                    +" << endl
                 << "+ 4. So luong guitar co trong kho                  +" << endl
                 << "+ 5. Gia guitar                                    +" << endl
                 << "+                                                  +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "Nhap lua chon: ";
            getline(cin, str);
            while ((str < "1" || str > "9") || (stoi(str) < 1 || stoi(str) > 5)) {
                cout << "lua chon khong phu hop, vui long thu lai: ";
                getline(cin, str);
            }
            choice = stoi(str);
            switch(choice) {
                case 1:
                    option = "ID";
                    break;
                case 2:
                    option = "Full Name";
                    break;
                case 3:
                    option = "Full Name";
                    break;
                case 4:
                    option = "Quantity";
                    break;
                case 5:
                    option = "Price";
                    break;
                default:
                    break;
            }
            cout << "Nhap thong tin: ";
            getline(cin, str);
            storage.deleteGuitar(str, option);
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 5: {
            system("cls");
            string str;
            string option;
            int choice;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+                   GUITAR STORE                   +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+  LUA CHON THONG TIN MUON TIM KIEM DE CHINH SUA   +" << endl
                 << "+ 1. Ma guitar                                     +" << endl
                 << "+ 2. Ten thuong hieu                               +" << endl
                 << "+ 3. Ten guitar                                    +" << endl
                 << "+ 4. So luong guitar co trong kho                  +" << endl
                 << "+ 5. Gia guitar                                    +" << endl
                 << "+                                                  +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "Nhap lua chon: ";
            getline(cin, str);
            while ((str < "1" || str > "9") || (stoi(str) < 1 || stoi(str) > 6)) {
                cout << "lua chon khong phu hop, vui long thu lai: ";
                getline(cin, str);
            }
            choice = stoi(str);
            switch(choice) {
                case 1:
                    option = "ID";
                    break;
                case 2:
                    option = "Full Name";
                    break;
                case 3:
                    option = "Full Name";
                    break;
                case 4:
                    option = "Quantity";
                    break;
                case 5:
                    option = "Price";
                    break;
                default:
                    break;
            }
            cout << "Nhap thong tin: ";
            getline(cin, str);
            storage.updateGuitar(str, option);
            storage.sort("Guitar","Full Name");
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 6: {
            //go back
            system("cls");
            storageMenu(manager, storage, receiptStored);
            break;
        }
        case 7: {
            system("cls");
            cout << "DA THOAT!";
            break;
        }
        default: {
            break;
        }
    }
}

void accessoryMenu(EmployeeManager& manager, CommodityManager& storage, ReceiptManager& receiptStored) {
    tryAgain:
    system("cls");
    //system("Color 07");
    string choice;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                   GUITAR STORE                   +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                     PHU KIEN                     +" << endl
         << "+ 1. Xem tat ca                                    +" << endl
         << "+ 2. Tim kiem                                      +" << endl
         << "+ 3. Them vao kho                                  +" << endl
         << "+ 4. Xoa khoi kho                                  +" << endl
         << "+ 5. Chinh sua thong tin phu kien                  +" << endl
         << "+ 6. Quay lai                                      +" << endl
         << "+ 7. Thoat                                         +" << endl
         << "+                                                  +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Nhap lua chon: ";
    cin >> choice;
    cin.ignore();
    if (choice.length() > 1 || choice < "1" || choice > "7") {
        do {
            cout << "Lua chon khong hop le, vui long chon lai: ";
            cin >> choice;
            cin.ignore();
        } while(choice.length() > 1 || choice < "1" || choice > "7");
    }
    int intChoice = 0;
    if (choice == "1") {
        intChoice = 1;
    }
    if (choice == "2") {
        intChoice = 2;
    }
    if (choice == "3") {
        intChoice = 3;
    }
    if (choice == "4") {
        intChoice = 4;
    }
    if (choice == "5") {
        intChoice = 5;
    }
    if (choice == "6") {
        intChoice = 6;
    }
    if (choice == "7") {
        intChoice = 7;
    }
    switch(intChoice) {
        case 1: {
            system("cls");
            //system("Color 0A");
            accessoryBoard(storage, "../Data/Accessory.txt");
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 2: {
            system("cls");
            // system("Color 0A");
            string str;
            string option;
            int choice;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+                   GUITAR STORE                   +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+         LUA CHON THONG TIN MUON TIM KIEM         +" << endl
                 << "+ 1. Ma phu kien                                   +" << endl
                 << "+ 2. Loai phu kien                                 +" << endl
                 << "+ 3. Ten phu kien                                  +" << endl
                 << "+ 4. So luong phu kien co trong kho                +" << endl
                 << "+ 5. Gia phu kien                                  +" << endl
                 << "+                                                  +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "Nhap lua chon: ";
            string temp;
            getline(cin, temp);
            while ((temp < "1" || temp > "9") || (stoi(temp) < 1 || stoi(temp) > 5)) {
                cout << "lua chon khong phu hop, vui long thu lai: ";
                getline(cin, temp);
            }
            choice = stoi(temp);
            switch(choice) {
                case 1:
                    option = "ID";
                    break;
                case 2:
                    option = "Type";
                    break;
                case 3:
                    option = "Name";
                    break;
                case 4:
                    option = "Quantity";
                    break;
                case 5:
                    option = "Price";
                    break;
                default:
                    break;
            }
            cout << "Nhap thong tin tim kiem: ";
            getline(cin, str);
            CommodityManager commodity;
            if (option != "Name")
                commodity = storage.findAllCommodity(str, option, "Accessory");
            else
                commodity = storage.findAllName(str, "Accessory");
            if (commodity.getNumberOfAccessory() == 0)
                cout << "Khong tim thay phu kien co thong tin trung khop!" << endl;
            else
                accessoryBoard(commodity, "../Data/Accessory.txt");
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 3: {
            system("cls");
            // system("Color 0A");
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+                   GUITAR STORE                   +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+               THEM PHU KIEN VAO KHO              +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            storage.addAccessory();
            storage.sort("Accessory", "Full Name");
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 4: {
            system("cls");
            // system("Color 0A");
            string str;
            string option;
            int choice;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+                   GUITAR STORE                   +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+      LUA CHON THONG TIN MUON TIM KIEM DE XOA     +" << endl
                 << "+ 1. Ma phu kien                                   +" << endl
                 << "+ 2. Loai phu kien                                 +" << endl
                 << "+ 3. Ten phu kien                                  +" << endl
                 << "+ 4. So luong phu kien co trong kho                +" << endl
                 << "+ 5. Gia phu kien                                  +" << endl
                 << "+                                                  +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "Nhap lua chon: ";
            getline(cin, str);
            while ((str < "1" || str > "9") || (stoi(str) < 1 || stoi(str) > 5)) {
                cout << "lua chon khong phu hop, vui long thu lai: ";
                getline(cin, str);
            }
            choice = stoi(str);
            switch(choice) {
                case 1:
                    option = "ID";
                    break;
                case 2:
                    option = "Type";
                    break;
                case 3:
                    option = "Name";
                    break;
                case 4:
                    option = "Quantity";
                    break;
                case 5:
                    option = "Price";
                    break;
                default:
                    break;
            }
            cout << "Nhap thong tin: ";
            getline(cin, str);
            storage.deleteAccessory(str, option);
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 5: {
            system("cls");
            string str;
            string option;
            int choice;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+                   GUITAR STORE                   +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+    LUA CHON THONG TIN MUON TIM KIEM CHINH SUA    +" << endl
                 << "+ 1. Ma phu kien                                   +" << endl
                 << "+ 2. Loai phu kien                                 +" << endl
                 << "+ 3. Ten phu kien                                  +" << endl
                 << "+ 4. So luong phu kien co trong kho                +" << endl
                 << "+ 5. Gia phu kien                                  +" << endl
                 << "+                                                  +" << endl
                 << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "Nhap lua chon: ";
            getline(cin, str);
            while ((str < "1" || str > "9") || (stoi(str) < 1 || stoi(str) > 5)) {
                cout << "lua chon khong phu hop, vui long thu lai: ";
                getline(cin, str);
            }
            choice = stoi(str);
            switch(choice) {
                case 1:
                    option = "ID";
                    break;
                case 2:
                    option = "Type";
                    break;
                case 3:
                    option = "Name";
                    break;
                case 4:
                    option = "Quantity";
                    break;
                case 5:
                    option = "Price";
                    break;
                default:
                    break;
            }
            cout << "Nhap thong tin: ";
            getline(cin, str);
            storage.updateAccessory(str, option);
            storage.sort("Accessory", "Full Name");
            string continueOption;
            cin >> continueOption;
            cin.ignore();
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 6: {
            //go back
            system("cls");
            storageMenu(manager, storage, receiptStored);
            break;
        }
        case 7: {
            system("cls");
            cout << "DA THOAT!";
            break;
        }
        default: {
            break;
        }
    }
}

void employeeBoard(EmployeeManager& manager, string fileName) {
    ifstream fileInput;
    fileInput.open(fileName, ios::in);
    cout << "+-----+----------+------------------------------+-----------+----+-----------+" << endl; //5, 10, 30, 11, 4, 11
    cout << "| STT |    ID    |            Ho ten            | Ngay sinh | GT |    SDT    |" << endl;
    cout << "+-----+----------+------------------------------+-----------+----+-----------+" << endl;
    //readData(manager, fileName);
    manager.sort("Last Name");
    for (int i = 0 ; i < manager.getNumberOfEmployee(); i++) {
        cout << "|" << toString(i + 1) << i + 1 << setw(3)
             << "|" << manager[i].getID() << setw(11 - manager[i].getID().length())
             << "|" << manager[i].getName() << setw(31 - manager[i].getName().length())
             << "|" << manager[i].getDateOfBirth() << setw(12 - manager[i].getDateOfBirth().getDate().length())
             << "|" << manager[i].getGender() << setw(5 - manager[i].getGender().length())
             << "|" << manager[i].getPhoneNumber() << setw(12 - manager[i].getPhoneNumber().length()) << "|" << endl;
    }
    cout << "+-----+----------+------------------------------+-----------+----+-----------+" << endl;
    fileInput.close();
}

void guitarBoard(CommodityManager& storage, string fileName) {
    ifstream fileInput;
    fileInput.open(fileName, ios::in);
    cout << "+-----+----------+-------------------+-----------+----+------------+----------+" << endl; //5, 10, 19, 11, 4, 12, 10
    cout << "| STT |    ID    |    Thuong hieu    |    Ten    | SL |  Gia tien  | Bao hanh |" << endl;
    cout << "+-----+----------+-------------------+-----------+----+------------+----------+" << endl;
    //readData(storage, "Guitar", fileName);
    storage.sort("Guitar", "Full Name");
    for (int i = 0 ; i < storage.getNumberOfGuitar(); i++) {
        cout << "|" << toString(i + 1) << i + 1 << setw(3)
             << "|" << storage.getGuitar(i).getID() << setw(11 - storage.getGuitar(i).getID().length())
             << "|" << storage.getGuitar(i).getBrand() << setw(20 - storage.getGuitar(i).getBrand().length())
             << "|" << storage.getGuitar(i).getName() << setw(12 - storage.getGuitar(i).getName().length())
             << "|" << storage.getGuitar(i).getQuantity() << setw(5 - to_string(storage.getGuitar(i).getQuantity()).length())
             << "|" << storage.getGuitar(i).getPrice() << setw(13 - to_string(storage.getGuitar(i).getPrice()).length())
             << "|" << storage.getGuitar(i).getWarrantyTime() << setw(11 - storage.getGuitar(i).getWarrantyTime().length()) << "|" << endl;
    }
    cout << "+-----+----------+-------------------+-----------+----+------------+----------+" << endl;
    fileInput.close();
}

void accessoryBoard(CommodityManager& storage, string fileName) {
    ifstream fileInput;
    fileInput.open(fileName, ios::in);
    cout << "+-----+----------+------------+-------------------+----+------------+----------------+" << endl; //10, 12, 13, 4, 12, 16
    cout << "| STT |    ID    |    Loai    |        Ten        | SL |  Gia tien  |    Bao hanh    |" << endl;
    cout << "+-----+----------+------------+-------------------+----+------------+----------------+" << endl;
    //readData(storage, "Accessory", fileName);
    storage.sort("Accessory", "Full Name");
    for (int i = 0 ; i < storage.getNumberOfAccessory(); i++) {
        cout << "|" << toString(i + 1) << i + 1<< setw(3)
             << "|" << storage.getAccessory(i).getID() << setw(11 - storage.getAccessory(i).getID().length())
             << "|" << storage.getAccessory(i).getTypeOfCommodity() << setw(13 - storage.getAccessory(i).getTypeOfCommodity().length())
             << "|" << storage.getAccessory(i).getName() << setw(20 - storage.getAccessory(i).getName().length())
             << "|" << storage.getAccessory(i).getQuantity() << setw(5 - to_string(storage.getAccessory(i).getQuantity()).length())
             << "|" << storage.getAccessory(i).getPrice() << setw(13 - to_string(storage.getAccessory(i).getPrice()).length())
             << "|" << storage.getAccessory(i).getWarrantyTime() << setw(17 - storage.getAccessory(i).getWarrantyTime().length()) << "|" << endl;
    }
    cout << "+-----+----------+------------+-------------------+----+------------+----------------+" << endl;
    fileInput.close();
}

//string setColor(int color)
//{
//	WORD colr;
//     HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
//     CONSOLE_SCREEN_BUFFER_INFO info;
//     if(GetConsoleScreenBufferInfo(out, &info))
//     {
//          colr = (info.wAttributes & 0xF0) + (color & 0x0F);
//          SetConsoleTextAttribute(out, colr);
//     }
//     return "";
//}

string toString(int x) {
    string str;
    if (x < 10) {
        str = "00";
    }
    else if (x >= 10 && x < 100) {
        str = "0";
    } else {
        str = "";
    }
    return str;
}
