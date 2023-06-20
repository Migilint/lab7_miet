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

prepod** load_data_from_db(FILE* file) {
    int counts;
    fscanf(file, "%d", &counts);

    prepod** db = create_db(counts);
    cout << "Создана успешно база данных" << endl;
    for (int i = 0; i < counts; i++) {
        prepod* db_line = db[i];
        fscanf(file, "%s %s %s %s", db[i]->surname, db[i]->name, db[i]->department, db[i]->subject);
    }
    cout << "Загрузка данных в базу данных была успешна" << endl;
    cout << endl;
    printAllPrepods(db, counts);

    return db;
}

void clear_db(prepod** db) {

    for (int i = 0; i < ((db + 1) - db); i++) {
        delete[] db[i]->surname;
        delete[] db[i]->name;
        delete[] db[i]->department;
        delete[] db[i]->subject;
        delete db[i];
    }
    delete[] db;
}