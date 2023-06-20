#include <algorithm>
#include <iostream>
#include <string.h>

#include "struct.h"

using namespace std;

prepod* createPrepod() {
    prepod* newPrepod = new prepod;

    newPrepod->fio_prepod.surname = new char[256];
    newPrepod->fio_prepod.name = new char[256];
    newPrepod->fio_prepod.secondname = new char[256];
    newPrepod->department = new char[256];
    newPrepod->subject = new char[256];
    newPrepod->date_ITB.month = new char[256];


    cout << "Введите фамилию преподавателя: ";
    cin >> newPrepod->fio_prepod.surname;
    cout << "Введите имя преподавателя: ";
    cin >> newPrepod->fio_prepod.name;
    cout << "Введите отчество преподавателя: ";
    cin >> newPrepod->fio_prepod.secondname;
    cout << "Введите кафедру: ";
    cin >> newPrepod->department;
    cout << "Введите предмет: ";
    cin >> newPrepod->subject;
    cout << "Введите дату техники безопасности (на английском и раздельно. Пример: 17 January 2023): ";
    cin >> newPrepod->date_ITB.day;
    cin >> newPrepod->date_ITB.month;
    cin >> newPrepod->date_ITB.year;

    return newPrepod;
}

void printPrepod(prepod* p) {
    cout << p->fio_prepod.surname << "\t" << p->fio_prepod.name << "\t" << p->fio_prepod.secondname << "\t"
        << p->department << "\t" << p->subject << "\t"
        << p->date_ITB.day << "\t" << p->date_ITB.month << "\t" << p->date_ITB.year << "\t" << endl;
}

void printAllPrepods(prepod** arr, int n) {
    cout << "Фамилия\tИмя\tОтчество\tКафедра\tПредмет\tИТБ" << endl;
    for (int i = 0; i < n; i++) {
        printPrepod(arr[i]);
    }
}

prepod** addPrepod(prepod** arr, int& n) {
    prepod* newPrepod = createPrepod();

    prepod** newArr = new prepod * [n + 1];
    for (int i = 0; i < n; i++) {
        newArr[i] = arr[i];
    }
    newArr[n] = newPrepod;

    delete[] arr;
    n++;
    return newArr;
}

void findPrepodsBySubject(prepod** arr, int n, char* surname, char* name, char* secondname) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i]->fio_prepod.surname, surname) == 0 &&
            strcmp(arr[i]->fio_prepod.name, name) == 0 &&
            strcmp(arr[i]->fio_prepod.secondname, secondname) == 0) {
            found = true;
            cout << arr[i]->subject << endl;
        }
    }
    if (!found) {
        cout << "Преподаватель не найден" << endl;
    }
}

bool comparePrepods(prepod* p1, prepod* p2) {
    return strcmp(p1->fio_prepod.surname, p2->fio_prepod.surname) < 0;
}

void findPrepodsByDepartment(prepod** arr, int n, char* department) {
    prepod** depArr = new prepod * [n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i]->department, department) == 0) {
            depArr[count] = arr[i];
            count++;
        }
    }

    sort(depArr, depArr + count, comparePrepods);

    cout << "Фамилия\tИмя\tОтчество\tКафедра\tПредмет\tИТБ" << endl;
    for (int i = 0; i < count; i++) {
        printPrepod(depArr[i]);
    }

    delete[] depArr;
}
