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