#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class note
{
private:
    string firstName;
    string lastName;
    string phoneNumber;
    int birthDate[3];

public:
    // Конструкторы
    note();
    note(const string& first, const string& last, const string& phone, const int* birth);
    note(const note& other); // Конструктор копирования

    // Деструктор
    ~note();

    // Методы доступа (getters и setters)
    const string& getFirstName() const;
    const string& getLastName() const;
    const string& getPhoneNumber() const;
    const int* getBirthDate() const;
    void noteShow();
    void setFirstName(const string& first);
    void setLastName(const string& last);
    void setPhoneNumber(const string& phone);
    void setBirthDate(const int* birth);

    // Перегруженные операции вставки и извлечения
    friend ostream& operator<<(ostream& os, const note& note);
    friend istream& operator>>(istream& is, note& note);
};


