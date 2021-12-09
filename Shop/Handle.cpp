#include <iostream>
#include "ReceiptManager.h"

using namespace std;

int main() {
    CommodityManager storage;
    storage.push(Guitar("102203009", "epiphone", "DR-100", 5, 10000000, "1 nam"));
    storage.push(Guitar("102200441", "Yamaha", "FT-300", 3, 300000, "1 nam"));
    CommodityManager commodity;
    commodity.push(Guitar("102203009", "epiphone", "DR-100", 2, 10000000, "1 nam"));
    commodity.push(Guitar("102200441", "Yamaha", "FT-300", 1, 300000, "1 nam"));
    Receipt rpt("102213", "Nguyen Nam", commodity, Date(8, 12, 2021));
    ReceiptManager receiptManager;
    receiptManager.addReceipt(rpt, storage);
    cout << storage;
    cout << receiptManager;
    return 0;
}
