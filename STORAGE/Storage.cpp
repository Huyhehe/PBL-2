#include "Storage.h"
#include <iostream>

using namespace std;

Storage::Storage() {
    this->numberOfAccessory = 0;
    this->guitar = nullptr;
    this->numberOfGuitar = 0;
    this->accessory = nullptr;
}

Storage::~Storage() {
    delete[] guitar;
    delete[] accessory;
}

void Storage::push(Guitar newGuitar) {
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

void Storage::push(Accessory newAccessory) {
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

void Storage::shift(Guitar newGuitar) {
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

void Storage::shift(Accessory newAccessory) {
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

int Storage::indexOf(string s, string option, string commodity) {
    if (commodity == "Guitar") {
        if (option == "ID") {
            for (int i = 0; i < this->numberOfGuitar; i++)
                if ((this->guitar + i)->getID() == s)
                    return i;
        }

        if (option == "Name") {
            for (int i = 0; i < this->numberOfGuitar; i++)
                if ((this->guitar + i)->getName() == s)
                    return i;
        }

        if (option == "Brand") {
            for (int i = 0; i < this->numberOfGuitar; i++)
                if ((this->guitar + i)->getBrand() == s)
                    return i;
        }
    }

    if (commodity == "Accessory") {
        if (option == "ID") {
            for (int i = 0; i < this->numberOfAccessory; i++)
                if ((this->accessory + i)->getID() == s)
                    return i;
        }

        if (option == "Name") {
            for (int i = 0; i < this->numberOfAccessory; i++)
                if ((this->accessory + i)->getName() == s)
                    return i;
        }

        if (option == "Type") {
            for (int i = 0; i < this->numberOfAccessory; i++)
                if ((this->accessory + i)->getTypeOfCommodity() == s)
                    return i;
        }
    }

    return -1;
}

int Storage::indexOf(Guitar guitar) {
    for (int i = 0; i < this->numberOfGuitar; i++) {
        if ((this->guitar + i)->getID() == guitar.getID())
            return i;
    }

    return -1;
}

int Storage::indexOf(Accessory accessory) {
    for (int i = 0; i < this->numberOfAccessory; i++) {
        if ((this->accessory + i)->getID() == accessory.getID())
            return i;
    }
    
    return -1;
}

void Storage::update(Guitar guitar, Guitar newGuitar) {
    int index = indexOf(guitar);

    if (index < 0) 
        return;

    *(this->guitar + index) = newGuitar;
}

void Storage::update(Accessory accessory, Accessory newAccessory) {
    int index = indexOf(accessory);

    if (index < 0) 
        return;

    *(this->accessory + index) = newAccessory;
}

void Storage::deleteAt(int index, string commodity) {
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

void Storage::deleteGuitar(Guitar guitar) {
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

void Storage::deleteAccessory(Accessory accessory) {
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

void Storage::swap(Guitar& g1, Guitar& g2) {
    Guitar temp = g1;
    g1 = g2;
    g2 = temp;
}

void Storage::swap(Accessory& a1, Accessory& a2) {
    Accessory temp = a1;
    a1 = a2;
    a2 = temp;
}

void Storage::sort(string commodity, string option) {
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
        if (option == "Warranty") {
            for (int i = 0; i < this->numberOfGuitar - 1; i++)
                for (int j = 0; j < this->numberOfGuitar - i - 1; j++)
                    if ((this->guitar + j)->getWarrantyTime() > (this->guitar + j + 1)->getWarrantyTime())
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
        if (option == "Warranty") {
            for (int i = 0; i < this->numberOfAccessory - 1; i++)
                for (int j = 0; j < this->numberOfAccessory - i - 1; j++)
                    if ((this->accessory + j)->getWarrantyTime() > (this->accessory + j + 1)->getWarrantyTime())
                        swap(*(this->accessory + j), *(this->accessory + j + 1));
        }
    }
}

void Storage::show() {
    for (int i = 0; i < this->numberOfGuitar; i++) {
        cout << *(this->guitar + i);
        cout << "------------------------" << endl;
    }
    for (int i = 0; i < this->numberOfAccessory; i++) {
        cout << *(this->accessory + i);
        cout << "------------------------" << endl;
    }
}