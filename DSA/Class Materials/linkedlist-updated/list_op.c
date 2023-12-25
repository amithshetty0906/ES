#include<stdlib.h>
#include "list.h"

List * initialise_list()
{
    List *my_list;

    my_list = (List *)malloc(sizeof(List));
    my_list->head = my_list->tail = NULL;
    my_list->count = 0;

    return my_list;
}

Node *get_node(int data)
{
    Node *new_node;

    new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->ptr = NULL;

    return new_node;
}
int insert_at_beg(List *my_list, int data)
{
    Node *new_node = get_node(data); //create new node and store data

    if(new_node == NULL) return FAILED;

    if(my_list->count == 0) my_list->head = my_list->tail = new_node;
    else{
    new_node->ptr = my_list->head;
    my_list->head = new_node;
    }
    my_list->count++;

    return INSERT_SUCCESS;
}
int insert_at_end(List *my_list, int data)
{
     Node *new_node = get_node(data); //create new node and store data

    if(new_node == NULL) return FAILED;

    if(my_list->count == 0) my_list->head = my_list->tail = new_node;
    else{
        my_list->tail->ptr = new_node;
        my_list->tail = new_node;
    }
    my_list->count++;

    return INSERT_SUCCESS;
}
int insert_after_data(List *my_list, int data, int element)
{
    Node * new_node, *temp;

    if(my_list->count == 0) return FAILED; // check if list is empty
    // check if the element is the last node then insert at the end
    if(my_list->tail->data == element) return insert_at_end(my_list, data);
    // traverse through the list and find the position of element
    for(temp = my_list->head; temp!=NULL && temp->data != element;temp = temp->ptr);
    // if element not found
    if(temp == NULL)
        return FAILED;
    // if element found
    new_node = get_node(data); // create new node
    //make necessary connection
    new_node->ptr = temp->ptr;
    temp->ptr = new_node;

    my_list->count++;

    return INSERT_SUCCESS;
}

//Lab exercise
int insert_at_pos(List *my_list, int data, int pos);


int search_list(List *my_list, int element)
{
    Node *temp;

    for(temp = my_list->head; temp != NULL; temp = temp->ptr)
        if(temp->data == element) return 1;
    return 0;
}

int delete_at_beg(List *my_list)
{
    Node *temp;
    // check if list is empty, if true return fail
    if(my_list->count == 0) return 0;

    // check if list has one element
    if(my_list->count == 1){
        free(my_list->head);
        my_list->head = NULL;
        my_list->tail = NULL;
    }
    //move the head node
    else
    {
        temp = my_list->head;
        my_list->head = my_list->head->ptr;
        free(temp); //free the previous head
    }

    // decrement the count
    my_list->count--;
    // return succeed
    return DELETED;
}

//Lab Exercise
int delete_at_end(List *my_list)
{
    // check if list empty

    // check if list has one element

    // go to N-1 node

    // free Nth node

    // update tail pointer

    // decrement the counter

}

// Lab Exercise
int delete_element(List *my_list, int element)
{
    // check id list is empty

    // check if the element is at head position

    //check if it is last element

    // search if element exist

    // if not return FAIL

    // if found, free the node

    //decrement count

    //return DELETED
}

List * free_list(List *my_list) // deallocate memory of the list
{
    Node *temp;

    while(my_list->head != NULL)
    {
        temp = my_list->head;
        my_list->head = my_list->head->ptr;
        free(temp);
    }
    free(my_list);

    return NULL;
}

int merge_list(List *list_a, List *list_b)
{

}
int split_list(List *, int split_index);
