#include "CommodityManager.h"
#include <iostream>
#include <iomanip>

using namespace std;

CommodityManager::CommodityManager() {
    this->numberOfAccessory = 0;
    this->guitar = nullptr;
    this->numberOfGuitar = 0;
    this->accessory = nullptr;
}

CommodityManager::CommodityManager(const CommodityManager& commodity) {
    this->numberOfGuitar = 0;
    this->guitar = new Guitar[commodity.numberOfGuitar];
    for (int i = 0; i < commodity.numberOfGuitar; i++)
        this->push(*(commodity.guitar + i));

    this->numberOfAccessory = 0;
    this->accessory = new Accessory[commodity.numberOfAccessory];
    for (int i = 0; i < commodity.numberOfAccessory; i++)
        this->push(*(commodity.accessory + i));
}

CommodityManager::~CommodityManager() {
    delete[] guitar;
    delete[] accessory;
}

int CommodityManager::getNumberOfGuitar() const {
    return this->numberOfGuitar;
}

int CommodityManager::getNumberOfAccessory() const {
    return this->numberOfAccessory;
}

Guitar& CommodityManager::getGuitar(int index) const {
    return *(this->guitar + index);
}

Accessory& CommodityManager::getAccessory(int index) const {
    return *(this->accessory + index);
}

void CommodityManager::push(Guitar newGuitar) {
    if (this->numberOfGuitar == 0) {
        this->guitar = new Guitar[this->numberOfGuitar + 1];
        *(this->guitar + this->numberOfGuitar) = newGuitar;
    } else {
        Guitar *temp = new Guitar[this->numberOfGuitar];
        for (int i = 0; i < this->numberOfGuitar; i++)
            *(temp + i) = *(this->guitar + i);
        delete[] this->guitar;

        this->guitar = new Guitar[this->numberOfGuitar + 1];
        for (int i = 0; i < this->numberOfGuitar; i++)
            *(this->guitar + i) = *(temp + i);
        *(this->guitar + this->numberOfGuitar) = newGuitar;
    }

    this->numberOfGuitar += 1;
}

void CommodityManager::push(Accessory newAccessory) {
    if (this->numberOfAccessory == 0) {
        this->accessory = new Accessory[this->numberOfAccessory + 1];
        *(this->accessory + this->numberOfAccessory) = newAccessory;
    } else {
        Accessory *temp = new Accessory[this->numberOfAccessory];
        for (int i = 0; i < this->numberOfAccessory; i++)
            *(temp + i) = *(this->accessory + i);
        delete[] this->accessory;

        this->accessory = new Accessory[this->numberOfAccessory + 1];
        for (int i = 0; i < this->numberOfAccessory; i++)
            *(this->accessory + i) = *(temp + i);
        *(this->accessory + this->numberOfAccessory) = newAccessory;
    }

    this->numberOfAccessory += 1;
}

void CommodityManager::pushWithQuantity(Guitar newGuitar, int quantity) {
    this->push(newGuitar);
    (this->guitar + this->numberOfGuitar - 1)->setQuantity(quantity);
}

void CommodityManager::shift(Guitar newGuitar) {
    if (this->guitar == 0) {
        this->guitar = new Guitar[this->numberOfGuitar + 1];
        *(this->guitar + this->numberOfGuitar) = newGuitar;
    } else {
        Guitar *temp = new Guitar[this->numberOfGuitar];
        for (int i = 0; i < this->numberOfGuitar; i++)
            *(temp + i) = *(this->guitar + i);
        delete[] this->guitar;

        this->guitar = new Guitar[this->numberOfGuitar + 1];
        for (int i = 0; i < this->numberOfGuitar; i++) {
            *(this->guitar + i + 1) = *(temp + i);
        }
        *(this->guitar) = newGuitar;
    }

    this->numberOfGuitar += 1;
}

void CommodityManager::pushWithQuantity(Accessory newAccessory, int quantity) {
    this->push(newAccessory);
    (this->accessory + this->numberOfAccessory - 1)->setQuantity(quantity);
}

void CommodityManager::shift(Accessory newAccessory) {
    if (this->accessory == 0) {
        this->accessory = new Accessory[this->numberOfAccessory + 1];
        *(this->accessory + this->numberOfGuitar) = newAccessory;
    } else {
        Accessory *temp = new Accessory[this->numberOfAccessory];
        for (int i = 0; i < this->numberOfAccessory; i++)
            *(temp + i) = *(this->accessory + i);
        delete[] this->accessory;

        this->accessory = new Accessory[this->numberOfAccessory + 1];
        for (int i = 0; i < this->numberOfAccessory; i++) {
            *(this->accessory + i + 1) = *(temp + i);
        }
        *(this->accessory) = newAccessory;
    }

    this->numberOfAccessory += 1;
}

