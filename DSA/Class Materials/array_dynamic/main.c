#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "array.h"

int main()
{
    Array_dyn *test;

    test = initialize_dynamic_array(7);
    assert(test != NULL);
    assert(test->c_size == 0 && test->t_size == 7);
    assert(test->arr != NULL);

    assert(insert_data_dyn(test, 10));
    assert(insert_data_dyn(test, 20));
    assert(insert_data_dyn(test, 30));
    assert(insert_data_dyn(test, 40));
    assert(insert_data_dyn(test, 50));
    assert(insert_data_dyn(test, 60));
    assert(insert_data_dyn(test, 70) == SUCCESS);

    assert(test->c_size == test->t_size);

    assert(insert_data_dyn(test, 80) == ARRAY_FULL);

    assert(search(test, 50));
    assert(search(test, 70));
    assert(search(test, 10));
    assert(search(test, 90) == NOT_FOUND);


    return 0;
}
