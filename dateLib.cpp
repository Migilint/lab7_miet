#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string.h>
#include "lab6.h"
#include "struct.h"

using namespace std;

int divisionDate(int y, int m, int d) {
    m = (m + 9) % 12;
    y = y - m / 10;
    return (365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1));
}

int convertMonth(char* month_ITB) {
         if (strcmp(month_ITB,"Декабрь") == 0) return 12;
    else if (strcmp(month_ITB,"Январь") == 0) return 1;
    else if (strcmp(month_ITB,"Февраль") == 0) return 2;
    else if (strcmp(month_ITB, "Март") == 0) return 3;
    else if (strcmp(month_ITB, "Апрель") == 0) return 4;
    else if (strcmp(month_ITB, "Май") == 0) return 5;
    else if (strcmp(month_ITB, "Июнь") == 0) return 6;
    else if (strcmp(month_ITB, "Июль") == 0) return 7;
    else if (strcmp(month_ITB, "Август") == 0) return 8;
    else if (strcmp(month_ITB, "Сентябрь") == 0) return 9;
    else if (strcmp(month_ITB, "Октябрь") == 0) return 10;
    else if (strcmp(month_ITB, "Ноябрь") == 0) return 11;
    else return 0; 
}

bool errorITBDate_Month(int month, int count) {
    if (month == 0) { 
        cout << "Неправильно введена дата преподавателя " << count << endl;
        return 1; }
    else {
        return 0;
    }
}

void findPrepodsByDateITB(prepod** arr, int n) {
    prepod** depArr = new prepod * [n];
    
    time_t now = time(0);
    struct tm *time = localtime(&now);

    cout << "Фамилия\tИмя\tОтчество\tКафедра\tПредмет\tИТБ" << endl;
    for (int i = 0; i < n; i++) {

        int day_ITB = arr[i]->date_ITB.day;
        char* month_ITB = arr[i]->date_ITB.month;
        int year_ITB = arr[i]->date_ITB.year;

        if (errorITBDate_Month(convertMonth(month_ITB), i));
        else {
            
            if (divisionDate(time->tm_year+1900, time->tm_mon+1, time->tm_mday) - divisionDate(year_ITB, convertMonth(month_ITB), day_ITB) > 150)
                //if ((time(0) - ((day_ITB * 3600) + (convertMonth(month_ITB) * 30 * 3600) + (year_ITB * 365) * 24 * 3600)) > 15 * 30 * 24 * 3600) {
                printPrepod(arr[i]);
            
        }
    }
} 


//cout << divisionDate(time->tm_year + 1900, time->tm_mon + 1, time->tm_mday) - divisionDate(year_ITB, convertMonth(month_ITB), day_ITB) << endl;