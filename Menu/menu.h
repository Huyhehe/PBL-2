#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>
using namespace std;

string toString(int x);
string setColor(int color);
void employeeBoard(string inputFile);
void accessoryBoard(string inputFile);
void guitarBoard(string inputFile);
void accessoryMenu();
void guitarMenu();
void storageMenu();
void guestMenu();
void employeeMenu();
void receiptMenu();
void manageMenu();
void mainMenu();


void mainMenu() {
    string choice;
    system("cls");
    system("Color 07");
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                   GUITAR STORE                   +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                    MAIN MENU                     +" << endl
         << "+ 1. Quan ly                                       +" << endl
         << "+ 2. In hoa don                                    +" << endl
         << "+ 3. Kiem tra bao hanh                             +" << endl
         << "+ 4. Thoat                                         +" << endl
         << "+                                                  +" << endl
         << "+                                                  +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Nhap lua chon: "; cin >> choice;
    if (choice.length() > 1 || choice < "1" || choice > "4") {
        do {
            cout << setColor(4) << "Lua chon khong hop le, vui long chon lai: " << setColor(255);
            cin >> choice;
        } while(choice.length() > 1 || choice < "1" || choice > "4");
    }
    int intChoice = 0;
    if (choice == "1") {
        intChoice = 1;
    }
    if (choice == "2") {
        intChoice = 2;
    }
    if (choice == "3") {
        intChoice = 3;
    }
    if (choice == "4") {
        intChoice = 4;
    }
    switch(intChoice) {
        case 1: {
            system("cls");
            manageMenu();
            break;
        }
        case 2: {
            system("cls");
            receiptMenu();
        }
        case 3: {
            system("cls");
            // warrantyCheck();
            break;
        }
        case 4: {
            system("cls");
            cout << "DA THOAT!";
            break;
        }
        default: break;
    }
}

void manageMenu() {
    system("cls");
    system("Color 07");
    string choice;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                   GUITAR STORE                   +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                     QUAN LY                      +" << endl
         << "+ 1. Nhan vien                                     +" << endl
         << "+ 2. Kho                                           +" << endl
         << "+ 3. Quay lai                                      +" << endl
         << "+ 4. Thoat                                         +" << endl
         << "+                                                  +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Nhap lua chon: "; cin >> choice;
    if (choice.length() > 1 || choice < "1" || choice > "4") {
        do {
            cout << setColor(4) << "Lua chon khong hop le, vui long chon lai: " << setColor(255);
            cin >> choice;
        } while(choice.length() > 1 || choice < "1" || choice > "4");
    }
    int intChoice = 0;
    if (choice == "1") {
        intChoice = 1;
    }
    if (choice == "2") {
        intChoice = 2;
    }
    if (choice == "3") {
        intChoice = 3;
    }
    if (choice == "4") {
        intChoice = 4;
    }
    switch(intChoice) {
        case 1: {
            system("cls");
            employeeMenu();
            break;
        }
        case 2: {
            system("cls");
            storageMenu();
            break;
        }
        case 3: {
            //go back
            system("cls");
            mainMenu();
            break;
        }
        case 4: {
            system("cls");
            cout << "DA THOAT!";
            break;
        }
        default: {
            break;
        }
    }
}

bool checkContinue(string continueOption) {
    if (continueOption != "Y" && continueOption != "y" && continueOption != "N" && continueOption != "n") {
        do {
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            cin >> continueOption;
        } while (continueOption != "Y" && continueOption != "y" && continueOption != "N" && continueOption != "n");
    }
    if (continueOption == "Y" || continueOption == "y") {
        return 1;
    }
    else if (continueOption == "N" || continueOption == "n"){
        return 0;
    }
    return 0;
}

void receiptMenu() {
    tryAgain:
    system("Color 0A");
    cout << "Da in hoa don thanh cong" << endl
         << "Ban co muon tiep tuc khong (Y/N): ";
    string continueOption;
    cin >> continueOption;
    if (checkContinue(continueOption)) {
        goto tryAgain;
    } else {
        system("cls");
        mainMenu();
    }
}

