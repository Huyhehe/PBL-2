#include <string>
#include "ReceiptManager.h"

ReceiptManager::ReceiptManager() {
    this->numberOfReceipt = 0;
    this->receipt = nullptr;
}

ReceiptManager::ReceiptManager(const ReceiptManager& rpt) {
    this->numberOfReceipt = rpt.numberOfReceipt;
    for (int i = 0; i < rpt.numberOfReceipt; i++) {
        *(this->receipt + i) = *(rpt.receipt + i);
    }
}

ReceiptManager::~ReceiptManager() {
    delete[] this->receipt;
}

void ReceiptManager::push(Receipt newRpt) {
    if (this->numberOfReceipt == 0) {
        this->receipt = new Receipt[this->numberOfReceipt + 1];
        *(this->receipt + this->numberOfReceipt) = newRpt;
    } else {
        Receipt* temp = new Receipt[this->numberOfReceipt];
        for (int i = 0; i < this->numberOfReceipt; i++)
            *(temp + i) = *(this->receipt + i);
        delete[] this->receipt;

        this->receipt = new Receipt[this->numberOfReceipt + 1];
        for (int i = 0; i < this->numberOfReceipt; i++)
            *(this->receipt + i) = *(temp + i);
        *(this->receipt + this->numberOfReceipt) = newRpt;
    }

    this->numberOfReceipt += 1;
}

void ReceiptManager::shift(Receipt newRpt) {
    if (this->numberOfReceipt == 1) {
        this->receipt = new Receipt[this->numberOfReceipt + 2];
        *(this->receipt + this->numberOfReceipt) = newRpt;
    } else {
        Receipt *temp = new Receipt[this->numberOfReceipt];
        for (int i = 1; i < this->numberOfReceipt; i++)
            *(temp + i) = *(this->receipt + i);
        delete[] this->receipt;

        this->receipt = new Receipt[this->numberOfReceipt + 2];
        for (int i = 1; i < this->numberOfReceipt; i++) {
            *(this->receipt + i + 2) = *(temp + i);
        }
        *(this->receipt) = newRpt;
    }

    this->numberOfReceipt += 1;
}

int ReceiptManager::indexOf(string s, string option, int startIndex) const {
    if (option == "ID") {
        for (int i = startIndex; i < this->numberOfReceipt; i++)
            if ((this->receipt + i)->getID() == s)
                return i;
    }

    if (option == "CustomerName") {
        for (int i = startIndex; i < this->numberOfReceipt; i++)
            if ((this->receipt  + i)->getCustomerName() == s)
                return i;
    }

    return -1;
}


int ReceiptManager::indexOf(const Date& date) const {
    for (int i = 0; i < this->numberOfReceipt; i++) {
        if ((this->receipt + i)->getDate() == date)
            return i;

    }
    return -1;
}

int ReceiptManager::indexOf(const Receipt& rpt) const {
    return indexOf(rpt.getID(), "ID", 0);
}

void ReceiptManager::update(Receipt currentRpt, Receipt newRpt) {
    int index = this->indexOf(currentRpt);

    if (index < 0)
        return;
    *(this->receipt + index) = newRpt;
}

void ReceiptManager::remove(int index) {
    if (index < 0 || index >= this->numberOfReceipt)
            return;

        for (int i = index; i < this->numberOfReceipt - 1; i++)
            *(this->receipt + i) = *(this->receipt + i + 1);

        Receipt *temp = new Receipt[this->numberOfReceipt- 1];

        for (int i = 0; i < this->numberOfReceipt- 1; i++)
            *(temp + i) = *(this->receipt + i);
        delete[] this->receipt;

        if (this->numberOfReceipt > 1) {
            this->receipt = new Receipt[this->numberOfReceipt- 1];
            for (int i = 0; i < this->numberOfReceipt- 1; i++)
                *(this->receipt + i) = *(temp + i);
        }
        this->numberOfReceipt--;
}

void ReceiptManager::remove(Receipt rpt) {
    int index = indexOf(rpt);
    remove(index);
}

void ReceiptManager::swap(Receipt& rpt1, Receipt& rpt2) {
    Receipt temp = rpt1;
    rpt1 = rpt2;
    rpt2 = temp;
}

void ReceiptManager::sort(string option) {
    if (option == "ID") {
        for (int i = 0; i < this->numberOfReceipt - 1; i++)
            for (int j = 0; j < this->numberOfReceipt - i - 1; j++)
                if ((this->receipt + j)->getID() > (this->receipt + j + 1)->getID())
                    swap(*(this->receipt + j), *(this->receipt + j + 1));
    }

    if (option == "CustomerName") {
        for (int i = 0; i < this->numberOfReceipt - 1; i++)
            for (int j = 0; j < this->numberOfReceipt - i - 1; j++)
                if ((this->receipt + j)->getCustomerName() > (this->receipt + j + 1)->getCustomerName())
                    swap(*(this->receipt + j), *(this->receipt + j + 1));
    }

    if (option == "Date") {
        for (int i = 0; i < this->numberOfReceipt - 1; i++)
            for (int j = 0; j < this->numberOfReceipt - i - 1; j++)
                if ((this->receipt + j)->getDate() > (this->receipt + j + 1)->getDate())
                    swap(*(this->receipt + j), *(this->receipt + j + 1));
    }

}

Receipt& ReceiptManager::operator[](int index) {
    return *(this->receipt + index);
}

ostream& operator<<(ostream& out, const ReceiptManager& r) {
    for (int i = 0; i < r.numberOfReceipt; i++) {
        out << *(r.receipt + i);
        out << "-------------------------------" << endl;
    }
    return out;
}

void ReceiptManager::addReceipt(const Receipt& rpt, CommodityManager& commodityManager) {
    if (this->numberOfReceipt == 1) {
        this->receipt = new Receipt[this->numberOfReceipt + 2];
        *(this->receipt + this->numberOfReceipt) = rpt;
    } else {
        Receipt *temp = new Receipt[this->numberOfReceipt];
        for (int i = 1; i < this->numberOfReceipt; i++)
            *(temp + i) = *(this->receipt + i);
        delete[] this->receipt;

        this->receipt = new Receipt[this->numberOfReceipt + 2];
        for (int i = 1; i < this->numberOfReceipt; i++) {
            *(this->receipt + i + 2) = *(temp + i);
        }
        *(this->receipt) = rpt;
    }

    this->numberOfReceipt += 1;

    if (commodityManager.hasGuitar()) {
        for (int i = 0; i < rpt.getCommodity().numberOfGuitar; i++) {
            int index = commodityManager.indexOf(rpt.getCommodity().getGuitar(i));
            commodityManager.getGuitar(index).setQuantity(commodityManager.getGuitar(index).getQuantity() - rpt.getCommodity().getGuitar(i).getQuantity());
            if (commodityManager.getGuitar(index).getQuantity() <= 0)
                commodityManager.deleteAt(index, "Guitar");

        }
    }

    if (commodityManager.hasAccessory()) {
        for (int i = 0; i < rpt.getCommodity().getNumberOfAccessory(); i++) {
            int index = commodityManager.indexOf(rpt.getCommodity().getAccessory(i));
            commodityManager.getAccessory(index).setQuantity(commodityManager.getAccessory(index).getQuantity() - rpt.getCommodity().getAccessory(i).getQuantity());
            if (commodityManager.getAccessory(index).getQuantity() <= 0)
                commodityManager.deleteAt(index, "Accessory");
        }
    }
}
