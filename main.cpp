#include "lab6.h"
#include "struct.h"
#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int n;

    cout << "Введите количество преподавателей: ";
    cin >> n;

    prepod** arr = new prepod * [n];
    for (int i = 0; i < n; i++) {
        cout << "Преподаватель " << i + 1 << ":" << endl;
        arr[i] = createPrepod();
    }

    printAllPrepods(arr, n);
    int command;
    bool condition = true;
    char* surname = new char[256];
    char* name = new char[256];
    char* department = new char[256];

    while (condition) {
        system("cls");
        cout << "Введите команду:" << endl;
        cout << "Добавить нового пользователя"
            << "  1" << endl;
        cout << "Показать весь список БД"
            << "  2" << endl;
        cout << "Найти всех преподавателей заданной кафедры"
            << "  3" << endl;
        cout << "Найти все предметы, который ведёт заданный преподаватель"
            << "   4" << endl;
        cout << "Выйти из программы"
            << "   5" << endl;
        cin >> command;
        switch (command) {
        case 4: {
            cout << endl;
            cout << "Введите фамилию и имя преподавателя: ";
            cin >> surname >> name;
            findPrepodsBySubject(arr, n, surname, name);
            system("pause");
            cout << "Для продолжения работы программы нажмите на любую клавишу...";
            cin.get(); 
            break;
        }
        case 2: {
            cout << endl;
            printAllPrepods(arr, n);
            system("pause");
            cout << "Для продолжения работы программы нажмите на любую клавишу...";
            cin.get(); 
            break;
        }
        case 3: {
            cout << endl;
            cout << "Введите кафедру: ";
            cin >> department;
            findPrepodsByDepartment(arr, n, department);
            system("pause");
            cout << "Для продолжения работы программы нажмите на любую клавишу...";
            cin.get(); 
            break;
        }
        case 1: {
            cout << endl;
            arr = addPrepod(arr, n);
            printAllPrepods(arr, n);
            system("pause");
            cout << "Для продолжения работы программы нажмите на любую клавишу...";
            cin.get(); 
            break;
        }
        case 5:
            condition = false;
        }
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i]->surname;
        delete[] arr[i]->name;
        delete[] arr[i]->department;
        delete[] arr[i]->subject;
        delete arr[i];
    }

    delete[] arr;
    delete[] surname;
    delete[] name;
    delete[] department;

    return 0;
}