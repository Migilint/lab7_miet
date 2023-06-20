#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include "struct.h"
using namespace std;

int error_open_zero_file(char file_name[]) {
    struct stat st;
    if (stat(file_name, &st) == 0) {
        if (st.st_size == 0) {
            cout << "Ошибка пустого файла" << endl;
            cout << "Исправление..." << endl;
            return 1;
        }
        return 0;
    }
    return -1;
}

int error_open(FILE* file) {
    if (file == NULL) {
        cout << "Не удалось открыть файл" << endl;
        return 1;
    }

    cout << "\n-------------Файлы успешно открылись!-------------\n";
    return 0;
}

int error_close(FILE* file)
{
    if (fclose(file))
    {
        cout << "Не удалось закрыть файл" << endl;
        return 1;
    }

    cout << "\n-------------Файлы успешно закрылись!-------------\n";
    return 0;
}

FILE* open_file(char db_name[], bool &loaded_db) {
    FILE* file;
    file = fopen(db_name, "r");

    if (error_open(file)) {
        file = fopen(db_name, "w");
        cout << "Ошибка открытие файла" << endl;
        cout << "Исправление..." << endl << "Создание нового файла" << endl;

        loaded_db = false;
        return file;
    }
    loaded_db = true;
    return file;
}

FILE* save_file(char db_name[], FILE* db_file, int db_counts, prepod** db) {
    fclose(db_file);
    db_file = fopen(db_name, "w+");
    fprintf(db_file, "%d\n", db_counts);
    for (int i = 0; i < db_counts; i++) {
        fprintf(db_file, "%s %s %s %s %s %i %s %i\n", 
            db[i]->fio_prepod.surname, db[i]->fio_prepod.name, db[i]->fio_prepod.secondname, 
            db[i]->department, db[i]->subject,
            db[i]->date_ITB.day, db[i]->date_ITB.month, db[i]->date_ITB.year);
    }
    cout << "Сохранение базы данных в файл 'db.txt'" << endl;
    system("pause");
    return db_file;
}

