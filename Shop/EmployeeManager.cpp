#include "EmployeeManager.h"
#include <iomanip>

EmployeeManager::EmployeeManager() {
    this->numberOfEmployee = 0;
    this->emp = nullptr;
}

EmployeeManager::EmployeeManager(int length) {
    this->numberOfEmployee = length;
    this->emp = new Employee[length];
}

EmployeeManager::~EmployeeManager() {
    delete[] this->emp;
}

int EmployeeManager::getNumberOfEmployee() const {
    return this->numberOfEmployee;
}

void EmployeeManager::push(Employee newEmp) {
    if (this->numberOfEmployee == 0) {
        this->emp = new Employee[this->numberOfEmployee+ 1];
        *(this->emp + this->numberOfEmployee) = newEmp;
    } else {
        Employee *temp = new Employee[this->numberOfEmployee];
        for (int i = 0; i < this->numberOfEmployee; i++)
            *(temp + i) = *(this->emp + i);
        delete[] this->emp;

        this->emp = new Employee[this->numberOfEmployee + 1];
        for (int i = 0; i < this->numberOfEmployee; i++)
            *(this->emp + i) = *(temp + i);
        *(this->emp + this->numberOfEmployee) = newEmp;
    }

    this->numberOfEmployee += 1;
}

void EmployeeManager::shift(Employee newEmp) {
    if (this->emp == 0) {
        this->emp = new Employee[this->numberOfEmployee + 1];
        *(this->emp + this->numberOfEmployee) = newEmp;
    } else {
        Employee *temp = new Employee[this->numberOfEmployee];
        for (int i = 0; i < this->numberOfEmployee; i++)
            *(temp + i) = *(this->emp + i);
        delete[] this->emp;

        this->emp = new Employee[this->numberOfEmployee + 1];
        for (int i = 0; i < this->numberOfEmployee; i++) {
            *(this->emp + i + 1) = *(temp + i);
        }
        *(this->emp) = newEmp;
    }

    this->numberOfEmployee += 1;
}

int EmployeeManager::indexOf(string s, string option, int startIndex) {
    if (option == "ID") {
        for (int i = startIndex; i < this->numberOfEmployee; i++)
            if ((this->emp + i)->getID() == s)
                return i;
    }

    if (option == "Name") {
        for (int i = startIndex; i < this->numberOfEmployee; i++)
            if ((this->emp + i)->getName() == s)
                return i;
    }

    if (option == "Gender") {
        for (int i = startIndex; i < this->numberOfEmployee; i++)
            if ((this->emp + i)->getGender() == s)
                return i;
    }

    if (option == "Date Of Birth") {
        Date date = stringToDate(s);
        for (int i = startIndex; i < this->numberOfEmployee; i++) {
            if ((this->emp + i)->getDateOfBirth() == date)
                return i;
        }
    }

    if (option == "Phone") {
        for (int i = startIndex; i < this->numberOfEmployee; i++)
            if ((this->emp + i)->getPhoneNumber() == s)
                return i;
    }

    if (option == "Email") {
        for (int i = startIndex; i < this->numberOfEmployee; i++)
            if ((this->emp + i)->getEmail() == s)
                return i;
    }

    if (option == "Address") {
        for (int i = startIndex; i < this->numberOfEmployee; i++)
            if ((this->emp + i)->getAddress() == s)
                return i;
    }

    if (option == "Date In") {
        Date date = stringToDate(s);
        for (int i = startIndex; i < this->numberOfEmployee; i++)
            if ((this->emp + i)->getContract().Contract_getDateIn() == date)
                return i;
    }

    if (option == "Date Out") {
        Date date = stringToDate(s);
        for (int i = startIndex; i < this->numberOfEmployee; i++)
            if ((this->emp + i)->getContract().Contract_getDateOut() == date)
                return i;
    }

    if (option == "Salary") {
        for (int i = startIndex; i < this->numberOfEmployee; i++)
            if ((this->emp + i)->getSalary() == stoi(s))
                return i;
    }

    return -1;
}