int CommodityManager::indexOf(string s, string option, string commodity, int startIndex) const {
    if (commodity == "Guitar") {
        if (option == "ID") {
            for (int i = startIndex; i < this->numberOfGuitar; i++)
                if ((this->guitar + i)->getID() == s)
                    return i;
        }

        if (option == "Name") {
            for (int i = startIndex; i < this->numberOfGuitar; i++)
                if ((this->guitar + i)->getName() == s)
                    return i;
        }

        if (option == "Brand") {
            for (int i = startIndex; i < this->numberOfGuitar; i++)
                if ((this->guitar + i)->getBrand() == s)
                    return i;
        }

        if (option == "Quantity") {
            for (int i = startIndex; i < this->numberOfGuitar; i++)
                if ((this->guitar + i)->getQuantity() == stoi(s))
                    return i;
        }

        if (option == "Price") {
            for (int i = startIndex; i < this->numberOfGuitar; i++)
                if ((this->guitar + i)->getPrice() == stoi(s))
                    return i;
        }
    }

    if (commodity == "Accessory") {
        if (option == "ID") {
            for (int i = startIndex; i < this->numberOfAccessory; i++)
                if ((this->accessory + i)->getID() == s)
                    return i;
        }

        if (option == "Name") {
            for (int i = startIndex; i < this->numberOfAccessory; i++)
                if ((this->accessory + i)->getName() == s)
                    return i;
        }

        if (option == "Type") {
            for (int i = startIndex; i < this->numberOfAccessory; i++)
                if ((this->accessory + i)->getTypeOfCommodity() == s)
                    return i;
        }

        if (option == "Quantity") {
            for (int i = startIndex; i < this->numberOfAccessory; i++)
                if ((this->accessory + i)->getQuantity() == stoi(s))
                    return i;
        }

        if (option == "Price") {
            for (int i = startIndex; i < this->numberOfAccessory; i++)
                if ((this->accessory + i)->getPrice() == stoi(s))
                    return i;
        }
    }

    return -1;
}

int CommodityManager::indexOf(Guitar guitar) const {
    for (int i = 0; i < this->numberOfGuitar; i++) {
        if ((this->guitar + i)->getID() == guitar.getID())
            return i;
    }

    return -1;
}

int CommodityManager::indexOf(Accessory accessory) const {
    for (int i = 0; i < this->numberOfAccessory; i++) {
        if ((this->accessory + i)->getID() == accessory.getID())
            return i;
    }

    return -1;
}

int CommodityManager::indexOfName(string str, string option, int startIndex) {
    if (option == "Guitar")
        for (int i = startIndex; i < this->numberOfGuitar; i++) {
            string s = this->getGuitar(i).getBrand() + " " +this->getGuitar(i).getName();
            if (s.find(str) >= 0 && s.find(str) <= s.length())
                return i;
        }

    if (option == "Accessory")
        for (int i = startIndex; i < this->numberOfAccessory; i++) {
            string s = this->getAccessory(i).getName();
            if (s.find(str) >= 0 && s.find(str) <= s.length())
                return i;
        }

    return -1;
}

void CommodityManager::update(Guitar guitar, Guitar newGuitar) {
    int index = indexOf(guitar);

    if (index < 0)
        return;

    *(this->guitar + index) = newGuitar;
}

void CommodityManager::update(Accessory accessory, Accessory newAccessory) {
    int index = indexOf(accessory);

    if (index < 0)
        return;

    *(this->accessory + index) = newAccessory;
}

