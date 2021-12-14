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

