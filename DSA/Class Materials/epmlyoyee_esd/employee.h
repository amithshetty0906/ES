struct _employee_
{
    int emp_id;
    char emp_name[10];
    float emp_salary;
};
typedef struct _employee_ Employee;


struct _emp_arr_
{
    Employee *arr;
    int c_size, t_size;
};

typedef struct _emp_arr_ Emp;

Emp * initialise_employee(int);
int insert_data_employee(Emp *, Employee);
int search(Emp *, char *);
