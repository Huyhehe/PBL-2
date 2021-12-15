#include "EmployeeManager.h"

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
    cout << emp;
    cout << "Ban muon sua doi nhan vien co stt (chon 0 de cap nhat tat ca): ";
    int index;
    cin >> index;
    while (index < 0 || index > emp.getNumberOfEmployee()) {
        cout << "Lua chon khong phu hop, vui long chon lai: ";
        cin >> index;
    }
    system("cls");
    cout << "Ban muon chinh sua: " << endl;
    cout << "1. Chinh sua ID. " << endl;
    cout << "2. Chinh sua Ten." << endl;
    cout << "3. Chinh sua ngay sinh." << endl;
    cout << "4. Chinh sua gioi tinh." << endl;
    cout << "5. Chinh sua so dien thoai." << endl;
    cout << "6. Chinh sua email." << endl;
    cout << "7. Chinh sua dia chi." << endl;
    cout << "8. Chinh sua ngay bat dau lam viec." << endl;
    cout << "9. Chinh sua ngay ket thuc hop dong lam viec." << endl;
    cout << "10. Chinh sua hinh thuc nhan vien((y): full time/(n): part time)." << endl;
    cout << "11. Chinh sua luong." << endl;
    cout << "Hay nhap lua chon cua ban: ";
    int j = 0;
    cin >> j;
    while (j < 1 || j > 11) {
        cout << "Lua chon khong hop le, vui long nhap lai lua chon cua ban: ";
        cin >> j;
    }
    string s;
    int i = index - 1;
    bool deleteAll = false;
    if (index == 0) {
        deleteAll = true;
        i = 0;
    }
    getline(cin, s);
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
        if (deleteAll)
            i++;
        else
            break;
    }
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
    cout << "ok";
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
    cout << emp;
    cout << "Ban muon xoa nhan vien co so thu tu(chon 0 de xoa tat ca): ";
    int i;
    cin >> i;
    while (i < 0 || i > emp.getNumberOfEmployee()) {
        cout << "Lua chon sai, vui long nhap lai: ";
        cin >> i;
    }
    if (i == 0) {
        for (int j = 0; j < emp.getNumberOfEmployee(); j++)
            this->remove(emp[j]);
        return;
    }
    int index = this->indexOf(emp[i - 1]);
    if (index == -1)
        return;
    remove(index);
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
    getline(in, str);
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
