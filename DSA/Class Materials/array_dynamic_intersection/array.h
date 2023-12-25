#define ARRAY_FULL 0
#define SUCCESS 1
#define NOT_FOUND 0
#define FOUND 1

struct _array_dynamic_
{
    int *arr;
    int c_size, t_size;
};
typedef struct _array_dynamic_ Array_dyn;

struct _max_min_
{
    int max, min;
};
typedef struct _max_min_ Maxmin;

Array_dyn * initialize_dynamic_array(int size);
int insert_data_dyn(Array_dyn *, int data);
int search(Array_dyn *, int element);
Array_dyn * intersection(Array_dyn *, Array_dyn *);
int max_min(Array_dyn *, Maxmin);
int is_palindrome(Array_dyn *);
int bubble_sort_array(Array_dyn *);
// merge_array() : content of src array is copied to tgt array
int merge_array(Array_dyn *src, Array_dyn *tgt);
Array_dyn * deallocate(Array_dyn *);
void display(Array_dyn *);
