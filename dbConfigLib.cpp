#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include "struct.h"
#include "lab6.h"
using namespace std;


prepod* create_db_line() {
    prepod* newPrepod = new prepod;

    newPrepod->surname = new char[256];
    newPrepod->name = new char[256];
    newPrepod->department = new char[256];
    newPrepod->subject = new char[256];

    return newPrepod;
}

prepod** create_db(int n) {
    prepod** db = new prepod * [n];
    for (int i = 0; i < n; i++) {
        db[i] = create_db_line();
    }
    return db;
}

prepod** load_data_from_db(FILE* file, int &counts) {

    fscanf(file, "%d", &counts);

    prepod** db = create_db(counts);
    cout << "������� ������� ���� ������" << endl;
    for (int i = 0; i < counts; i++) {
        prepod* db_line = db[i];
        fscanf(file, "%s %s %s %s", db[i]->surname, db[i]->name, db[i]->department, db[i]->subject);
    }
    cout << "�������� ������ � ���� ������ ���� �������" << endl;
    cout << endl;
    printAllPrepods(db, counts);

    return db;
}

void clear_db(prepod** db, int counts) {

    for (int i = 0; i < counts; i++) {
        delete[] db[i]->surname;
        delete[] db[i]->name;
        delete[] db[i]->department;
        delete[] db[i]->subject;
        delete db[i];
    }
    delete[] db;
}

void user_interface(bool condition, prepod** db, int counts) {
    
    system("pause");
    cout << "��� ����������� ������ ��������� ������� �� ����� �������...";
    cin.get();

    int command;

    char* surname = new char[256];
    char* name = new char[256];
    char* department = new char[256];

    int n = counts;
    prepod** arr = db;

    while (condition) {
        system("cls");
        cout << "������� �������:" << endl;
        cout << "�������� ������ ������������"
            << "  1" << endl;
        cout << "�������� ���� ������ ��"
            << "  2" << endl;
        cout << "����� ���� �������������� �������� �������"
            << "  3" << endl;
        cout << "����� ��� ��������, ������� ���� �������� �������������"
            << "   4" << endl;
        cout << "����� �� ���������"
            << "   5" << endl;
        cin >> command;
        switch (command) {
        case 4: {
            cout << endl;
            cout << "������� ������� � ��� �������������: ";
            cin >> surname >> name;
            findPrepodsBySubject(arr, n, surname, name);
            system("pause");
            cout << "��� ����������� ������ ��������� ������� �� ����� �������...";
            cin.get();
            break;
        }
        case 2: {
            cout << endl;
            printAllPrepods(arr, n);
            system("pause");
            cout << "��� ����������� ������ ��������� ������� �� ����� �������...";
            cin.get();
            break;
        }
        case 3: {
            cout << endl;
            cout << "������� �������: ";
            cin >> department;
            findPrepodsByDepartment(arr, n, department);
            system("pause");
            cout << "��� ����������� ������ ��������� ������� �� ����� �������...";
            cin.get();
            break;
        }
        case 1: {
            cout << endl;
            arr = addPrepod(arr, n);
            printAllPrepods(arr, n);
            system("pause");
            cout << "��� ����������� ������ ��������� ������� �� ����� �������...";
            cin.get();
            break;
        }
        case 5:
            condition = false;
        }
    }

    delete[] surname;
    delete[] name;
    delete[] department;
}