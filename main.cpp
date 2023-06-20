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
    char db_name[] = "db.txt";
    db_file = open_file(db_name);

    prepod** db = load_data_from_db(db_file);
    cout << (db + 1) - db << endl;

    user_interface(true, db);

    if (error_close(db_file)) return 0;
    clear_db(db);

    return 0;
}