void employeeMenu() {
    tryAgain:
    system("cls");
    system("Color 07");
    string choice;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                   GUITAR STORE                   +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                    NHAN VIEN                     +" << endl
         << "+ 1. Them nhan vien                                +" << endl
         << "+ 2. Xoa nhan vien                                 +" << endl
         << "+ 3. Thong tin nhan vien                           +" << endl
         << "+ 4. Quay lai                                      +" << endl
         << "+ 5. Thoat                                         +" << endl
         << "+                                                  +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Nhap lua chon: "; cin >> choice;
    if (choice.length() > 1 || choice < "1" || choice > "5") {
        do {
            cout << setColor(4) << "Lua chon khong hop le, vui long chon lai: " << setColor(255);
            cin >> choice;
        } while(choice.length() > 1 || choice < "1" || choice > "5");
    }
    int intChoice = 0;
    if (choice == "1") {
        intChoice = 1;
    }
    if (choice == "2") {
        intChoice = 2;
    }
    if (choice == "3") {
        intChoice = 3;
    }
    if (choice == "4") {
        intChoice = 4;
    }
    if (choice == "5") {
        intChoice = 5;
    }
    switch(intChoice) {
        case 1: {
            system("cls");
            system("Color 0A");
            cout << "Them nhan vien thanh cong" << endl
                 << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            if (checkContinue(continueOption)) {
                goto tryAgain;
            }
            break;
        }
        case 2: {
            system("cls");
            cout << "Xoa nhan vien thanh cong" << endl
                 << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 3: {
            system("cls");
            employeeBoard("../Data/Employee.txt");
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 4: {
            //go back
            system("cls");
            manageMenu();
            break;
        }
        case 5: {
            system("cls");
            cout << "DA THOAT!";
            break;
        }
        default: {
            break;
        }
    }
}

void storageMenu() {
    system("cls");
    system("Color 07");
    string choice;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                   GUITAR STORE                   +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                       KHO                        +" << endl
         << "+ 1. Guitar                                        +" << endl
         << "+ 2. Phu kien                                      +" << endl
         << "+ 3. Quay lai                                      +" << endl
         << "+ 4. Thoat                                         +" << endl
         << "+                                                  +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Nhap lua chon: "; cin >> choice;
    if (choice.length() > 1 || choice < "1" || choice > "4") {
        do {
            cout << setColor(4) << "Lua chon khong hop le, vui long chon lai: " << setColor(255);
            cin >> choice;
        } while(choice.length() > 1 || choice < "1" || choice > "4");
    }
    int intChoice = 0;
    if (choice == "1") {
        intChoice = 1;
    }
    if (choice == "2") {
        intChoice = 2;
    }
    if (choice == "3") {
        intChoice = 3;
    }
    if (choice == "4") {
        intChoice = 4;
    }
    switch(intChoice) {
        case 1: {
            system("cls");
            guitarMenu();
            break;
        }
        case 2: {
            system("cls");
            accessoryMenu();
            break;
        }
        case 3: {
            //go back
            system("cls");
            manageMenu();
            break;
        }
        case 4: {
            system("cls");
            cout << "DA THOAT!";
            break;
        }
        default: {
            break;
        }
    }
}

void guitarMenu() {
    tryAgain:
    system("cls");
    system("Color 07");
    string choice;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                   GUITAR STORE                   +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                      GUITAR                      +" << endl
         << "+ 1. Xem tat ca                                    +" << endl
         << "+ 2. Tim theo ten                                  +" << endl
         << "+ 3. Them vao kho                                  +" << endl
         << "+ 4. Xoa khoi kho                                  +" << endl
         << "+ 5. Quay lai                                      +" << endl
         << "+ 6. Thoat                                         +" << endl
         << "+                                                  +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Nhap lua chon: "; cin >> choice;
    if (choice.length() > 1 || choice < "1" || choice > "6") {
        do {
            cout << setColor(4) << "Lua chon khong hop le, vui long chon lai: " << setColor(255);
            cin >> choice;
        } while(choice.length() > 1 || choice < "1" || choice > "6");
    }
    int intChoice = 0;
    if (choice == "1") {
        intChoice = 1;
    }
    if (choice == "2") {
        intChoice = 2;
    }
    if (choice == "3") {
        intChoice = 3;
    }
    if (choice == "4") {
        intChoice = 4;
    }
    if (choice == "5") {
        intChoice = 5;
    }
    if (choice == "6") {
        intChoice = 6;
    }
    switch(intChoice) {
        case 1: {
            system("cls");
            guitarBoard("../Data/Guitar.txt");
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 2: {
            system("cls");
            cout << "Nhap ten loai dan ban muon tim: " << endl
                 << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 3: {
            system("cls");
            // them vao kho
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 4: {
            system("cls");
            // xoa khoi kho
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 5: {
            //go back
            system("cls");
            storageMenu();
            break;
        }
        case 6: {
            system("cls");
            cout << "DA THOAT!";
            break;
        }
        default: {
            break;
        }
    }
}

void accessoryMenu() {
    tryAgain:
    system("cls");
    system("Color 07");
    string choice;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                   GUITAR STORE                   +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                     PHU KIEN                     +" << endl
         << "+ 1. Xem tat ca                                    +" << endl
         << "+ 2. Tim theo ten                                  +" << endl
         << "+ 3. Them vao kho                                  +" << endl
         << "+ 4. Xoa khoi kho                                  +" << endl
         << "+ 5. Quay lai                                      +" << endl
         << "+ 6. Thoat                                         +" << endl
         << "+                                                  +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Nhap lua chon: "; cin >> choice;
    if (choice.length() > 1 || choice < "1" || choice > "6") {
        do {
            cout << setColor(4) << "Lua chon khong hop le, vui long chon lai: " << setColor(255);
            cin >> choice;
        } while(choice.length() > 1 || choice < "1" || choice > "6");
    }
    int intChoice = 0;
    if (choice == "1") {
        intChoice = 1;
    }
    if (choice == "2") {
        intChoice = 2;
    }
    if (choice == "3") {
        intChoice = 3;
    }
    if (choice == "4") {
        intChoice = 4;
    }
    if (choice == "5") {
        intChoice = 5;
    }
    if (choice == "6") {
        intChoice = 6;
    }
    switch(intChoice) {
        case 1: {
            system("cls");
            // system("Color 0A");
            accessoryBoard("../Data/Accessory.txt");
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 2: {
            system("cls");
            // system("Color 0A");
            cout << "Nhap ten loai phu kien ban muon tim: " << endl
                 << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 3: {
            system("cls");
            // system("Color 0A");
            // them vao kho
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 4: {
            system("cls");
            // system("Color 0A");
            // xoa khoi kho
            cout << "Ban co muon tiep tuc khong (Y/N): ";
            string continueOption;
            cin >> continueOption;
            if (checkContinue(continueOption)) {
                goto tryAgain;
            } else {
                system("cls");
                cout << "DA THOAT!";
            }
            break;
        }
        case 5: {
            //go back
            system("cls");
            storageMenu();
            break;
        }
        case 6: {
            system("cls");
            cout << "DA THOAT!";
            break;
        }
        default: {
            break;
        }
    }
}

void employeeBoard(string inputFile) {
    struct empProp {
        int index;
        string ID;
        string name;
        string ngaysinh;
        string gentle;
        string phoneNum;
        string email;
        string address;
        string dateStart;
        string dateEnd;
        string check;
        string salary;
    };
    string str;
    struct empProp arr[100];
    int i = 0;
    int j = 0;
    int h = 1;
    ifstream infile;
    infile.open(inputFile, ios::in);
    cout << "+-----+----------+------------------------------+-----------+----+-----------+" << endl; //5, 10, 30, 11, 4, 11 
    cout << "| STT |    ID    |            Ho ten            | Ngay sinh | GT |    SDT    |" << endl;
    cout << "+-----+----------+------------------------------+-----------+----+-----------+" << endl;
    while (!infile.eof()) {
        getline(infile, str);
        if (str == "") {
            i = 0;
            continue;
        }
        arr[j].index = h;
        switch(i) {
            case 0: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].ID = str;
                i++;
                break;
            }
            case 1: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].name = str;
                i++;
                break;
            }
            case 2: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].ngaysinh = str;
                i++;
                break;
            }
            case 3: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].gentle = str;
                i++;
                break;
            }
            case 4: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].phoneNum = str;
                i++;
                break;
            }
            case 5: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].email = str;
                i++;
                break;
            }
            case 6: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].address = str;
                i++;
                break;
            }
            case 7: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].dateStart = str;
                i++;
                break;
            }
            case 8: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].dateEnd = str;
                i++;
                break;
            }
            case 9: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].check = str;
                i++;
                break;
            }
            case 10: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].salary = str;
                i = 0;
                j++;
                h++;
                break;
            }
            default: break;
        }
    }
    int k = j;
    for (j = 0 ; j < k ; j++) {
        cout << "|" << toString(arr[j].index) << arr[j].index << setw(toString(arr[j].index).length
        () + 1)
             << "|" << arr[j].ID << setw(11 - arr[j].ID.length()) 
             << "|" << arr[j].name << setw(31 - arr[j].name.length()) 
             << "|" << arr[j].ngaysinh << setw(12 - arr[j].ngaysinh.length()) 
             << "|" << arr[j].gentle << setw(5 - arr[j].gentle.length())
             << "|" << arr[j].phoneNum << setw(12 - arr[j].phoneNum.length()) << "|" << endl;
    }
    cout << "+-----+----------+------------------------------+-----------+----+-----------+" << endl;
    infile.close();
}