int EmployeeManager::indexOf(const Contract& cont) {
    for (int i = 0; i < this->numberOfEmployee; i++)
        if ((this->emp + i)->getContract() == cont)
            return i;
    return -1;
}

int EmployeeManager::indexOf(const Employee& emp) {
    return indexOf(emp.getID(), "ID", 0);
}

int EmployeeManager::indexOfStatus(bool isFullTime, int startIndex) {
    for (int i = startIndex; i < this->numberOfEmployee; i++)
        if ((this->emp + i)->getContract().Contract_getIsFullTime() == isFullTime)
            return i;
    return -1;
}

int EmployeeManager::indexOf(long salary, int startIndex) {
    for (int i = startIndex; i < this->numberOfEmployee; i++)
        if ((this->emp + i)->getSalary() == salary)
            return i;
    return -1;
}

void EmployeeManager::update(Employee currentEmp, Employee newEmp) {
    int index = this->indexOf(currentEmp);

    if (index < 0)
        return;
    *(this->emp + index) = newEmp;
}

void EmployeeManager::update(string currentData, string newData, string option) {
    if (option == "ID") {
        int index = this->indexOf(currentData, option);
        (this->emp + index)->setID(newData);
    }

    if (option == "Name") {
        int index = this->indexOf(currentData, option);
        (this->emp + index)->setName(newData);
    }

    if (option == "Date") {
        Date date = stringToDate(currentData);
        int index = this->indexOf(currentData, option);
        date = stringToDate(newData);
        (this->emp + index)->setDateOfBirth(date);
    }
    if (option == "Gender") {
        int index = this->indexOf(currentData, option);
        (this->emp + index)->setGender(newData);
    }

    if (option == "Phone") {
        int index = this->indexOf(currentData, option);
        (this->emp + index)->setPhoneNumber(newData);
    }

    if (option == "Email") {
        int index = this->indexOf(currentData, option);
        (this->emp + index)->setEmail(newData);
    }

    if (option == "Address") {
        int index = this->indexOf(currentData, option);
        (this->emp + index)->setAddress(newData);
    }
}

