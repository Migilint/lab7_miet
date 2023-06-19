#include <algorithm>
#include <iostream>
#include <string.h>

#include "struct.h"

using namespace std;

prepod* createPrepod() {
    prepod* newPrepod = new prepod;

    newPrepod->surname = new char[256];
    newPrepod->name = new char[256];
    newPrepod->department = new char[256];
    newPrepod->subject = new char[256];

    cout << "Введите фамилию преподавателя: ";
    cin >> newPrepod->surname;
    cout << "Введите имя преподавателя: ";
    cin >> newPrepod->name;
    cout << "Введите кафедру: ";
    cin >> newPrepod->department;
    cout << "Введите предмет: ";
    cin >> newPrepod->subject;

    return newPrepod;
}

void printPrepod(prepod* p) {
    cout << p->surname << "\t" << p->name << "\t" << p->department << "\t"
        << p->subject << endl;
}

void printAllPrepods(prepod** arr, int n) {
    cout << "Фамилия\tИмя\tКафедра\tПредмет" << endl;
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

void findPrepodsBySubject(prepod** arr, int n, char* surname, char* name) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i]->surname, surname) == 0 &&
            strcmp(arr[i]->name, name) == 0) {
            found = true;
            cout << arr[i]->subject << endl;
        }
    }
    if (!found) {
        cout << "Преподаватель не найден" << endl;
    }
}

bool comparePrepods(prepod* p1, prepod* p2) {
    return strcmp(p1->surname, p2->surname) < 0;
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

    cout << "Фамилия\tИмя\tКафедра\tПредмет" << endl;
    for (int i = 0; i < count; i++) {
        printPrepod(depArr[i]);
    }

    delete[] depArr;
}