void CommodityManager::updateGuitar(string str, string option) {
    CommodityManager commodityManager;
    if (option != "Full Name")
        commodityManager = this->findAllCommodity(str, option, "Guitar");
    else
        commodityManager = this->findAllName(str, "Guitar");
    if (commodityManager.getNumberOfGuitar() == 0) {
        cout << "Khong co du lieu trung khop, vui long kiem lai thong tin ban muon chinh sua." << endl;
        cout << "Ban co muon tiep tuc khong (Y/N): ";
        return;
    }
    cout << "+-----+----------+-------------------+-----------+----+------------+----------+" << endl;
    cout << "| STT |    ID    |    Thuong hieu    |    Ten    | SL |  Gia tien  | Bao hanh |" << endl;
    cout << "+-----+----------+-------------------+-----------+----+------------+----------+" << endl;
    for (int i = 0 ; i < commodityManager.getNumberOfGuitar(); i++) {
        string temp = "";
        if (i + 1 < 10)
            temp = "00";
        if (i + 1 >= 10 && i + 1 < 100)
            temp = "0";
        cout << "|" << temp << i + 1 << setw(3)
             << "|" << commodityManager.getGuitar(i).getID() << setw(11 - commodityManager.getGuitar(i).getID().length())
             << "|" << commodityManager.getGuitar(i).getBrand() << setw(20 - commodityManager.getGuitar(i).getBrand().length())
             << "|" << commodityManager.getGuitar(i).getName() << setw(12 - commodityManager.getGuitar(i).getName().length())
             << "|" << commodityManager.getGuitar(i).getQuantity() << setw(5 - to_string(commodityManager.getGuitar(i).getQuantity()).length())
             << "|" << commodityManager.getGuitar(i).getPrice() << setw(13 - to_string(commodityManager.getGuitar(i).getPrice()).length())
             << "|" << commodityManager.getGuitar(i).getWarrantyTime() << setw(11 - commodityManager.getGuitar(i).getWarrantyTime().length()) << "|" << endl;
    }
    cout << "+-----+----------+-------------------+-----------+----+------------+----------+" << endl;
    cout << "Ban muon xoa guitar co so thu tu(chon (0) de chinh sua tat ca hoac nhan (x) de thoat): ";
    int index;
    string temp;
    getline(cin, temp);
    if (temp == "x" || temp == "X") {
        cout << "Chinh sua khong thanh cong!" << endl
             << "Ban co muon tiep tuc khong (Y/N): ";
        return;
    }
    while ((temp< "1" || temp> "9") && (stoi(temp) < 0 || stoi(temp) > commodityManager.getNumberOfGuitar())) {
        cout << "lua chon khong phu hop, vui long thu lai: ";
        getline(cin, str);
    }
    index = stoi(temp);
    system("cls");
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                   GUITAR STORE                   +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+         LUA CHON THONG TIN MUON CHINH SUA        +" << endl
         << "+ 1. Ma guitar.                                    +" << endl
         << "+ 2. Thuong Hieu.                                  +" << endl
         << "+ 3. Ten guitar.                                   +" << endl
         << "+ 4. So luong guitar co trong kho.                 +" << endl
         << "+ 5. Gia guitar.                                   +" << endl
         << "+ 6. Thoi gian bao hanh.                           +" << endl
         << "+                                                  +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Hay nhap lua chon cua ban: ";
    getline(cin, temp);
    while ((temp< "1" || temp> "9") && (stoi(temp) < 0 || stoi(temp) > 6)) {
        cout << "lua chon khong phu hop, vui long thu lai: ";
        getline(cin, str);
    }
    int j = stoi(temp);
    string s;
    int i = index - 1;
    bool updateAll = false;
    if (index == 0) {
        updateAll = true;
        i = 0;
    }
    while (i < commodityManager.getNumberOfGuitar()) {
        switch(j) {
            case 1: {
                cout << "Nhap ma Guitar moi: ";
                getline(cin, s);
                Guitar temp = commodityManager.getGuitar(i);
                temp.setID(s);
                this->update(commodityManager.getGuitar(i), temp);
                break;
            }
            case 2: {
                cout << "Nhap ten thuong hieu Guitar moi: ";
                getline(cin, s);
                Guitar temp = commodityManager.getGuitar(i);
                temp.setBrand(s);
                this->update(commodityManager.getGuitar(i), temp);
                break;
            }
            case 3: {
                cout << "Nhap ten Guitar moi: ";
                getline(cin, s);
                Guitar temp = commodityManager.getGuitar(i);
                temp.setName(s);
                this->update(commodityManager.getGuitar(i), temp);
                break;
            }
            case 4: {
                cout << "Nhap so luong guitar co trong kho moi: ";
                getline(cin, s);
                Guitar temp = commodityManager.getGuitar(i);
                temp.setQuantity(stoi(s));
                this->update(commodityManager.getGuitar(i), temp);
                break;
            }
            case 5: {
                cout << "Nhap gia Guitar moi: ";
                getline(cin, s);
                Guitar temp = commodityManager.getGuitar(i);
                temp.setPrice(stoi(s));
                this->update(commodityManager.getGuitar(i), temp);
                break;
            }
            case 6: {
                cout << "Nhap thoi gian bao hanh moi: ";
                getline(cin, s);
                Guitar temp = commodityManager.getGuitar(i);
                temp.setWarrantyTime(s);
                this->update(commodityManager.getGuitar(i), temp);
                break;
            }
            default:
                break;
        }
        if (updateAll)
            i++;
        else
            break;
    }
    cout << "Chinh sua thanh cong!" << endl
         << "Ban co muon tiep tuc khong (Y/N): ";
}

