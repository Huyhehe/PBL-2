#include <iostream>
#include "CommodityManager.h"
#include "EmployeeManager.h"
#include "ReceiptManager.h"
#include "menu.h"
#include "InputMethod.h"
#include <fstream>
#include <string>

using namespace std;

int main() {
    CommodityManager storage;
    EmployeeManager manager;
    ReceiptManager receiptStored;
    readData(storage, "Guitar", "../Data/Guitar.txt");
    readData(storage, "Accessory", "../Data/Accessory.txt");
    readData(manager, "../Data/Employee.txt");
    readData(receiptStored,"../Data/Receipt.txt");
    mainMenu(manager, storage, receiptStored);
    storage.sort("Guitar", "Full Name");
    storage.sort("Accessory", "Full Name");
    manager.sort("Last Name");
    receiptStored.sort("Date");
    writeData(storage, "Guitar", "../Data/Guitar.txt");
    writeData(storage, "Accessory", "../Data/Accessory.txt");
    writeData(manager, "../Data/Employee.txt");
    writeData(receiptStored, "../Data/Receipt.txt");
    return 0;
}
