#include <string.h>
#include <stdlib.h>
#include<assert.h>
#include "employee.h"

int main()
{
    Emp *test;
    Employee data;

    test = initialise_employee(10);
    assert(test->c_size == 0 && test->t_size == 10);

    data.emp_id = 1001;
    strcpy(data.emp_name, "Ajay");
    data.emp_salary = 10000;
    assert(insert_data_employee(test, data));


    data.emp_id = 1002;
    strcpy(data.emp_name, "Alia");
    data.emp_salary = 600000;
    assert(insert_data_employee(test, data));

    data.emp_id = 1003;
    strcpy(data.emp_name, "Salman");
    data.emp_salary = 300000;
    assert(insert_data_employee(test, data));

    data.emp_id = 1004;
    strcpy(data.emp_name, "Sara");
    data.emp_salary = 750000;
    assert(insert_data_employee(test, data));

    data.emp_id = 1005;
    strcpy(data.emp_name, "Rahul");
    data.emp_salary = 500000;
    assert(insert_data_employee(test, data));

    assert(test->c_size == 5);
    assert((test->arr + 4)->emp_id == 1005);

    return 0;
}
