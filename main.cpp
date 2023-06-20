#define _CRT_SECURE_NO_WARNINGS
#include "lab6.h"
#include "struct.h"
#include "fileConfigLib.h"
#include "dbConfigLib.h"
#include <iostream>

using namespace std;




int main() {

    setlocale(LC_ALL, "Russian");

    FILE* db_file; 
    bool loaded_db;
    char db_name[] = "db.txt";
    int counts;

    db_file = open_file(db_name, loaded_db);
    cout << loaded_db << endl;

    prepod** db = load_data_from_db(db_file, counts);
    cout << counts << endl;

    user_interface(true, db, counts);

    if (error_close(db_file)) return 0;
    clear_db(db, counts);

    return 0;
}