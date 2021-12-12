#include "Employee.h"

Employee::Employee() {

}

Employee::Employee(string ID, string name, Date date, string gender, string phoneNumber, string email, string address, Contract contract, long salary)
    : Human(ID, name, date, phoneNumber, email, address, gender){
    this->salary = salary;
    this->contract = contract;
}

Employee::~Employee(){

}

void Employee::setSalary(long salary) {
    this->salary = salary;
}

long Employee::getSalary() const {
    return salary;
}

void Employee::setContract(const Contract& cont) {
    this->contract = cont;
}

Contract Employee::getContract() const {
    return this->contract;
}

const Employee& Employee::operator=(const Employee& emp) {
    this->setID(emp.getID());
    this->setName(emp.getName());
    this->setDateOfBirth(emp.getDateOfBirth());
    this->setGender(emp.getGender());
    this->setPhoneNumber(emp.getPhoneNumber());
    this->setEmail(emp.getEmail());
    this->setAddress(emp.getAddress());
    this->contract = emp.contract;
    this->salary = emp.salary;
    return *this;
}

ostream& operator<<(ostream& out, const Employee& emp) {
    out << "Ma nhan vien: " << emp.getID() << endl;
    out << "Ten nhan vien: " << emp.getName() << endl;
    out << "Ngay Sinh: " << emp.getDateOfBirth() << endl;
    out << "Gioi tinh: " << emp.getGender() << endl;
    out << "So dien thoai: " << emp.getPhoneNumber() << endl;
    out << "Email: " << emp.getEmail() << endl;
    out << "Dia chi: " << emp.getAddress() << endl;
    out << "Ngay bat dau lam viec: " << emp.getContract().Contract_getDateIn() << endl;
    out << "Ngay ket thuc hop dong: " << emp.getContract().Contract_getDateOut() << endl;
    if (emp.getContract().Contract_getIsFullTime())
        out << "La nhan vien toan thoi gian: true" << endl;
    else
        out << "La nhan vien ban thoi gian: false" << endl;
    out << "Tien luong: " << emp.getSalary() <<endl;
    return out;
}
