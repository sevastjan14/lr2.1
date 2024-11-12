#include "note.h"

#include <Windows.h>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;
void find_change(vector <note*> notes) {
    string name;
    cout << "Введите фамилию для поиска и изменения: ";
    cin >> name;
    auto it = find_if(notes.begin(), notes.end(),
        [name](const note* n) {
            return n->getLastName() == name;
        });
    if (it != notes.end()) {
        std::cout << "Запись найдена: \n" << **it << std::endl;
        std::cout << "Выберите, что вы хотите изменить:" << std::endl;
        std::cout << "1. Имя" << std::endl;
        std::cout << "2. Фамилия" << std::endl;
        std::cout << "3. Номер телефона" << std::endl;
        std::cout << "4. Дата рождения" << std::endl;

        int option;
        std::cout << "Введите номер выбранной опции: ";
        std::cin >> option;
        std::cin.ignore(32767, '\n');


        if (option == 1) {
            std::string newName;
            std::cout << "Введите новое имя: ";
            std::cin >> newName;
            (*it)->setFirstName(newName);
        }
        if (option == 2) {
            std::string newLastName;
            std::cout << "Введите новую фамилию: ";
            std::cin >> newLastName;
            (*it)->setLastName(newLastName);

        }
        if (option == 3) {
            std::string newPhoneNumber;
            std::cout << "Введите новый номер телефона: ";
            std::cin >> newPhoneNumber;
            (*it)->setPhoneNumber(newPhoneNumber);

        }
        if (option == 4) {
            int newBirthDate[3];
            std::cout << "Введите новую дату рождения (день месяц год): ";
            for (int i = 0; i < 3; ++i) {
                std::cin >> newBirthDate[i];
            }
            (*it)->setBirthDate(newBirthDate);

        }
        else {
            cout << "Неверный выбор" << endl;
        }
    }
}



std::string replace_digits(const std::string& word) {
    std::string result = "";
    for (char c : word) {
        if (isdigit(c)) {
            switch (c) {
            case '0': result += "ноль"; break;
            case '1': result += "один"; break;
            case '2': result += "два"; break;
            case '3': result += "три"; break;
            case '4': result += "четыре"; break;
            case '5': result += "пять"; break;
            case '6': result += "шесть"; break;
            case '7': result += "семь"; break;
            case '8': result += "восемь"; break;
            case '9': result += "девять"; break;
            default: break;
            }
        }
        else {
            result += c;
        }
    }
    return result;
}

void digits_to_replace(const std::string& file) {
    try {
        std::ifstream input(file);
        if (!input.is_open()) {
            cerr << "Не удалось открыть файл" << endl;
            return;
        }

        std::vector<std::string> output;
        std::string line;

        while (getline(input, line)) {
            stringstream ss(line);
            string word;

            while (ss >> word) {
                output.push_back(replace_digits(word));
                if ((word.find('.') != std::string::npos) || word.find('?') != std::string::npos || word.find('!') != std::string::npos) {
                    // Добавляем перенос строки после точки
                    output.push_back(" \n");
                }
            }
        }

        cout << "Преобразованный текст:" << endl;
        int j = output.size();
        for (int i = 0; i < j; i++) {
            cout << output[i];
        }
        
        cout << endl;

        // Вывод исходного файла
        cout << "Исходный текст:" << endl;
        input.clear();
        input.seekg(0, ios::beg);
        cout << input.rdbuf() << endl;
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
}



void find_delete(vector <note*> notes) {
    string searchLastName;
    std::cout << "Введите фамилию для поиска: ";
    std::cin >> searchLastName;
    auto it = std::find_if(notes.begin(), notes.end(),
        [searchLastName](const note* n) {
            return n->getLastName() == searchLastName;
        });
    if (it != notes.end()) {
        std::cout << "Запись найдена: \n" << **it << std::endl;
        delete* it;  // Освобождаем память
        notes.erase(it);  // Удаляем указатель из вектора
        std::cout << "Запись удалена." << std::endl;
    }
    else {
        std::cout << "Запись не найдена." << std::endl;
    }
}
void find_lastname(vector <note*> notes) {
    string searchLastName;
    std::cout << "Введите фамилию для поиска: ";
    std::cin >> searchLastName;
    auto it = std::find_if(notes.begin(), notes.end(),
        [searchLastName](const note* n) {
            return n->getLastName() == searchLastName;
        });
    if (it != notes.end()) {
        std::cout << "Запись найдена: \n" << **it << std::endl;
    }
    else {
        std::cout << "Запись не найдена." << std::endl;
    }
}
bool compareByPhoneNumber(const note* a, const note* b) {
    return a->getPhoneNumber().substr(0, 5) < b->getPhoneNumber().substr(0, 5);
}
void sortByPhoneNumber(vector<note*>& notes) {
    std::sort(notes.begin(), notes.end(), compareByPhoneNumber);
}
void output_vector(vector <note*> notes) {
    sortByPhoneNumber(notes);
    cout << "Отсортированные записи по первым 3 цифрам телефона:\n";
    for (const auto& n : notes) {
        n->noteShow();
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<note*> notes;
    char choice;
    string searchLastName;
    while (true) {
        // Выводим опции меню

        std::cout << "===== Меню =====" << std::endl;
        std::cout << "1. Создать запись" << std::endl;
        std::cout << "2. Изменить запись" << std::endl;
        std::cout << "3. Удалить запись" << std::endl;
        std::cout << "4. Вывести на экран записи" << std::endl;
        std::cout << "5. Поиск по фамилии" << std::endl;
        std::cout << "6. Заменить цифры в файле на слова" << std::endl;
        
        std::cout << "0. Выйти из программы" << std::endl;

        // Запрашиваем выбор пользователя

        std::cout << "Введите номер выбранной опции: ";

        std::cin >> choice;
        std::cin.ignore(32767, '\n');

        // Обрабатываем выбор пользователя
        switch (choice) {

        case '1': {
            note newnote;
            string first, last, phone;
            int birth[3];
            cout << "Введите имя: ";
            getline(cin, first);
            newnote.setFirstName(first);
            cout << "Введите фамилию: ";
            getline(cin, last);
            newnote.setLastName(last);
            cout << "Введите номер телефона: ";
            getline(cin, phone);
            newnote.setPhoneNumber(phone);
            cout << "Введите день рождения: ";
            cin >> birth[0];
            cout << "Введите месяц рождения: ";
            cin >> birth[1];
            cout << "Введите год рождения: ";
            cin >> birth[2];
            newnote.setBirthDate(birth);
            notes.push_back(new note(newnote));
            break;
        }
        case '2':
            find_change(notes);
            
            break;
        case '3': {
            find_delete(notes);
            
            break;
        }
        case '4': {
            output_vector(notes);
            break;
        }
        case '5':

            find_lastname(notes);
            
            break;
        case '6': {
            setlocale(LC_ALL, "Russian");
            SetConsoleCP(1251);
            SetConsoleOutputCP(1251);

            cout << "Введите имя файла: ";
            string loadFileName;
            getline(cin, loadFileName);

            digits_to_replace(loadFileName);

            break;
        }
        
       
        case '0':
            std::cout << "Программа завершена." << std::endl;
            for (auto& notePtr : notes) {
                delete notePtr;
            }
            notes.clear();
            return 0;
        default:
            std::cout << "Неверный выбор." << std::endl;
            break;
        }
    }
}
