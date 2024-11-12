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
    cout << "������� ������� ��� ������ � ���������: ";
    cin >> name;
    auto it = find_if(notes.begin(), notes.end(),
        [name](const note* n) {
            return n->getLastName() == name;
        });
    if (it != notes.end()) {
        std::cout << "������ �������: \n" << **it << std::endl;
        std::cout << "��������, ��� �� ������ ��������:" << std::endl;
        std::cout << "1. ���" << std::endl;
        std::cout << "2. �������" << std::endl;
        std::cout << "3. ����� ��������" << std::endl;
        std::cout << "4. ���� ��������" << std::endl;

        int option;
        std::cout << "������� ����� ��������� �����: ";
        std::cin >> option;
        std::cin.ignore(32767, '\n');


        if (option == 1) {
            std::string newName;
            std::cout << "������� ����� ���: ";
            std::cin >> newName;
            (*it)->setFirstName(newName);
        }
        if (option == 2) {
            std::string newLastName;
            std::cout << "������� ����� �������: ";
            std::cin >> newLastName;
            (*it)->setLastName(newLastName);

        }
        if (option == 3) {
            std::string newPhoneNumber;
            std::cout << "������� ����� ����� ��������: ";
            std::cin >> newPhoneNumber;
            (*it)->setPhoneNumber(newPhoneNumber);

        }
        if (option == 4) {
            int newBirthDate[3];
            std::cout << "������� ����� ���� �������� (���� ����� ���): ";
            for (int i = 0; i < 3; ++i) {
                std::cin >> newBirthDate[i];
            }
            (*it)->setBirthDate(newBirthDate);

        }
        else {
            cout << "�������� �����" << endl;
        }
    }
}



std::string replace_digits(const std::string& word) {
    std::string result = "";
    for (char c : word) {
        if (isdigit(c)) {
            switch (c) {
            case '0': result += "����"; break;
            case '1': result += "����"; break;
            case '2': result += "���"; break;
            case '3': result += "���"; break;
            case '4': result += "������"; break;
            case '5': result += "����"; break;
            case '6': result += "�����"; break;
            case '7': result += "����"; break;
            case '8': result += "������"; break;
            case '9': result += "������"; break;
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
            cerr << "�� ������� ������� ����" << endl;
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
                    // ��������� ������� ������ ����� �����
                    output.push_back(" \n");
                }
            }
        }

        cout << "��������������� �����:" << endl;
        int j = output.size();
        for (int i = 0; i < j; i++) {
            cout << output[i];
        }
        
        cout << endl;

        // ����� ��������� �����
        cout << "�������� �����:" << endl;
        input.clear();
        input.seekg(0, ios::beg);
        cout << input.rdbuf() << endl;
    }
    catch (const exception& e) {
        cerr << "������: " << e.what() << endl;
    }
}



void find_delete(vector <note*> notes) {
    string searchLastName;
    std::cout << "������� ������� ��� ������: ";
    std::cin >> searchLastName;
    auto it = std::find_if(notes.begin(), notes.end(),
        [searchLastName](const note* n) {
            return n->getLastName() == searchLastName;
        });
    if (it != notes.end()) {
        std::cout << "������ �������: \n" << **it << std::endl;
        delete* it;  // ����������� ������
        notes.erase(it);  // ������� ��������� �� �������
        std::cout << "������ �������." << std::endl;
    }
    else {
        std::cout << "������ �� �������." << std::endl;
    }
}
void find_lastname(vector <note*> notes) {
    string searchLastName;
    std::cout << "������� ������� ��� ������: ";
    std::cin >> searchLastName;
    auto it = std::find_if(notes.begin(), notes.end(),
        [searchLastName](const note* n) {
            return n->getLastName() == searchLastName;
        });
    if (it != notes.end()) {
        std::cout << "������ �������: \n" << **it << std::endl;
    }
    else {
        std::cout << "������ �� �������." << std::endl;
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
    cout << "��������������� ������ �� ������ 3 ������ ��������:\n";
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
        // ������� ����� ����

        std::cout << "===== ���� =====" << std::endl;
        std::cout << "1. ������� ������" << std::endl;
        std::cout << "2. �������� ������" << std::endl;
        std::cout << "3. ������� ������" << std::endl;
        std::cout << "4. ������� �� ����� ������" << std::endl;
        std::cout << "5. ����� �� �������" << std::endl;
        std::cout << "6. �������� ����� � ����� �� �����" << std::endl;
        
        std::cout << "0. ����� �� ���������" << std::endl;

        // ����������� ����� ������������

        std::cout << "������� ����� ��������� �����: ";

        std::cin >> choice;
        std::cin.ignore(32767, '\n');

        // ������������ ����� ������������
        switch (choice) {

        case '1': {
            note newnote;
            string first, last, phone;
            int birth[3];
            cout << "������� ���: ";
            getline(cin, first);
            newnote.setFirstName(first);
            cout << "������� �������: ";
            getline(cin, last);
            newnote.setLastName(last);
            cout << "������� ����� ��������: ";
            getline(cin, phone);
            newnote.setPhoneNumber(phone);
            cout << "������� ���� ��������: ";
            cin >> birth[0];
            cout << "������� ����� ��������: ";
            cin >> birth[1];
            cout << "������� ��� ��������: ";
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

            cout << "������� ��� �����: ";
            string loadFileName;
            getline(cin, loadFileName);

            digits_to_replace(loadFileName);

            break;
        }
        
       
        case '0':
            std::cout << "��������� ���������." << std::endl;
            for (auto& notePtr : notes) {
                delete notePtr;
            }
            notes.clear();
            return 0;
        default:
            std::cout << "�������� �����." << std::endl;
            break;
        }
    }
}
