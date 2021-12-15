#pragma once
#include "Guitar.h"
#include "Accessory.h"

using namespace std;

class CommodityManager {
    private:
        Guitar* guitar;
        int numberOfGuitar;
        Accessory* accessory;
        int numberOfAccessory;
    public:
        CommodityManager();
        CommodityManager(const CommodityManager&);
        ~CommodityManager();
        int getNumberOfGuitar() const;
        int getNumberOfAccessory() const;
        Guitar& getGuitar(int) const;
        Accessory& getAccessory(int) const;
        void push(Guitar);
        void pushWithQuantity(Guitar, int);
        void push(Accessory);
        void pushWithQuantity(Accessory, int);
        void shift(Guitar);
        void shift(Accessory);
        int indexOf(Guitar) const;
        int indexOf(Accessory) const;
        int indexOf(string, string, string, int = 0) const;
        int indexOfName(string, string, int = 0);
        void update(Guitar, Guitar);
        void update(Accessory, Accessory);
        void deleteAt(int, string);
        void deleteGuitar(Guitar);
        void deleteAccessory(Accessory);
        void swap(Guitar&, Guitar&);
        void swap(Accessory&, Accessory&);
        void sort(string, string);
        void showGuitarName() const;
        void showAccessoryName() const;
        bool hasGuitar();
        bool hasAccessory();
        const CommodityManager& findAllCommodity(string, string, string);
        const CommodityManager& findAllName(string, string);
        const CommodityManager& operator=(const CommodityManager&);
        friend ostream& operator<<(ostream&, const CommodityManager&);
        friend class ReceiptManager;
        friend class Receipt;
};
