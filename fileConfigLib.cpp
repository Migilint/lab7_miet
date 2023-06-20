#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int error_open(FILE* file) {
    if (file == NULL) {
        cout << "�� ������� ������� ����" << endl;
        return 1;
    }

    cout << "\n-------------����� ������� ���������!-------------\n";
    return 0;
}

int error_close(FILE* file)
{
    if (fclose(file))
    {
        cout << "�� ������� ������� ����";
        return 1;
    }

    cout << "\n-------------����� ������� ���������!-------------\n";
    return 0;
}

FILE* open_file(char db_name[], bool &loaded_db) {
    FILE* file;
    file = fopen(db_name, "r");

    if (error_open(file)) {
        file = fopen(db_name, "w"); fclose(file);
        cout << "������ ����� ����";
        file = fopen(db_name, "r");
        loaded_db = false;
        return file;
    }
    loaded_db = true;
    return file;
}

