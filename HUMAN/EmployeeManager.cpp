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
            if ((this->emp + i)->getID() == emp->getID())
                return i;
    }

    if (option == "Name") {
        for (int i = startIndex; i < this->numberOfEmployee; i++)
            if ((this->emp + i)->getName() == emp->getName())
                return i;
    }

    if (option == "Gender") {
        for (int i = startIndex; i < this->numberOfEmployee; i++)
            if ((this->emp + i)->getGender() == emp->getGender())
                return i;
    }

    if (option == "Phone") {
        for (int i = startIndex; i < this->numberOfEmployee; i++)
            if ((this->emp + i)->getPhoneNumber() == emp->getPhoneNumber())
                return i;
    }

    if (option == "Email") {
        for (int i = startIndex; i < this->numberOfEmployee; i++)
            if ((this->emp + i)->getEmail() == emp->getEmail())
                return i;
    }
    
    if (option == "Address") {
        for (int i = startIndex; i < this->numberOfEmployee; i++)
            if ((this->emp + i)->getAddress() == emp->getAddress())
                return i;
    }
    
    if (option == "Contract") {
        for (int i = startIndex; i < this->numberOfEmployee; i++)
            if ((this->emp + i)->getContract() == emp->getContract())
                return i;
    }

    return -1;
}

int EmployeeManager::indexOf(const Employee& emp) {
    return indexOf(emp.getID(), "ID", 0);
}

void EmployeeManager::update(Employee currentEmp, Employee newEmp) {
    int index = indexOf(currentEmp);

    if (index < 0)
        return;
    *(this->emp + index) = newEmp;
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
                if ((this->emp + j)->getAge() > (this->emp + j + 1)->getAge())
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

ostream& operator<<(ostream& out, const EmployeeManager& e) {
    for (int i = 0; i < e.numberOfEmployee; i++) {
        out << *(e.emp + i);
        out << "-------------------------------" << endl;
    }
    return out;
}