void CommodityManager::updateAccessory(string str, string option) {
    CommodityManager commodityManager;
    if (option != "Name")
        commodityManager = this->findAllCommodity(str, option, "Accessory");
    else
        commodityManager = this->findAllName(str, "Accessory");
    if (commodityManager.getNumberOfAccessory() == 0) {
        cout << "Khong co du lieu trung khop, vui long kiem lai thong tin ban muon chinh sua." << endl;
        cout << "Ban co muon tiep tuc khong (Y/N):";
        return;
    }
    cout << "+-----+----------+------------+-------------------+----+------------+----------------+" << endl;
    cout << "| STT |    ID    |    Loai    |        Ten        | SL |  Gia tien  |    Bao hanh    |" << endl;
    cout << "+-----+----------+------------+-------------------+----+------------+----------------+" << endl;
    for (int i = 0 ; i < commodityManager.getNumberOfAccessory(); i++) {
        string temp = "";
        if (i + 1 < 10)
            temp = "00";
        if (i + 1 >= 10 && i + 1 < 100)
            temp = "0";
        cout << "|" << temp << i + 1<< setw(3)
             << "|" << commodityManager.getAccessory(i).getID() << setw(11 - commodityManager.getAccessory(i).getID().length())
             << "|" << commodityManager.getAccessory(i).getTypeOfCommodity() << setw(13 - commodityManager.getAccessory(i).getTypeOfCommodity().length())
             << "|" << commodityManager.getAccessory(i).getName() << setw(20 - commodityManager.getAccessory(i).getName().length())
             << "|" << commodityManager.getAccessory(i).getQuantity() << setw(5 - to_string(commodityManager.getAccessory(i).getQuantity()).length())
             << "|" << commodityManager.getAccessory(i).getPrice() << setw(13 - to_string(commodityManager.getAccessory(i).getPrice()).length())
             << "|" << commodityManager.getAccessory(i).getWarrantyTime() << setw(17 - commodityManager.getAccessory(i).getWarrantyTime().length()) << "|" << endl;
    }
    cout << "+-----+----------+------------+-------------------+----+------------+----------------+" << endl;
    cout << "Ban muon chinh sua phu kien co so thu thu (chon (0) de sua tat ca hoac chon (x) de thoat): ";
    int index;
    string temp;
    getline(cin, temp);
    if (temp == "x" || temp == "X") {
        cout << "Chinh sua khong thanh cong!" << endl
             << "Ban co muon tiep tuc khong (Y/N): ";
        return;
    }
    while ((temp< "1" || temp> "9") && (stoi(temp) < 0 || stoi(temp) > commodityManager.getNumberOfGuitar())) {
        cout << "lua chon khong phu hop, vui long thu lai: ";
        getline(cin, str);
    }
    index = stoi(temp);
    system("cls");
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                   GUITAR STORE                   +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+         LUA CHON THONG TIN MUON CHINH SUA        +" << endl
         << "+ 1. Ma phu kien.                                  +" << endl
         << "+ 2. Loai phu kien.                                +" << endl
         << "+ 3. Ten phu kien.                                 +" << endl
         << "+ 4. So luong phu kien co trong kho.               +" << endl
         << "+ 5. Gia phu kien.                                 +" << endl
         << "+ 6. Thoi gian bao hanh.                           +" << endl
         << "+                                                  +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Hay nhap lua chon cua ban: ";
    getline(cin, temp);
    while ((temp< "1" || temp> "9") && (stoi(temp) < 0 || stoi(temp) > 6)) {
        cout << "lua chon khong phu hop, vui long thu lai: ";
        getline(cin, str);
    }
    int j = stoi(temp);
    string s;
    int i = index - 1;
    bool updateAll = false;
    if (index == 0) {
        updateAll = true;
        i = 0;
    }
    while (i < commodityManager.getNumberOfAccessory()) {
        switch(j) {
            case 1: {
                cout << "Nhap ma phu kien moi: ";
                getline(cin, s);
                Accessory temp = commodityManager.getAccessory(i);
                temp.setID(s);
                this->update(commodityManager.getAccessory(i), temp);
                break;
            }
            case 2: {
                cout << "Nhap ten loai phu kien moi: ";
                getline(cin, s);
                Accessory temp = commodityManager.getAccessory(i);
                temp.setTypeOfCommodoty(s);
                this->update(commodityManager.getAccessory(i), temp);
                break;
            }
            case 3: {
                cout << "Nhap ten phu kien moi: ";
                getline(cin, s);
                Accessory temp = commodityManager.getAccessory(i);
                temp.setName(s);
                this->update(commodityManager.getAccessory(i), temp);
                break;
            }
            case 4: {
                cout << "Nhap so luong phu kien co trong kho moi: ";
                getline(cin, s);
                Accessory temp = commodityManager.getAccessory(i);
                temp.setQuantity(stoi(s));
                this->update(commodityManager.getAccessory(i), temp);
                break;
            }
            case 5: {
                cout << "Nhap gia moi cho phu kien: ";
                getline(cin, s);
                Accessory temp = commodityManager.getAccessory(i);
                temp.setPrice(stoi(s));
                this->update(commodityManager.getAccessory(i), temp);
                break;
            }
            case 6: {
                cout << "Nhap thoi gian bao hanh moi: ";
                getline(cin, s);
                Accessory temp = commodityManager.getAccessory(i);
                temp.setWarrantyTime(s);
                this->update(commodityManager.getAccessory(i), temp);
                break;
            }
            default:
                break;
        }
        if (updateAll)
            i++;
        else
            break;
    }
    cout << "Chinh sua thanh cong!" << endl
         << "Ban co muon tiep tuc khong (Y/N): ";
}