void EmployeeManager::updateData(string str, string option) {
    EmployeeManager emp;
    if (option != "Name") {
        if (option == "Full Name")
            option = "Name";
        emp = this->findAllEmployee(str, option);
    } else
        emp = this->findAllLastName(str);
    cout << "+-----+----------+------------------------------+-----------+----+-----------+" << endl; //5, 10, 30, 11, 4, 11
    cout << "| STT |    ID    |            Ho ten            | Ngay sinh | GT |    SDT    |" << endl;
    cout << "+-----+----------+------------------------------+-----------+----+-----------+" << endl;
    for (int i = 0 ; i < emp.getNumberOfEmployee(); i++) {
        string temp;
        if (i < 10)
            temp = "00";
        if (i >= 10 && i < 100)
            temp = "0";
        cout << "|" << temp << i + 1 << setw(3)
             << "|" << emp[i].getID() << setw(11 - emp[i].getID().length())
             << "|" << emp[i].getName() << setw(31 - emp[i].getName().length())
             << "|" << emp[i].getDateOfBirth() << setw(12 - emp[i].getDateOfBirth().getDate().length())
             << "|" << emp[i].getGender() << setw(5 - emp[i].getGender().length())
             << "|" << emp[i].getPhoneNumber() << setw(12 - emp[i].getPhoneNumber().length()) << "|" << endl;
    }
    cout << "+-----+----------+------------------------------+-----------+----+-----------+" << endl;
    cout << "Ban muon sua doi nhan vien co so thu tu (chon (0) de chinh sua tat ca hoac (x) de thoat): ";
    string temp;
    getline(cin, temp);
    if (temp == "x" || temp == "X") {
        cout << "Chinh sua thong tin nhan vien khong thanh cong!" << endl;
        cout << "Ban co muon tiep tuc khong (Y/N): ";
        return;
    }
    while (temp < "0" || temp > "9") {
        cout << "Lua chon khong hop le, vui long thu lai: ";
        getline(cin, temp);
    }
    int index = stoi(temp);
    while (index < 0 || index > emp.getNumberOfEmployee()) {
        cout << "Lua chon khong phu hop, vui long chon lai: ";
        cin >> index;
        cin.ignore();
    }
    system("cls");
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+                   GUITAR STORE                   +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
         << "+         LUA CHON THONG TIN MUON CHINH SUA        +" << endl
         << "+ 1. Ma nhan vien.                                 +" << endl
         << "+ 2. Ho va ten Nhan Vien.                          +" << endl
         << "+ 3. Ngay sinh.                                    +" << endl
         << "+ 4. Gioi tinh.                                    +" << endl
         << "+ 5. So dien thoai.                                +" << endl
         << "+ 6. Email.                                        +" << endl
         << "+ 7. Dia chi.                                      +" << endl
         << "+ 8. Ngay bat dau lam viec.                        +" << endl
         << "+ 9. Ngay het hop dong lam viec.                   +" << endl
         << "+ 10. Tien luong.                                  +" << endl
         << "+ 11. Ten nhan vien.                               +" << endl
         << "+                                                  +" << endl
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Hay nhap lua chon cua ban: ";
    int j = 0;
    cin >> j;
    cin.ignore();
    while (j < 1 || j > 11) {
        cout << "Lua chon khong hop le, vui long nhap lai lua chon cua ban: ";
        cin >> j;
        cin.ignore();
    }
    string s;
    int i = index - 1;
    bool updateAll = false;
    if (index == 0) {
        updateAll = true;
        i = 0;
    }
    while (i < emp.getNumberOfEmployee()) {
        switch(j) {
            case 1: {
                cout << "Nhap ID moi: ";
                //getline(cin, s);
                getline(cin, s);
                Employee temp = emp[i];
                temp.setID(s);
                this->update(emp[i], temp);
                break;
            }
            case 2: {
                cout << "Nhap ho va ten moi: ";
                //getline(cin, s);
                getline(cin, s);
                Employee temp = emp[i];
                temp.setName(s);
                this->update(emp[i], temp);
                break;
            }
            case 3: {
                cout << "Nhap ngay sinh moi(dd/mm/yyyy): ";
                //getline(cin, s);
                getline(cin, s);
                Employee temp = emp[i];
                temp.setDateOfBirth(stringToDate(s));
                this->update(emp[i], temp);
                break;
            }
            case 4: {
                cout << "Nhap gioi tinh moi: ";
                //getline(cin, s);
                getline(cin, s);
                Employee temp = emp[i];
                temp.setGender(s);
                this->update(emp[i], temp);
                break;
            }
            case 5: {
                cout << "Nhap so dien thoai moi: ";
                //getline(cin, s);
                getline(cin, s);
                Employee temp = emp[i];
                temp.setPhoneNumber(s);
                this->update(emp[i], temp);
                break;
            }
            case 6: {
                cout << "Nhap Email moi: ";
                //getline(cin, s);
                getline(cin, s);
                Employee temp = emp[i];
                temp.setEmail(s);
                this->update(emp[i], temp);
                break;
            }
            case 7: {
                cout << "Nhap dia chi moi: ";
                //getline(cin, s);
                getline(cin, s);
                Employee temp = emp[i];
                temp.setAddress(s);
                this->update(emp[i], temp);
                break;
            }
            case 8: {
                cout << "Nhap ngay bat dau lam viec: ";
                //getline(cin, s);
                getline(cin, s);
                Employee temp = emp[i];
                temp.setContract(Contract(stringToDate(s), temp.getContract().Contract_getDateOut(), temp.getContract().Contract_getIsFullTime()));
                this->update(emp[i], temp);
                break;
            }
            case 9: {
                cout << "Nhap ngay ket thuc hop dong lam viec: ";
                //getline(cin, s);
                getline(cin, s);
                Employee temp = emp[i];
                temp.setContract(Contract(temp.getContract().Contract_getDateIn(), stringToDate(s), temp.getContract().Contract_getIsFullTime()));
                this->update(emp[i], temp);
                break;
            }
            case 10: {
                cout << "Nhap hinh thuc nhan vien((y): Full Time / (n): Past Time): ";
                //getline(cin, s);
                getline(cin, s);
                Employee temp = emp[i];
                bool isFullTime;
                if (s == "y")
                    isFullTime = true;
                else
                    isFullTime = false;
                temp.setContract(Contract(temp.getContract().Contract_getDateIn(), temp.getContract().Contract_getDateOut(), isFullTime));
                this->update(emp[i], temp);
            }
            case 11: {
                cout << "Nhap tien luong: ";
                //getline(cin, s);
                getline(cin, s);
                Employee temp = emp[i];
                temp.setSalary(stol(s));
                this->update(emp[i], temp);
            }
            default:
                break;
        }
        if (updateAll)
            i++;
        else
            break;
    }
    cout << "Chinh sua thong tin nhan vien thanh cong!" << endl
         << "Ban co muon tiep tuc khong (Y/N): ";
}

