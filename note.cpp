#include "note.h"


note::note() {
    // ���������� ������������ ��� ����������
    firstName = "Ivan";
    lastName = "Ivanov";
    phoneNumber = "+7 999 999 99 99";
    birthDate[0] = 06;
    birthDate[1] = 07;
    birthDate[2] = 2003;
    cout << "������ ����������� �� ���������" << endl;
}

note::note(const string& first, const string& last, const string& phone, const int* birth) {
    // ���������� ������������ � �����������
    firstName = first;
    lastName = last;
    phoneNumber = phone;
    for (int i = 0; i < 3; i++) {
        birthDate[i] = birth[i];
    }
    cout << "������ ����������� � �����������" << endl;
}

note::note(const note& other) {
    // ���������� ������������ �����������
    firstName = other.firstName;
    lastName = other.lastName;
    phoneNumber = other.phoneNumber;
    for (int i = 0; i < 3; i++) {
        birthDate[i] = other.birthDate[i];
    }
    cout << "������ ����������� �����������" << endl;
}

note::~note() {
    // ���������� �����������
    cout << "������ ����������" << endl;
}

const string& note::getFirstName() const {
    return firstName;
}

const string& note::getLastName() const {

    return lastName;
}

const string& note::getPhoneNumber() const {

    return phoneNumber;
}

const int* note::getBirthDate() const {

    return birthDate;
}
void note::noteShow() {
    cout << "---------------------" << endl;
    cout << "���: " << firstName << endl;
    cout << "�������: " << lastName << endl;
    cout << "�������: " << phoneNumber << endl;
    cout << "���� ��������: " << birthDate[0] << '.' << birthDate[1] << '.' << birthDate[2] << endl;
    cout << "---------------------" << endl;
}
void note::setFirstName(const string& first) {

    firstName = first;
}

void note::setLastName(const string& last) {

    lastName = last;
}

void note::setPhoneNumber(const string& phone) {
    phoneNumber = phone;
}

void note::setBirthDate(const int* birth) {
    for (int i = 0; i < 3; i++) {
        birthDate[i] = birth[i];
    }
}

ostream& operator<<(ostream& os, const note& note) {
    os << "First Name: " << note.getFirstName() << "\n";
    os << "Last Name: " << note.getLastName() << "\n";
    os << "Phone Number: " << note.getPhoneNumber() << "\n";
    os << "Birth Date: " << note.getBirthDate()[0] << "." << note.getBirthDate()[1] << "." << note.getBirthDate()[2] << "\n";
    return os;
}

istream& operator>>(istream& is, note& note) {
    cout << "Enter First Name: ";
    is >> note.firstName;

    cout << "Enter Last Name: ";
    is >> note.lastName;

    cout << "Enter Phone Number: ";
    is >> note.phoneNumber;

    cout << "Enter Birth Date (day month year, separated by spaces): ";
    for (int i = 0; i < 3; ++i) {
        is >> note.birthDate[i];
    }
    return is;
}
