#include <string>
#include "ReceiptManager.h"
#include <iomanip>

ReceiptManager::ReceiptManager() {
    this->numberOfReceipt = 0;
    this->receipt = nullptr;
}

//ReceiptManager::ReceiptManager(const ReceiptManager& rpt) {
//    for (int i = 0; i < rpt.numberOfReceipt; i++)
//        this->push(*(rpt.receipt + i));
//}

ReceiptManager::~ReceiptManager() {
    delete[] this->receipt;
}

int ReceiptManager::getNumberOfReceipt() {
    return this->numberOfReceipt;
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

int ReceiptManager::indexOfCustomrerName(string str, int startIndex) {
    for (int i = startIndex; i < this->getNumberOfReceipt(); i++) {
        string s = (*this)[i].getCustomerName();
        if (s.find(str) >= 0 && s.find(str) <= s.length())
            return i;
    }
    return -1;
}


int ReceiptManager::indexOf(const Date& date, int startIndex) const {
    for (int i = startIndex; i < this->numberOfReceipt; i++) {
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
    if (rpt.getCommodity().hasGuitar() && !commodityManager.hasGuitar())
        return;
    if (rpt.getCommodity().hasAccessory() && !commodityManager.hasAccessory())
        return;

    if (rpt.getCommodity().hasGuitar() && commodityManager.hasGuitar())
        for (int i = 0; i < rpt.getCommodity().getNumberOfGuitar(); i++)
            if (commodityManager.indexOf(rpt.getCommodity().getGuitar(i)) == -1)
                return;
    if (rpt.getCommodity().hasAccessory() && commodityManager.hasAccessory())
        for (int i = 0; i < rpt.getCommodity().getNumberOfAccessory(); i++)
            if (commodityManager.indexOf(rpt.getCommodity().getAccessory(i)) == -1)
                return;

    this->push(rpt);

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

void ReceiptManager::addReceipt(CommodityManager& commodityManager) {
    string str;
    Receipt newRpt;
    CommodityManager choosed;
    cout << "Nhap ID hoa don: ";
    getline(cin, str);
    newRpt.setID(str);
    cout << "Nhap ten khach hang: ";
    getline(cin, str);
    newRpt.setCustomerName(str);
tryAgain:
    cout << "**chon Hang hoa: " << endl;
    cout << "\t1. Guitar" << endl;
    cout << "\t2. Phu kien" << endl;
    cout << "Nhap lua chon: ";
    string temp;
    getline(cin, temp);
    while ((temp < "1" || temp > "9") || (stoi(temp) < 1 || stoi(temp) > 2)) {
        cout << "lua chon khong phu hop, vui long thu lai: ";
        getline(cin, temp);
    }
    int choice = stoi(temp);
    switch(choice) {
        case 1: {
            cout << "Nhap ten guitar: ";
            getline(cin, str);
            CommodityManager guitar = commodityManager.findAllName(str, "Guitar");
            if (guitar.getNumberOfGuitar() == 0) {
                cout << "Guitar khong ton tai trong kho!";
                break;
            }
            cout << "+-----+----------+-------------------+-----------+----+------------+----------+" << endl; //5, 10, 19, 11, 4, 12, 10
            cout << "| STT |    ID    |    Thuong hieu    |    Ten    | SL |  Gia tien  | Bao hanh |" << endl;
            cout << "+-----+----------+-------------------+-----------+----+------------+----------+" << endl;
            for (int i = 0 ; i < guitar.getNumberOfGuitar(); i++) {
                string temp = "";
                if (i + 1 < 10)
                    temp = "00";
                if (i + 1 >= 10 && i + 1 < 100)
                    temp = "0";
                cout << "|" << temp << i + 1 << setw(3)
                     << "|" << guitar.getGuitar(i).getID() << setw(11 - guitar.getGuitar(i).getID().length())
                     << "|" << guitar.getGuitar(i).getBrand() << setw(20 - guitar.getGuitar(i).getBrand().length())
                     << "|" << guitar.getGuitar(i).getName() << setw(12 - guitar.getGuitar(i).getName().length())
                     << "|" << guitar.getGuitar(i).getQuantity() << setw(5 - to_string(guitar.getGuitar(i).getQuantity()).length())
                     << "|" << guitar.getGuitar(i).getPrice() << setw(13 - to_string(guitar.getGuitar(i).getPrice()).length())
                     << "|" << guitar.getGuitar(i).getWarrantyTime() << setw(11 - guitar.getGuitar(i).getWarrantyTime().length()) << "|" << endl;
            }
            cout << "+-----+----------+-------------------+-----------+----+------------+----------+" << endl;
            cout << "Ban muon chon guitar co so thu tu(chon (0) de huy): ";
            int i;
            string temp;
            getline(cin, temp);
            if (temp == "0")
                break;
            while ((temp < "1" || temp > "9") && (stoi(temp) < 0 || stoi(temp) > guitar.getNumberOfGuitar())) {
                cout << "lua chon khong phu hop, vui long thu lai: ";
                getline(cin, temp);
            }
            i = stoi(temp);
            int num;
            cout << "Nhap so luong san pham: ";
            cin >> num;
            cin.ignore();
            guitar.getGuitar(i - 1).setQuantity(num);
            choosed.push(guitar.getGuitar(i - 1));
            break;
        }
        case 2: {
            cout << "Nhap ten phu kien: ";
            getline(cin, str);
            CommodityManager accessory = commodityManager.findAllName(str, "Accessory");
            if (accessory.getNumberOfAccessory() == 0) {
                cout << "Phu kien khong ton tai trong kho!";
                break;
            }
            cout << "+-----+----------+------------+-------------+----+------------+----------------+" << endl; //10, 12, 13, 4, 12, 16
            cout << "| STT |    ID    |    Loai    |     Ten     | SL |  Gia tien  |    Bao hanh    |" << endl;
            cout << "+-----+----------+------------+-------------+----+------------+----------------+" << endl;
            for (int i = 0 ; i < accessory.getNumberOfAccessory(); i++) {
                string temp = "";
                if (i + 1 < 10)
                    temp = "00";
                if (i + 1 >= 10 && i + 1 < 100)
                    temp = "0";
                cout << "|" << temp << i + 1<< setw(3)
                     << "|" << accessory.getAccessory(i).getID() << setw(11 - accessory.getAccessory(i).getID().length())
                     << "|" << accessory.getAccessory(i).getTypeOfCommodity() << setw(13 - accessory.getAccessory(i).getTypeOfCommodity().length())
                     << "|" << accessory.getAccessory(i).getName() << setw(14 - accessory.getAccessory(i).getName().length())
                     << "|" << accessory.getAccessory(i).getQuantity() << setw(5 - to_string(accessory.getAccessory(i).getQuantity()).length())
                     << "|" << accessory.getAccessory(i).getPrice() << setw(13 - to_string(accessory.getAccessory(i).getPrice()).length())
                     << "|" << accessory.getAccessory(i).getWarrantyTime() << setw(17 - accessory.getAccessory(i).getWarrantyTime().length()) << "|" << endl;
            }
            cout << "+-----+----------+------------+-------------+----+------------+----------------+" << endl;
            cout << "Ban muon chon phu kien co so thu tu(chon (0) de huy): ";
            int i;
            string temp;
            getline(cin, temp);
            if (temp == "0")
                break;
            while ((temp < "1" || temp> "9") && (stoi(temp) < 0 || stoi(temp) > accessory.getNumberOfAccessory())) {
                cout << "lua chon khong phu hop, vui long thu lai: ";
                getline(cin, temp);
            }
            i = stoi(temp);
            int num;
            cout << "Nhap so luong san pham: ";
            cin >> num;
            cin.ignore();
            accessory.getAccessory(i - 1).setQuantity(num);
            choosed.push(accessory.getAccessory(i - 1));
            break;
        }
    }
    cout << "Ban co muon tiep tuc them san pham (y/n): ";
    getline(cin, temp);
    if (temp == "y" || temp == "Y")
        goto tryAgain;
    for (int i = 0; i < choosed.getNumberOfGuitar(); i++)
        newRpt.getCommodityManager().push(choosed.getGuitar(i));
    for (int i = 0; i < choosed.getNumberOfAccessory(); i++)
        newRpt.getCommodityManager().push(choosed.getAccessory(i));
    cout << "Nhap ngay xuat hoa don (dd/mm/yyyy): ";
    getline(cin, str);
    newRpt.setDate(stringToDate(str));
    this->addReceipt(newRpt, commodityManager);
}

const ReceiptManager& ReceiptManager::findAllReceipt(string str, string option) {
    ReceiptManager* rptManager = new ReceiptManager();
    int i = 0;
    int index;
    if (option == "ID") {
        index = this->indexOf(str, option, i);
        while (index != -1) {
            rptManager->push((*this)[index]);
            i = index + 1;
            index = this->indexOf(str, option, i);
        }
    }
    if (option == "Date") {
        index = this->indexOf(stringToDate(str), i);
        while (index != -1) {
            rptManager->push((*this)[index]);
            i = index + 1;
            index = this->indexOf(stringToDate(str), i);
        }
    }
    if (option == "Customer Name") {
        index = this->indexOfCustomrerName(str, i);
        while (index != -1) {
            rptManager->push((*this)[index]);
            i = index + 1;
            index = this->indexOfCustomrerName(str, i);
        }
    }
    return *rptManager;

}

const ReceiptManager& ReceiptManager::operator=(const ReceiptManager& rptManager) {
    for (int i = 0; i < rptManager.numberOfReceipt; i++)
        this->push(*(rptManager.receipt + i));
    return *this;
}
