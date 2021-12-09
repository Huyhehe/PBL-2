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
         ReceiptManager(const ReceiptManager&);
         ~ReceiptManager();
         void insert(Receipt, int);
         void push(Receipt);
         void shift(Receipt);
         int indexOf(const Receipt&) const;
         int indexOf(string, string = "ID", int = 0) const;
         int indexOf(const Date&) const;
         void update(Receipt, Receipt);
         void remove(int);
         void remove(Receipt);
         void swap(Receipt&, Receipt&);
         void sort(string);
         Receipt& operator[](int);
         friend ostream& operator<<(ostream&, const ReceiptManager&);
         void addReceipt(const Receipt&, CommodityManager&);
 };
