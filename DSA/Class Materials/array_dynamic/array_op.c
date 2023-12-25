#include<stdlib.h>
#include "array.h"

Array_dyn * initialize_dynamic_array(int size)
{
    Array_dyn *dyn_arr;

    dyn_arr = (Array_dyn *)malloc(sizeof(Array_dyn));

    if(dyn_arr == NULL) return NULL;

    dyn_arr->c_size = 0;
    dyn_arr->t_size = size;
    dyn_arr->arr = (int *)malloc(sizeof(int) * size);

    return dyn_arr;
}

int insert_data_dyn(Array_dyn *dyn_arr, int data)
{
    if(dyn_arr->c_size == dyn_arr->t_size) return ARRAY_FULL;

    *(dyn_arr->arr + dyn_arr->c_size) = data;
    dyn_arr->c_size++;

    return SUCCESS;
}

int search(Array_dyn *dyn_arr, int element)
{
    int i;

    for(i=0; i<dyn_arr->c_size;i++)
        if(*(dyn_arr->arr + i) == element) return FOUND;
    return NOT_FOUND;
}

int deallocate(Array_dyn *);