void CommodityManager::deleteAt(int index, string commodity) {
    if (commodity == "Guitar") {
        if (index < 0 || index >= this->numberOfGuitar)
            return;

        for (int i = index; i < this->numberOfGuitar - 1; i++)
            *(this->guitar + i) = *(this->guitar + i + 1);

        Guitar *temp = new Guitar[this->numberOfGuitar - 1];

        for (int i = 0; i < this->numberOfGuitar - 1; i++)
            *(temp + i) = *(this->guitar + i);
        delete[] this->guitar;

        if (this->numberOfGuitar > 1) {
            this->guitar = new Guitar[this->numberOfGuitar - 1];
            for (int i = 0; i < this->numberOfGuitar - 1; i++)
                *(this->guitar + i) = *(temp + i);
        }
        this->numberOfGuitar--;
    }

    if (commodity == "Accessory") {
        if (index < 0 || index >= this->numberOfAccessory)
            return;

        for (int i = index; i < this->numberOfAccessory - 1; i++)
            *(this->accessory + i) = *(this->accessory + i + 1);

        Accessory *temp = new Accessory[this->numberOfAccessory - 1];

        for (int i = 0; i < this->numberOfAccessory - 1; i++)
            *(temp + i) = *(this->accessory + i);
        delete[] this->accessory;

        if (this->numberOfAccessory > 1) {
            this->accessory = new Accessory[this->numberOfAccessory - 1];
            for (int i = 0; i < this->numberOfAccessory - 1; i++)
                *(this->accessory + i) = *(temp + i);
        }
        this->numberOfAccessory--;
    }
}

void CommodityManager::deleteGuitar(Guitar guitar) {
    int index = indexOf(guitar);
    if (index < 0 || index >= this->numberOfGuitar)
        return;

    for (int i = index; i < this->numberOfGuitar - 1; i++)
        *(this->guitar + i) = *(this->guitar + i + 1);

    Guitar *temp = new Guitar[this->numberOfGuitar - 1];
    for (int i = 0; i < this->numberOfGuitar - 1; i++)
        *(temp + i) = *(this->guitar + i);
    delete[] this->guitar;

    if (this->numberOfGuitar > 1) {
        this->guitar = new Guitar[this->numberOfGuitar - 1];
        for (int i = 0; i < this->numberOfGuitar - 1; i++)
            *(this->guitar + i) = *(temp + i);
    }
    this->numberOfGuitar--;
}

void CommodityManager::deleteAccessory(Accessory accessory) {
    int index = indexOf(accessory);

    if (index < 0 || index >= this->numberOfAccessory)
        return;

    for (int i = index; i < this->numberOfAccessory - 1; i++)
        *(this->accessory + i) = *(this->accessory + i + 1);

    Accessory *temp = new Accessory[this->numberOfAccessory - 1];
    for (int i = 0; i < this->numberOfAccessory - 1; i++)
        *(temp + i) = *(this->accessory + i);
    delete[] this->accessory;

    if (this->numberOfAccessory > 1) {
        this->accessory = new Accessory[this->numberOfAccessory - 1];
        for (int i = 0; i < this->numberOfAccessory - 1; i++)
            *(this->accessory + i) = *(temp + i);
    }

    this->numberOfAccessory--;
}

void CommodityManager::deleteGuitar(string str, string option) {
    CommodityManager commodityManager;
    if (option != "Full Name")
        commodityManager = this->findAllCommodity(str, option, "Guitar");
    else
        commodityManager = this->findAllName(str, "Guitar");
    if (commodityManager.getNumberOfGuitar() == 0) {
        cout << "Khong co du lieu trung khop, vui long kiem lai thong tin ban muon chinh sua." << endl;
        cout << "Ban co muon tiep tuc khong (Y/N):";
        return;
    }
    cout << "+-----+----------+-------------------+-----------+----+------------+----------+" << endl;
    cout << "| STT |    ID    |    Thuong hieu    |    Ten    | SL |  Gia tien  | Bao hanh |" << endl;
    cout << "+-----+----------+-------------------+-----------+----+------------+----------+" << endl;
    for (int i = 0 ; i < commodityManager.getNumberOfGuitar(); i++) {
        string temp = "";
        if (i < 10)
            temp = "00";
        if (i >= 10 && i < 100)
            temp = "0";
        cout << "|" << temp << i + 1 << setw(3)
             << "|" << commodityManager.getGuitar(i).getID() << setw(11 - commodityManager.getGuitar(i).getID().length())
             << "|" << commodityManager.getGuitar(i).getBrand() << setw(20 - commodityManager.getGuitar(i).getBrand().length())
             << "|" << commodityManager.getGuitar(i).getName() << setw(12 - commodityManager.getGuitar(i).getName().length())
             << "|" << commodityManager.getGuitar(i).getQuantity() << setw(5 - to_string(commodityManager.getGuitar(i).getQuantity()).length())
             << "|" << commodityManager.getGuitar(i).getPrice() << setw(13 - to_string(commodityManager.getGuitar(i).getPrice()).length())
             << "|" << commodityManager.getGuitar(i).getWarrantyTime() << setw(11 - commodityManager.getGuitar(i).getWarrantyTime().length()) << "|" << endl;
    }
    cout << "+-----+----------+-------------------+-----------+----+------------+----------+" << endl;
    cout << "Ban muon xoa guitar co so thu tu(chon (0) de xoa tat ca hoac nhan (x) de thoat): ";
    int i;
    string temp;
    getline(cin, temp);
    if (temp == "x" || temp == "X") {
        cout << "Xoa khong thanh cong! << endl"
             << "Ban co muon tiep tuc khong (Y/N): ";
        return;
    }
    while ((temp< "1" || temp> "9") && (stoi(temp) < 0 || stoi(temp) > commodityManager.getNumberOfGuitar())) {
        cout << "lua chon khong phu hop, vui long thu lai: ";
        getline(cin, str);
    }
    i = stoi(temp);
    if (i == 0) {
        for (int j = 0; j < commodityManager.getNumberOfGuitar(); j++)
            this->deleteGuitar(commodityManager.getGuitar(j));
        cout << "Xoa thanh cong!" << endl;
        cout << "Ban co muon tiep tuc khong (Y/N): ";
        return;
    }
    int index = this->indexOf(commodityManager.getGuitar(i - 1));
    if (index == -1) {
        cout << "Xoa khong thanh cong!" << endl;
        cout << "Ban co muon tiep tuc khong (Y/N): ";
        return;
    }
    deleteAt(index, "Guitar");
    cout << "Xoa thanh cong!" << endl;
    cout << "Ban co muon tiep tuc khong (Y/N): ";
}

