#include<stdlib.h>
#include "array.h"

Array * initialise_array(int size)
{
    Array *my_arr;

    my_arr = (Array *)malloc(sizeof(Array));

    if(my_arr == NULL) return NULL;

    my_arr->c_size = 0;
    my_arr->t_size = size;
    my_arr->arr = (int *)malloc(sizeof(int) * size);

    return my_arr;
}
int insert_data(Array *my_arr, int data)
{
    // Check if array is FULL return 0 if true
    if(my_arr->c_size == my_arr->t_size) return ARRAY_FULL;

    //Insert data at c_size position with pointer arithmetic
    *(my_arr->arr + my_arr->c_size) = data;
    my_arr->c_size++; // Increment the c_size

    return SUCCESS; // returns 1
}

Split * initialise_split_array(int size)
{
    Split *index;

    index = (Split *)malloc(sizeof(Split) * size);

    return index;
}


Split * split_array(Array *my_arr, int split)
{
    int sub_part, i, j, rem;;
    Split *index;

    if(split > my_arr->c_size/2) return SPIT_FAILED;

    rem = my_arr->c_size;
    sub_part = my_arr->c_size/ split;
    if(sub_part * split  < my_arr->c_size) sub_part++;

    index = initialise_split_array(split);

    for(i=0, j =0;i < my_arr->c_size && j< split; i += sub_part, j++)
    {
        (index+j)->index_ref  = (my_arr->arr + i);

        if(rem > sub_part)
            (index+j)->count = sub_part;
        else break;
        rem -= sub_part;
    }
    (index+j )->count = rem;

    return index;
}

/*void display(Split *new_arr)
{
    int i;
    for(i=0; i<)
}
*/
