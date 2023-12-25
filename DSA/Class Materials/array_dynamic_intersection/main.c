#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "array.h"

int main()
{
    Array_dyn *test, *two, *arr_three;

    two = initialize_dynamic_array(9);
    test = initialize_dynamic_array(7);
    assert(test != NULL);
    assert(test->c_size == 0 && test->t_size == 7);
    assert(test->arr != NULL);

    assert(insert_data_dyn(test, 10));
    assert(insert_data_dyn(test, 20));
    assert(insert_data_dyn(test, 30));
    assert(insert_data_dyn(test, 40));
    assert(insert_data_dyn(test, 30));
    assert(insert_data_dyn(test, 10));
    assert(insert_data_dyn(test, 10) == SUCCESS);

    assert(test->c_size == test->t_size);

    assert(insert_data_dyn(test, 80) == ARRAY_FULL);

    assert(insert_data_dyn(two, 40));
    assert(insert_data_dyn(two, 30));
    assert(insert_data_dyn(two, 10));
    assert(insert_data_dyn(two, 10));
    assert(insert_data_dyn(two, 90));
    assert(insert_data_dyn(two, 60));

    assert(search(test, 40));
    assert(search(test, 30));
    assert(search(test, 10));
    assert(search(test, 90) == NOT_FOUND);

   // test = deallocate(test);

   // assert(test == NULL);
   arr_three = intersection(test, two);
   printf("\n After Intersection data: ");
   display(arr_three);

   assert(arr_three->c_size == 3);

   assert(is_palindrome(test) == 0);

   assert(bubble_sort_array(test));

    printf("\n After sorting data : ");
   display(test);

   test=deallocate(test);
    return 0;
}
