#define _CRT_SECURE_NO_WARNINGS
#include "lab6.h"
#include "struct.h"
#include "fileConfigLib.h"
#include <iostream>

using namespace std;




int main() {

    setlocale(LC_ALL, "Russian");

    FILE* db; 
    char db_name[] = "db.txt";
    db = open_file(db_name);

    if (error_close(db)) return 0;
    

    return 0;
}