void guitarBoard(string inputFile) {
    struct empProp {
        int index;
        string ID;
        string name;
        string brand;
        string amount;
        string price;
        string warrantyTime;
    };
    string str;
    struct empProp arr[100];
    int i = 0;
    int j = 0;
    int h = 1;
    ifstream infile;
    infile.open(inputFile, ios::in);
    cout << "+-----+----------+-------------------+-----------+----+------------+----------+" << endl; //5, 10, 19, 11, 4, 12, 10
    cout << "| STT |    ID    |    Thuong hieu    |    Ten    | SL |  Gia tien  | Bao hanh |" << endl;
    cout << "+-----+----------+-------------------+-----------+----+------------+----------+" << endl;
    while (!infile.eof()) {
        getline(infile, str);
        if (str == "") {
            i = 0;
            continue;
        }
        arr[j].index = h;
        switch(i) {
            case 0: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].ID = str;
                i++;
                break;
            }
            case 1: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].brand = str;
                i++;
                break;
            }
            case 2: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].name = str;
                i++;
                break;
            }
            case 3: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].amount = str;
                i++;
                break;
            }
            case 4: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].price = str;
                i++;
                break;
            }
            case 5: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].warrantyTime = str;
                i = 0;
                j++;
                h++;
                break;
            }
            default: break;
        }
    }
    int k = j;
    for (j = 0 ; j < k ; j++) {
        cout << "|" << toString(arr[j].index) << arr[j].index << setw(toString(arr[j].index).length
        () + 1)
             << "|" << arr[j].ID << setw(11 - arr[j].ID.length()) 
             << "|" << arr[j].brand << setw(20 - arr[j].brand.length()) 
             << "|" << arr[j].name << setw(12 - arr[j].name.length()) 
             << "|" << arr[j].amount << setw(5 - arr[j].amount.length())
             << "|" << arr[j].price << setw(13 - arr[j].price.length())
             << "|" << arr[j].warrantyTime << setw(11 - arr[j].warrantyTime.length()) << "|" << endl;
    }
    cout << "+-----+----------+-------------------+-----------+----+------------+----------+" << endl;
    infile.close();
}