void EmployeeManager::updateSalary(long salary) {
    int index = this->indexOf(salary);
    (this->emp + index)->setSalary(salary);
}

void EmployeeManager::remove(int index) {
    if (index < 0 || index >= this->numberOfEmployee)
            return;

        for (int i = index; i < this->numberOfEmployee - 1; i++)
            *(this->emp + i) = *(this->emp + i + 1);

        Employee *temp = new Employee[this->numberOfEmployee - 1];

        for (int i = 0; i < this->numberOfEmployee - 1; i++)
            *(temp + i) = *(this->emp + i);
        delete[] this->emp;

        if (this->numberOfEmployee > 1) {
            this->emp = new Employee[this->numberOfEmployee - 1];
            for (int i = 0; i < this->numberOfEmployee- 1; i++)
                *(this->emp + i) = *(temp + i);
        }
        this->numberOfEmployee--;
}

void EmployeeManager::remove(Employee emp) {
    int index = indexOf(emp);
    remove(index);
}

void EmployeeManager::deleteEmployee(string str, string option) {
    EmployeeManager emp;
    if (option != "Name") {
        if (option == "Full Name")
            option = "Name";
        emp = this->findAllEmployee(str, option);
    } else
        emp = this->findAllLastName(str);
    cout << "+-----+----------+------------------------------+-----------+----+-----------+" << endl; //5, 10, 30, 11, 4, 11
    cout << "| STT |    ID    |            Ho ten            | Ngay sinh | GT |    SDT    |" << endl;
    cout << "+-----+----------+------------------------------+-----------+----+-----------+" << endl;
    for (int i = 0 ; i < emp.getNumberOfEmployee(); i++) {
        string temp;
        if (i < 10)
            temp = "00";
        if (i >= 10 && i < 100)
            temp = "0";
        cout << "|" << temp << i + 1 << setw(3)
             << "|" << emp[i].getID() << setw(11 - emp[i].getID().length())
             << "|" << emp[i].getName() << setw(31 - emp[i].getName().length())
             << "|" << emp[i].getDateOfBirth() << setw(12 - emp[i].getDateOfBirth().getDate().length())
             << "|" << emp[i].getGender() << setw(5 - emp[i].getGender().length())
             << "|" << emp[i].getPhoneNumber() << setw(12 - emp[i].getPhoneNumber().length()) << "|" << endl;
    }
    cout << "+-----+----------+------------------------------+-----------+----+-----------+" << endl;
    cout << "Ban muon xoa nhan vien co so thu tu(chon (0) de xoa tat ca hoac nhan (x) de thoat): ";
    string temp;
    getline(cin, temp);
    if (temp == "x" || temp == "X") {
        cout << "Xoa nhan vien khong thanh cong!" << endl
             << "Ban co muon tiep tuc khong (Y/N): ";
        return;
    }
    while (temp < "0" || temp > "9") {
        cout << "Lua chon khong hop le, vui long thu lai: ";
        getline(cin, temp);
    }
    int i = stoi(temp);
    while (i < 0 || i > emp.getNumberOfEmployee()) {
        cout << "Lua chon khong hop le, vui long thu lai: ";
        cin >> i;
        cin.ignore();
    }
    if (i == 0) {
        for (int j = 0; j < emp.getNumberOfEmployee(); j++)
            this->remove(emp[j]);
        cout << "Xoa nhan vien khong thanh cong!" << endl
             << "Ban co muon tiep tuc khong (Y/N): ";
        return;
    }
    int index = this->indexOf(emp[i - 1]);
    if (index == -1) {
        cout << "Xoa nhan vien khong thanh cong!" << endl
             << "Ban co muon tiep tuc khong (Y/N): ";
        return;
    }
    remove(index);
    cout << "Xoa nhan vien khong thanh cong!" << endl
         << "Ban co muon tiep tuc khong (Y/N): ";
}

