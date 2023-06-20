#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int error_open(FILE* file1, FILE* file2) {
    if (file1 == NULL) {
        cout << "Не удалось открыть файл file1" << endl;
        return 1;
    }
    if (file2 == NULL) {
        cout << "Не удалось открыть файл file2" << endl;
        return 1;
    }
    cout << "\n-------------Файлы успешно открылись!-------------\n";
    return 0;
}

int error_close(FILE* file1, FILE* file2)
{
    if (fclose(file2))
    {
        cout << "Не удалось закрыть файл file.txt";
        return 1;
    }
    if (fclose(file1))
    {
        cout << "Не удалось закрыть файл db.txt";
        return 1;
    }
    cout << "\n-------------Файлы успешно закрылись!-------------\n";
    return 0;
}