#define SUCCESS 1
#define ARRAY_FULL 0
#define SPIT_FAILED NULL;

struct _array_
{
    int *arr;
    int c_size, t_size;
};
typedef struct _array_ Array;


struct split_array_reference
{
    int *index_ref;
    int count;
};
typedef struct split_array_reference Split;

Split * initialise_split_array(int size);

Array * initialise_array(int);
int insert_data(Array *, int);
Split * split_array(Array *, int split);
