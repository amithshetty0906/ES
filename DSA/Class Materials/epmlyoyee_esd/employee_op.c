#include<stdlib.h>
#include "employee.h"

Emp * initialise_employee(int size)
{
    Emp *my_emp;

    my_emp = (Emp *) malloc(sizeof(Emp));
    my_emp->c_size = 0;
    my_emp->t_size = size;
    my_emp->arr = (Employee *)malloc(sizeof(Employee) * size);

    return my_emp;
}
int insert_data_employee(Emp *my_emp, Employee data)
{
    if(my_emp->c_size == my_emp->t_size) return 0;

    *(my_emp->arr + my_emp->c_size) = data;
    my_emp->c_size++;

    return 1;
}
int search(Emp *, char *);
