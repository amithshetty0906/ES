#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
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

    for(i=0; i< dyn_arr->c_size; i++)
        if(*(dyn_arr->arr + i) == element) return FOUND;
    return NOT_FOUND;
}

Array_dyn * deallocate(Array_dyn *dyn_arr)
{
    free(dyn_arr->arr);
    free(dyn_arr);

    return NULL;

}

Array_dyn * intersection(Array_dyn *arr_a, Array_dyn *arr_b)
{
    Array_dyn *arr_c;
    int i;

    if(arr_a->c_size == 0 || arr_b->c_size == 0) return NULL;

    arr_c = initialize_dynamic_array(arr_a->c_size);

    for(i=0; i<arr_a->c_size; i++)
    {
        if(search(arr_b, arr_a->arr[i]) && !search(arr_c, arr_a->arr[i] ))
                assert(insert_data_dyn(arr_c, arr_a->arr[i]));
    }
    return arr_c;
}


int max_min(Array_dyn *, Maxmin);

int is_palindrome(Array_dyn *dy_arr)
{
    int i=0, j = dy_arr->c_size - 1;

    while(i < j)
        if(dy_arr->arr[i++] != dy_arr->arr[j--]) return 0;
    return 1;
}

int bubble_sort_array(Array_dyn *dy_arr)
{
    int i, j, temp, flag;

    if(dy_arr->c_size <= 1) return 0;

    for(i=0; i < dy_arr->c_size; i++)
    {
        flag = 0;
        for(j=0; j < dy_arr->c_size - i - 1; j++)
        {
            if(*(dy_arr->arr + j) > *(dy_arr->arr + j + 1) )
            {
                temp = dy_arr->arr[j];
                dy_arr->arr[j] = dy_arr->arr[j+1];
                dy_arr->arr[j+1] = temp;

                flag = 1;
            }

        }
        if(flag == 0) return 1;
    }
    return 1;
}

void display(Array_dyn *dy_arr)
{
    int i;

    for(i=0; i < dy_arr->c_size; i++)
        printf(" %d ", dy_arr->arr[i]);
}