void accessoryBoard(string inputFile) {
    struct empProp {
        int index;
        string ID;
        string name;
        string type;
        string amount;
        string price;
        string warrantyTime;
    };
    string str;
    struct empProp arr[100];
    int i = 0;
    int j = 0;
    int h = 1;
    ifstream infile;
    infile.open(inputFile, ios::in);
    cout << "+-----+----------+------------+-------------+----+------------+----------------+" << endl; //10, 12, 13, 4, 12, 16
    cout << "| STT |    ID    |    Loai    |     Ten     | SL |  Gia tien  |    Bao hanh    |" << endl;
    cout << "+-----+----------+------------+-------------+----+------------+----------------+" << endl;
    while (!infile.eof()) {
        getline(infile, str);
        if (str == "") {
            i = 0;
            continue;
        }
        arr[j].index = h;
        switch(i) {
            case 0: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].ID = str;
                i++;
                break;
            }
            case 1: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].type = str;
                i++;
                break;
            }
            case 2: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].name = str;
                i++;
                break;
            }
            case 3: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].amount = str;
                i++;
                break;
            }
            case 4: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].price = str;
                i++;
                break;
            }
            case 5: {
                str = str.substr(str.find(":") + 2, str.length());
                arr[j].warrantyTime = str;
                i = 0;
                j++;
                h++;
                break;
            }
            default: break;
        }
    }
    int k = j;
    for (j = 0 ; j < k ; j++) {
        cout << "|" << toString(arr[j].index) << arr[j].index << setw(toString(arr[j].index).length
        () + 1)
             << "|" << arr[j].ID << setw(11 - arr[j].ID.length()) 
             << "|" << arr[j].type << setw(13 - arr[j].type.length()) 
             << "|" << arr[j].name << setw(14 - arr[j].name.length()) 
             << "|" << arr[j].amount << setw(5 - arr[j].amount.length())
             << "|" << arr[j].price << setw(13 - arr[j].price.length())
             << "|" << arr[j].warrantyTime << setw(17 - arr[j].warrantyTime.length()) << "|" << endl;
    }
    cout << "+-----+----------+------------+-------------+----+------------+----------------+" << endl;
    infile.close();
}

string setColor(int color)
{
	WORD colr;
     HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO info;
     if(GetConsoleScreenBufferInfo(out, &info))
     {
          colr = (info.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(out, colr);
     }
     return "";
}

string toString(int x) {
    string str;
    if (x < 10) {
        str = "00";
    }
    else if (x >= 10 && x < 100) {
        str = "0";
    } else {
        str = "";
    }
    return str;
}