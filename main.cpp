#define _CRT_SECURE_NO_WARNINGS
#include "lab6.h"
#include "struct.h"
#include "fileConfigLib.h"
#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    FILE* db; FILE* buf;
    db = fopen("db.txt", "w");
    buf = fopen("buf.txt", "w");
    if(error_open(db, buf)) return 0;
    if (error_close(db, buf)) return 0;
    

    return 0;
}