void EmployeeManager::deleteAllLastName(string name) {
    EmployeeManager emp = this->findAllLastName(name);
    int i = 0;
    while (i < emp.getNumberOfEmployee()) {
        if (this->indexOf(emp[i]) != -1) {
            this->remove(emp[i]);
        }
        i++;
    }
}

void EmployeeManager::deleteAllEmployee(string str, string option) {
    EmployeeManager emp = this->findAllEmployee(str, option);
    int i = 0;
    while (i < emp.getNumberOfEmployee()) {
        if (this->indexOf(emp[i]) != -1) {
            this->remove(emp[i]);
        }
        i++;
    }
    cout << "Xoa nhan vien thanh cong!" << endl
         << "Ban co muon tiep tuc khong (Y/N): ";
}

void EmployeeManager::swap(Employee& emp1, Employee& emp2) {
    Employee temp = emp1;
    emp1 = emp2;
    emp2 = temp;
}

void EmployeeManager::sort(string option) {
    if (option == "ID") {
        for (int i = 0; i < this->numberOfEmployee - 1; i++)
            for (int j = 0; j < this->numberOfEmployee - i - 1; j++)
                if ((this->emp + j)->getID() > (this->emp + j + 1)->getID())
                    swap(*(this->emp + j), *(this->emp + j + 1));
    }

    if (option == "Name") {
        for (int i = 0; i < this->numberOfEmployee - 1; i++)
            for (int j = 0; j < this->numberOfEmployee - i - 1; j++)
                if ((this->emp + j)->getName() > (this->emp + j + 1)->getName())
                    swap(*(this->emp + j), *(this->emp + j + 1));
    }

    if (option == "Last Name") {
        for (int i = 0; i < this->numberOfEmployee - 1; i++)
            for (int j = 0; j < this->numberOfEmployee - i - 1; j++) {
                string str = this->getLastName(j);
                string str1 = this->getLastName(j + 1);
                if (str > str1)
                    swap(*(this->emp + j), *(this->emp + j + 1));
            }
    }

    if (option == "Age") {
        for (int i = 0; i < this->numberOfEmployee - 1; i++)
            for (int j = 0; j < this->numberOfEmployee - i - 1; j++)
                if ((this->emp + j)->getDateOfBirth() > (this->emp + j + 1)->getDateOfBirth())
                    swap(*(this->emp + j), *(this->emp + j + 1));
    }

    if (option == "Email") {
        for (int i = 0; i < this->numberOfEmployee - 1; i++)
            for (int j = 0; j < this->numberOfEmployee - i - 1; j++)
                if ((this->emp + j)->getEmail() > (this->emp + j + 1)->getEmail())
                    swap(*(this->emp + j), *(this->emp + j + 1));
    }

    if (option == "Salary") {
        for (int i = 0; i < this->numberOfEmployee - 1; i++)
            for (int j = 0; j < this->numberOfEmployee - i - 1; j++)
                if ((this->emp + j)->getSalary() > (this->emp + j + 1)->getSalary())
                    swap(*(this->emp + j), *(this->emp + j + 1));
    }
}

