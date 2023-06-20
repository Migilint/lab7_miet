#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int error_open(FILE* file1, FILE* file2) {
    if (file1 == NULL) {
        cout << "�� ������� ������� ���� file1" << endl;
        return 1;
    }
    if (file2 == NULL) {
        cout << "�� ������� ������� ���� file2" << endl;
        return 1;
    }
    cout << "\n-------------����� ������� ���������!-------------\n";
    return 0;
}

int error_close(FILE* file1, FILE* file2)
{
    if (fclose(file2))
    {
        cout << "�� ������� ������� ���� file.txt";
        return 1;
    }
    if (fclose(file1))
    {
        cout << "�� ������� ������� ���� db.txt";
        return 1;
    }
    cout << "\n-------------����� ������� ���������!-------------\n";
    return 0;
}