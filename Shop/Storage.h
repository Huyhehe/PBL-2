#pragma once
#include "Guitar.h"
#include "Accessory.h"
class Storage {
    private:
        Guitar* guitar;
        int numberOfGuitar;
        Accessory* accessory;
        int numberOfAccessory;
    public:
        Storage();
        Storage(const Storage&);
        ~Storage();
        int getNumberOfGuitar() const;
        int getNumberOfAccessory() const;
        void push(Guitar);
        void push(Accessory);
        void shift(Guitar);
        void shift(Accessory);
        int indexOf(Guitar);
        int indexOf(Accessory);
        int indexOf(string, string, string);
        void update(Guitar, Guitar);
        void update(Accessory, Accessory);
        void deleteAt(int, string);
        void deleteGuitar(Guitar);
        void deleteAccessory(Accessory);
        void swap(Guitar&, Guitar&);
        void swap(Accessory&, Accessory&);
        void sort(string, string);
        void show();
};