void CommodityManager::deleteAccessory(string str, string option) {
    CommodityManager commodityManager;
    if (option != "Name")
        commodityManager = this->findAllCommodity(str, option, "Accessory");
    else
        commodityManager = this->findAllName(str, "Accessory");
    if (commodityManager.getNumberOfAccessory() == 0) {
        cout << "Khong co du lieu trung khop, vui long kiem lai thong tin ban muon chinh sua." << endl;
        cout << "Ban co muon tiep tuc khong (Y/N):";
        return;
    }
    cout << "+-----+----------+------------+-------------------+----+------------+----------------+" << endl;
    cout << "| STT |    ID    |    Loai    |        Ten        | SL |  Gia tien  |    Bao hanh    |" << endl;
    cout << "+-----+----------+------------+-------------------+----+------------+----------------+" << endl;
    for (int i = 0 ; i < commodityManager.getNumberOfAccessory(); i++) {
        string temp = "";
        if (i < 10)
            temp = "00";
        if (i >= 10 && i < 100)
            temp = "0";
        cout << "|" << temp << i + 1<< setw(3)
             << "|" << commodityManager.getAccessory(i).getID() << setw(11 - commodityManager.getAccessory(i).getID().length())
             << "|" << commodityManager.getAccessory(i).getTypeOfCommodity() << setw(13 - commodityManager.getAccessory(i).getTypeOfCommodity().length())
             << "|" << commodityManager.getAccessory(i).getName() << setw(20 - commodityManager.getAccessory(i).getName().length())
             << "|" << commodityManager.getAccessory(i).getQuantity() << setw(5 - to_string(commodityManager.getAccessory(i).getQuantity()).length())
             << "|" << commodityManager.getAccessory(i).getPrice() << setw(13 - to_string(commodityManager.getAccessory(i).getPrice()).length())
             << "|" << commodityManager.getAccessory(i).getWarrantyTime() << setw(17 - commodityManager.getAccessory(i).getWarrantyTime().length()) << "|" << endl;
    }
    cout << "+-----+----------+------------+-------------------+----+------------+----------------+" << endl;
    cout << "Ban muon xoa phu kien co so thu tu(chon (0) de xoa tat ca hoac nhan (x) de thoat): ";
    int i;
    string temp;
    getline(cin, temp);
    if (temp == "x" || temp == "X") {
        cout << "Xoa khong thanh cong!" << endl
             << "Ban co muon tiep tuc khong (Y/N): ";
        return;
    }
    while ((temp < "1" || temp> "9") && (stoi(temp) < 0 || stoi(temp) > commodityManager.getNumberOfAccessory())) {
        cout << "lua chon khong phu hop, vui long thu lai: ";
        getline(cin, str);
    }
    i = stoi(temp);
    if (i == 0) {
        for (int j = 0; j < commodityManager.getNumberOfAccessory(); j++)
            this->deleteAccessory(commodityManager.getAccessory(j));
        cout << "Xoa thanh cong!" << endl;
        cout << "Ban co muon tiep tuc khong (Y/N): ";
        return;
    }
    int index = this->indexOf(commodityManager.getAccessory(i - 1));
    if (index == -1) {
        cout << "Xoa khong thanh cong!" << endl;
        cout << "Ban co muon tiep tuc khong (Y/N): ";
        return;
    }
    deleteAt(index, "Accessory");
    cout << "Xoa thanh cong!" << endl;
    cout << "Ban co muon tiep tuc khong (Y/N): ";
}

