#pragma once

struct prepod {
    struct fio {
        char* name;
        char* surname;
        char* secondname;
    } fio_prepod;

    char* department;
    char* subject;

    struct date {
        int day;
        char* month;
        int year;
    } date_ITB;
};

