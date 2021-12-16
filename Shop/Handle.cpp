//#include <iostream>
//#include "ReceiptManager.h"
//#include "InputMethod.cpp"
//
//using namespace std;
//
//int main() {
//    CommodityManager storage;
//    storage.push(Guitar("102203009", "epiphone", "DR-100", 5, 10000000, "1 nam"));
//    storage.push(Guitar("102200441", "Yamaha", "FT-300", 3, 300000, "1 nam"));
//    CommodityManager commodity;
//    commodity.push(Guitar("102203009", "epiphone", "DR-100", 2, 10000000, "1 nam"));
//    commodity.push(Guitar("102200441", "Yamaha", "FT-300", 1, 300000, "1 nam"));
//    Receipt rpt("102213", "Nguyen Nam", commodity, Date(8, 12, 2021));
//    ReceiptManager receiptManager;
//    receiptManager.addReceipt(rpt, storage);
//    cout << storage;
//    cout << receiptManager;
//    string str = "02/01/2002";
//    cout << str.substr(0, str.find("/")) << endl;
//    str = str.substr(str.find("/") + 1, str.length());
//    cout << str << endl;
//    cout << str.substr(0, str.find("/")) << endl;
//    str = str.substr(str.find("/") + 1, str.length());
//    cout << str;
//    Date date = stringToDate("10/11/2002");
//    cout << date;
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
    //storage.updateAccessory("Capo", "Full Name");
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
    //EmployeeManager emp;
    //readData(emp, "../Data/Employee.txt");
//    return 0;
//}
