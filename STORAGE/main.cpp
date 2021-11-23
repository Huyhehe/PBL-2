#include <iostream>
#include "Storage.h"

using namespace std;

int main() {
    Guitar g1("1011", "epiphone", "TR-100", 10, 3000000, "2 nam");
    Guitar g2("1012", "epiphone", "BR-300", 10, 4500000, "2 nam");
    Guitar g3("1013", "epiphone", "ZR-400", 10, 2000000, "2 nam");
    Storage s;
    s.push(g3);
    s.push(g1);
    s.push(g2);
    s.push(g1);
    Accessory a1("0001", "capo", "er1", 5, 70000, "khong bao hanh");
    Accessory a2("0002", "day dan", "elixir", 7, 300000, "3 thang");
    // s.push(a1);
    // s.push(a2);
    // s.shift(g3);
    // s.shift(a2);
    // s.update(g1, Guitar("10044", "epiphone", "Dove", 5, 8000000, "2 nam"));
    // s.deleteGuitar(g2);
    // s.deleteAccessory(a2);
    // s.deleteAt(0, "Accessory");
    s.sort("Guitar", "Price");
    s.show();
}