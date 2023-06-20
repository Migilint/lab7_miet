#include "struct.h"
#include <iostream>

prepod* create_db_line(void);
prepod** create_db(int);
prepod** load_data_from_db(FILE*, int&);
void clear_db(prepod**, int);
void user_interface(bool, prepod**, int);