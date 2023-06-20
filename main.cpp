#define _CRT_SECURE_NO_WARNINGS
#include "lab6.h"
#include "struct.h"
#include "fileConfigLib.h"
#include "dbConfigLib.h"
#include <iostream>

using namespace std;




int main() {


    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    prepod** db;
    FILE* db_file; 
    bool db_loaded;
    char db_name[] = "db.txt";
    int db_counts;

    if (error_open_zero_file(db_name)) remove(db_name);
    db_file = open_file(db_name, db_loaded);
    //cout << db_loaded << endl;
    //db_loaded = true;

    if (db_loaded) 
    {
        db = load_data_from_db(db_file, db_counts);
    //   cout << time(0) << endl;
        
    } else 
    {

        cout << "Введите количество преподавателей: ";
        cin >> db_counts;

        db = new prepod * [db_counts];
        for (int i = 0; i < db_counts; i++) {
            cout << "Преподаватель " << db_counts << ":" << endl;
            db[i] = createPrepod();
        }
    }

    user_interface(true, db, db_counts);
    db_file = save_file(db_name, db_file, db_counts, db);
    if (error_close(db_file)) return 0;
    clear_db(db, db_counts);

    return 0;
}