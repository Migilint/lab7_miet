#include <iostream>
#include <string>
#include <cstring>
using namespace std;

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
        cout << "Не удалось закрыть файл";
        return 1;
    }

    cout << "\n-------------Файлы успешно закрылись!-------------\n";
    return 0;
}