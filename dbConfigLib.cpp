#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include "struct.h"
#include "lab6.h"
#include "dateLib.h"
using namespace std;


prepod* create_db_line() {
    prepod* newPrepod = new prepod;

    newPrepod->fio_prepod.surname = new char[256];
    newPrepod->fio_prepod.name = new char[256];
    newPrepod->fio_prepod.secondname = new char[256];
    newPrepod->department = new char[256];
    newPrepod->subject = new char[256];
    newPrepod->date_ITB.month = new char[256];

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
    cout << "Создана успешно база данных" << endl;
    for (int i = 0; i < counts; i++) {
        prepod* db_line = db[i];
        fscanf(file, "%s %s %s %s %s %d %s %d", db[i]->fio_prepod.surname, db[i]->fio_prepod.name, db[i]->fio_prepod.secondname,
            db[i]->department, db[i]->subject,
            &(db[i]->date_ITB.day), db[i]->date_ITB.month, &(db[i]->date_ITB.year));
    }
    cout << "Загрузка данных в базу данных была успешна" << endl;
    cout << endl;
    printAllPrepods(db, counts);

    return db;
}

void clear_db(prepod** db, int counts) {

    for (int i = 0; i < counts; i++) {
        delete[] db[i]->fio_prepod.surname;
        delete[] db[i]->fio_prepod.name;
        delete[] db[i]->fio_prepod.secondname;
        delete[] db[i]->department;
        delete[] db[i]->subject;
        delete[] db[i]->date_ITB.month;
        delete db[i];
    }
    delete[] db;
}

void user_interface(bool condition, prepod** db, int db_counts) {
    
    system("pause");
    //cout << "Для продолжения работы программы нажмите на любую клавишу...";
    //cin.get();

    int command;

    char* surname = new char[256];
    char* name = new char[256];
    char* secondname = new char[256];
    char* department = new char[256];

    int n = db_counts;
    prepod** arr = db;

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
            << "  4" << endl;
        cout << "Найти всех преподавателей, у которых прошло более 15 месяцев с последнеего ИТБ на текущую дату"
            << "   5" << endl;
        cout << "Выйти из программы"
            << "   6" << endl;
        cin >> command;
        system("pause");
        switch (command) {
        case 5: {
            cout << endl;
            findPrepodsByDateITB(arr, n);
            system("pause");
            break;
        }
        case 4: {
            cout << endl;
            cout << "Введите фамилию, имя и отчество преподавателя: ";
            cin >> surname >> name >> secondname;
            findPrepodsBySubject(arr, n, surname, name, secondname);
            system("pause");
            //cout << "Для продолжения работы программы нажмите на любую клавишу...";
            //cin.get();
            break;
        }
        case 2: {
            cout << endl;
            printAllPrepods(arr, n);
            system("pause");
            //cout << "Для продолжения работы программы нажмите на любую клавишу...";
            //cin.get();
            break;
        }
        case 3: {
            cout << endl;
            cout << "Введите кафедру: ";
            cin >> department;
            findPrepodsByDepartment(arr, n, department);
            system("pause");
            //cout << "Для продолжения работы программы нажмите на любую клавишу...";
            //cin.get();
            break;
        }
        case 1: {
            cout << endl;
            arr = addPrepod(arr, n);
            printAllPrepods(arr, n);
            system("pause");
            //cout << "Для продолжения работы программы нажмите на любую клавишу...";
            //cin.get();
            break;
        }
        case 6:
            condition = false;
        }
    }

    delete[] surname;
    delete[] name;
    delete[] secondname;
    delete[] department;
}