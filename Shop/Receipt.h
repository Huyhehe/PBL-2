#pragma once
#include <iostream>
#include "CommodityManager.h"
#include "Date.h"

using namespace std;

class Receipt {
    private:
        string ID;
        string customerName;
        CommodityManager commodity;
        Date date;
    public:
        Receipt();
        Receipt(string, string, CommodityManager, Date);
        Receipt(const Receipt&);
        ~Receipt();
        string getID() const;
        void setID(string);
        string getCustomerName() const;
        void setCustomerName(string);
        CommodityManager getCommodity() const;
        void addCommodity(const Guitar&);
        void addCommodity(const Accessory&);
        int getTotalMoney() const;
        Date getDate() const;
        void setDate(const Date&);
        friend ostream& operator<<(ostream&, const Receipt&);
        const Receipt& operator=(const Receipt&);
};