void CommodityManager::swap(Guitar& g1, Guitar& g2) {
    Guitar temp = g1;
    g1 = g2;
    g2 = temp;
}

void CommodityManager::swap(Accessory& a1, Accessory& a2) {
    Accessory temp = a1;
    a1 = a2;
    a2 = temp;
}

void CommodityManager::sort(string commodity, string option) {
    if (commodity == "Guitar") {
        if (option == "ID") {
            for (int i = 0; i < this->numberOfGuitar - 1; i++)
                for (int j = 0; j < this->numberOfGuitar - i - 1; j++)
                    if ((this->guitar + j)->getID() > (this->guitar + j + 1)->getID())
                        swap(*(this->guitar + j), *(this->guitar + j + 1));
        }

        if (option == "Brand") {
            for (int i = 0; i < this->numberOfGuitar - 1; i++)
                for (int j = 0; j < this->numberOfGuitar - i - 1; j++)
                    if ((this->guitar + j)->getBrand() > (this->guitar + j + 1)->getBrand())
                        swap(*(this->guitar + j), *(this->guitar + j + 1));
        }
        if (option == "Name") {
            for (int i = 0; i < this->numberOfGuitar - 1; i++)
                for (int j = 0; j < this->numberOfGuitar - i - 1; j++)
                    if ((this->guitar + j)->getName() > (this->guitar + j + 1)->getName())
                        swap(*(this->guitar + j), *(this->guitar + j + 1));
        }
        if (option == "Quantity") {
            for (int i = 0; i < this->numberOfGuitar - 1; i++)
                for (int j = 0; j < this->numberOfGuitar - i - 1; j++)
                    if ((this->guitar + j)->getQuantity() > (this->guitar + j + 1)->getQuantity())
                        swap(*(this->guitar + j), *(this->guitar + j + 1));
        }
        if (option == "Price") {
            for (int i = 0; i < this->numberOfGuitar - 1; i++)
                for (int j = 0; j < this->numberOfGuitar - i - 1; j++)
                    if ((this->guitar + j)->getPrice() > (this->guitar + j + 1)->getPrice())
                        swap(*(this->guitar + j), *(this->guitar + j + 1));
        }
        if (option == "Full Name") {
            for (int i = 0; i < this->numberOfGuitar - 1; i++)
                for (int j = 0; j < this->numberOfGuitar - i - 1; j++)
                    if ((this->guitar + j)->getFullName() > (this->guitar + j + 1)->getFullName())
                        swap(*(this->guitar + j), *(this->guitar + j + 1));
        }
    }
    if (commodity == "Accessory") {
        if (option == "ID") {
            for (int i = 0; i < this->numberOfAccessory - 1; i++)
                for (int j = 0; j < this->numberOfAccessory - i - 1; j++)
                    if ((this->accessory + j)->getID() > (this->accessory + j + 1)->getID())
                        swap(*(this->accessory + j), *(this->accessory + j + 1));
        }

        if (option == "Type") {
            for (int i = 0; i < this->numberOfAccessory - 1; i++)
                for (int j = 0; j < this->numberOfAccessory - i - 1; j++)
                    if ((this->accessory + j)->getTypeOfCommodity() > (this->accessory + j + 1)->getTypeOfCommodity())
                        swap(*(this->accessory + j), *(this->accessory + j + 1));
        }
        if (option == "Name") {
            for (int i = 0; i < this->numberOfAccessory - 1; i++)
                for (int j = 0; j < this->numberOfAccessory - i - 1; j++)
                    if ((this->accessory + j)->getName() > (this->accessory + j + 1)->getName())
                        swap(*(this->accessory + j), *(this->accessory + j + 1));
        }
        if (option == "Quantity") {
            for (int i = 0; i < this->numberOfAccessory - 1; i++)
                for (int j = 0; j < this->numberOfAccessory - i - 1; j++)
                    if ((this->accessory + j)->getQuantity() > (this->accessory + j + 1)->getQuantity())
                        swap(*(this->accessory + j), *(this->accessory + j + 1));
        }
        if (option == "Price") {
            for (int i = 0; i < this->numberOfAccessory - 1; i++)
                for (int j = 0; j < this->numberOfAccessory - i - 1; j++)
                    if ((this->accessory + j)->getPrice() > (this->accessory + j + 1)->getPrice())
                        swap(*(this->accessory + j), *(this->accessory + j + 1));
        }
        if (option == "Full Name") {
            for (int i = 0; i < this->numberOfAccessory - 1; i++)
                for (int j = 0; j < this->numberOfAccessory - i - 1; j++)
                    if ((this->accessory + j)->getFullName() > (this->accessory + j + 1)->getFullName())
                        swap(*(this->accessory + j), *(this->accessory + j + 1));
        }
    }
}

void CommodityManager::showGuitarName() const {
    for (int i = 0; i < this->numberOfGuitar; i++) {
        cout << " --- " << (this->guitar + i)->getBrand() << " " <<(this->guitar + i)->getName() << endl;
    }
}

