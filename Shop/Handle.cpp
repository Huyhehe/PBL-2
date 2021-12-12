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
//    return 0;
//}
