 #pragma once
 #include <iostream>
 #include "Receipt.h"

 using namespace std;

 class ReceiptManager {
     private:
         Receipt* receipt;
         int numberOfReceipt;
     public:
         ReceiptManager();
         //ReceiptManager(const ReceiptManager&);
         ~ReceiptManager();
         int getNumberOfReceipt();
         void insert(Receipt, int);
         void push(Receipt);
         void shift(Receipt);
         int indexOf(const Receipt&) const;
         int indexOf(string, string = "ID", int = 0) const;
         int indexOf(const Date&, int) const;
         int indexOfCustomrerName(string, int);
         const ReceiptManager& findAllReceipt(string, string);
         void update(Receipt, Receipt);
         void remove(int);
         void remove(Receipt);
         void swap(Receipt&, Receipt&);
         void sort(string);
         Receipt& operator[](int);
         const ReceiptManager& operator=(const ReceiptManager&);
         friend ostream& operator<<(ostream&, const ReceiptManager&);
         void addReceipt(const Receipt&, CommodityManager&);
         void addReceipt(CommodityManager&);
 };
