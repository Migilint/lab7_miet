#pragma once

#include "struct.h"

prepod* createPrepod(void);
prepod** addPrepod(prepod**, int&);

void printPrepod(prepod*);
void printAllPrepods(prepod**, int);

void findPrepodsByDepartment(prepod**, int, char*);
void findPrepodsBySubject(prepod**, int, char*, char*, char*);

bool comparePrepods(prepod*, prepod*);
