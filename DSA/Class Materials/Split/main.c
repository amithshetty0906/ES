#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include "array.h"

int main()
{
    Array *test;
    Split *test_index;

    test = initialise_array(10);
    assert(test != NULL);

    assert(insert_data(test, 10));
    assert(insert_data(test, 20));
    assert(insert_data(test, 30));
    assert(insert_data(test, 40));
    assert(insert_data(test, 50));
    assert(insert_data(test, 60));
    assert(insert_data(test, 70));
    assert(insert_data(test, 80));


    assert(test->c_size  + 2 == test->t_size);

    test_index = split_array(test,3);

    printf("\n data = %d and count = %d", *(test_index->index_ref), test_index->count);
    printf("\n data = %d and count = %d", *(test_index+1)->index_ref, (test_index+1)->count);
      printf("\n data = %d and count = %d", *(test_index+2)->index_ref, (test_index+2)->count);


    return 0;
}