Employee& EmployeeManager::operator[](int index) {
    return *(this->emp + index);
}

const EmployeeManager& EmployeeManager::operator=(const EmployeeManager& empManager) {
    for (int i = 0; i < empManager.numberOfEmployee; i++) {
        this->push(*(empManager.emp + i));
    }
    return *this;
}

ostream& operator<<(ostream& out, const EmployeeManager& e) {
    for (int i = 0; i < e.numberOfEmployee; i++) {
        out << *(e.emp + i);
        out << "-------------------------------" << endl;
    }
    return out;
}

istream& operator>>(istream& in, EmployeeManager& empManager) {
    Employee emp;
    string str;
    cout << "Ma nhan vien: ";
    getline(in, str);
    if (str != "")
        emp.setID(str);
    cout << "Ten nhan vien: ";
    getline(in, str);
    if (str != "")
        emp.setName(str);
    cout << "Ngay sinh (dd/mm/yyyy): ";
    Date date;
    getline(in, str);
    if (str != "") {
        date = stringToDate(str);
        emp.setDateOfBirth(date);
    }
    cout << "Gioi tinh: ";
    getline(in, str);
    if (str != "" && str == "nam")
        emp.setGender("Nam");
    if (str != "" && str == "nu")
        emp.setGender("Nu");
    if ((str != "" && str == "Nam") || (str != "" && str == "Nu"))
        emp.setGender(str);
    cout << "So dien thoai: ";
    getline(in, str);
    if (str != "")
        emp.setPhoneNumber(str);
    cout << "Email: ";
    getline(in, str);
    if (str != "")
        emp.setEmail(str);
    cout << "Dia chi: ";
    getline(in, str);
    if (str != "")
        emp.setAddress(str);
    Contract contract;
    cout << "Ngay bat dau lam viec (dd/mm/yyyy): ";
    getline(in, str);
    if (str != "") {
        date = stringToDate(str);
        contract.Contract_setDateIn(date);
    }
    cout << "Ngay het hop dong lam viec (dd/mm/yyyy): ";
    getline(in, str);
    if (str != "") {
        date = stringToDate(str);
        contract.Contract_setDateOut(date);
    }
    cout << "La nhan vien toan thoi gian (y/n): ";
    in >> str;
    if (str != "") {
        if (str == "y")
            contract.Contract_setIsFullTime(true);
        if (str == "n")
            contract.Contract_setIsFullTime(false);
    }
    emp.setContract(contract);
    cout << "Tien luong: ";
    long salary;
    in >> salary;
    if (str != "")
        emp.setSalary(salary);
    empManager.push(emp);
    return in;
}

const EmployeeManager& EmployeeManager::findAllEmployee(string str, string option) {
    EmployeeManager *empManager = new EmployeeManager();
    int i = 0;
    int index = 0;
    index = this->indexOf(str, option, i);
    while (index != -1) {
        empManager->push((*this)[index]);
        i = index + 1;
        index = this->indexOf(str, option, i);
    }
    return *empManager;
}

string EmployeeManager::getLastName(int index) {
    string str = (this->emp + index)->getName();
    int i = str.length();
    while (str[i] != ' ') {
        i--;
    }
    str = str.substr(i + 1, str.length() - i);
    return str;
}

int EmployeeManager::indexOfLastName(string str, int startIndex) {
    for (int i = startIndex; i < this->numberOfEmployee; i++)
        if (this->getLastName(i) == str)
            return i;
    return -1;
}

const EmployeeManager& EmployeeManager::findAllLastName(string str) {
    EmployeeManager *empManager = new EmployeeManager();
    int i = 0;
    int index = 0;
    index = this->indexOfLastName(str, i);
    while (index != -1) {
        empManager->push((*this)[index]);
        i = index + 1;
        index = this->indexOfLastName(str, i);
    }
    return *empManager;
}