void CommodityManager::showAccessoryName() const {
    for (int i = 0; i < this->numberOfAccessory; i++)
        cout << " --- " << (this->accessory + i)->getName() << endl;
}

bool CommodityManager::hasGuitar() {
    if (this->numberOfGuitar > 0)
        return true;
    return false;
}

bool CommodityManager::hasAccessory() {
    if (this->numberOfAccessory > 0)
        return true;
    return false;
}

const CommodityManager& CommodityManager::findAllCommodity(string str, string option, string commodity) {
    CommodityManager *commodityManager = new CommodityManager();
    if (commodity == "Guitar") {
        int i = 0;
        int index = this->indexOf(str, option, commodity, i);
        while (index != -1) {
            commodityManager->push(this->getGuitar(index));
            i = index + 1;
            index = this->indexOf(str, option, commodity, i);
        }
    }
    if (commodity == "Accessory") {
        int i = 0;
        int index = this->indexOf(str, option, commodity, i);
        while (index != -1) {
            commodityManager->push(this->getAccessory(index));
            i = index + 1;
            index = this->indexOf(str, option, commodity, i);
        }
    }
    return *commodityManager;
}

const CommodityManager& CommodityManager::findAllName(string str, string option) {
    CommodityManager *commodityManager = new CommodityManager();
    if (option == "Guitar") {
        int i = 0;
        int index = this->indexOfName(str, option, i);
        while (index != -1) {
            commodityManager->push(this->getGuitar(index));
            i = index + 1;
            index = this->indexOfName(str, option, i);
        }
    }
    if (option == "Accessory") {
        int i = 0;
        int index = this->indexOfName(str, option, i);
        while (index != -1) {
            commodityManager->push(this->getAccessory(index));
            i = index + 1;
            index = this->indexOfName(str, option, i);
        }
    }

    return *commodityManager;
}

const CommodityManager& CommodityManager::operator=(const CommodityManager& commodity) {
    this->numberOfGuitar = 0;
    this->guitar = new Guitar[commodity.numberOfGuitar];
    for (int i = 0; i < commodity.numberOfGuitar; i++)
        this->push(*(commodity.guitar + i));

    this->numberOfAccessory = 0;
    this->accessory = new Accessory[commodity.numberOfAccessory];
    for (int i = 0; i < commodity.numberOfAccessory; i++)
        this->push(*(commodity.accessory + i));

    return *this;
}

void CommodityManager::addGuitar() {
    Guitar guitar;
    string str;
    cout << "Nhap ma guitar: ";
    getline(cin, str);
    if (str != "")
        guitar.setID(str);
    cout << "Nhap thuong hieu guitar: ";
    getline(cin, str);
    if (str != "")
        guitar.setBrand(str);
    cout << "Nhap ten guitar: ";
    getline(cin, str);
    if (str != "")
        guitar.setName(str);
    cout << "Nhap so luong guitar: ";
    getline(cin, str);
    if (str < "0" || str > "9") {
        cout << str << " is not number" << endl;
        return;
    }
    if (str != "")
        guitar.setQuantity(stoi(str));
    cout << "Nhap gia cua guitar: ";
    getline(cin, str);
    if (str < "0" || str > "9") {
        cout << str << " is not number" << endl;
        return;
    }
    if (str != "")
        guitar.setPrice(stoi(str));
    cout << "Nhap thoi gian bao hanh: ";
    getline(cin, str);
    if (str != "")
        guitar.setWarrantyTime(str);
    this->push(guitar);
}

void CommodityManager::addAccessory() {
    Accessory accessory;
    string str;
    cout << "Nhap ma phu kien: ";
    getline(cin, str);
    if (str != "")
        accessory.setID(str);
    cout << "Nhap loai phu kien: ";
    getline(cin, str);
    if (str != "")
        accessory.setTypeOfCommodoty(str);
    cout << "Nhap ten phu kien: ";
    getline(cin, str);
    if (str != "")
        accessory.setName(str);
    cout << "Nhap so luong phu kien: ";
    getline(cin, str);
    if (str < "0" || str > "9") {
        cout << str << " is not number" << endl;
        return;
    }
    if (str != "")
        accessory.setQuantity(stoi(str));
    cout << "Nhap gia cua phu kien: ";
    getline(cin, str);
    if (str < "0" || str > "9") {
        cout << str << " is not number" << endl;
        return;
    }
    if (str != "")
        accessory.setPrice(stoi(str));
    cout << "Nhap thoi gian bao hanh: ";
    getline(cin, str);
    if (str != "")
        accessory.setWarrantyTime(str);
    this->push(accessory);

}

ostream& operator<<(ostream& out, const CommodityManager& commodity){
    for (int i = 0; i < commodity.numberOfGuitar; i++) {
        out << *(commodity.guitar + i);
        out << "------------------------" << endl;
    }

    for (int i = 0; i < commodity.numberOfAccessory; i++) {
        out << *(commodity.accessory + i);
        out << "------------------------" << endl;
    }

    return out;
}
