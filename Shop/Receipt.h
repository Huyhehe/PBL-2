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
        int totalMoney = 0;
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
        CommodityManager& getCommodityManager();
        void addCommodity(const Guitar&, int);
        void addCommodity(const Accessory&, int);
        void calculatorTotalMoney();
        void setTotalMoney(int);
        int getTotalMoney() const;
        Date getDate() const;
        void setDate(const Date&);
        friend ostream& operator<<(ostream&, const Receipt&);
        const Receipt& operator=(const Receipt&);
        friend class CommodityManager;
};
