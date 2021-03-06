#include <stdlib.h>
#include <stdio.h>
#include "priority_queue.h"


//p_queue->capacity is equivalent to (*p_queue).capacity


void insert(MinPriorityQueue *p_queue, Node *user_node)
{
    if(p_queue->entered_nodes_counter+1 == p_queue->capacity) { resize(p_queue, p_queue->capacity*2); }
    
    p_queue->entered_nodes_counter++;
    *(p_queue->nodes_buffer + p_queue->entered_nodes_counter) = user_node;
    
    int i = p_queue->entered_nodes_counter;      //swim
    while(i > 1 && is_less_than(p_queue->nodes_buffer, i, i/2))
    {
        exchange_nodes(p_queue->nodes_buffer, i, i/2);
        i /= 2;
    }
}

void resize(MinPriorityQueue *p_queue, int new_size)
{
    p_queue->nodes_buffer = realloc(p_queue->nodes_buffer, new_size*sizeof(*(p_queue->nodes_buffer)));
    p_queue->capacity = new_size;
}

void exchange_nodes(Node **nds, int a, int b)
{
    Node *temp = *(nds + b);
    *(nds + b) = *(nds + a);
    *(nds + a) = temp;
}

int is_less_than(Node **nds, int a, int b)
{
    return (*(nds + a))->key < (*(nds + b))->key;
}

Node* delete_min(MinPriorityQueue *p_queue)
{
    if(p_queue == NULL || p_queue->entered_nodes_counter == 0){ return NULL; }

    Node *min_n = *(p_queue->nodes_buffer + 1);  //return an address
    exchange_nodes(p_queue->nodes_buffer, p_queue->entered_nodes_counter, 1);
    *(p_queue->nodes_buffer + p_queue->entered_nodes_counter) = NULL;  
    p_queue->entered_nodes_counter--;

    int i = 1;                  //sink
    int small_child_idx;

    //while the left child of parent i is not a leaf node. The left child could be at indexes less than "entered nodes" or at index "entered nodes"
    while((2*i) <= p_queue->entered_nodes_counter) 
    {
        small_child_idx = 2*i;  // assuming, for now, that the left child has the smallest key, and therefore we are storing its idex.
        // There is always a left child, but there may or may not be a right child. Therefore we must check for the presence of the right child.
        // If small_child_idx is less than "entered_nodes" index then there IS a right child
        // if small_child_idx equals or greater than "entered_nodes" index then there is NO right child. Because "entered_nodes" marks the index of the last node in the array which is being occupied by the left child.
        if(small_child_idx < p_queue->entered_nodes_counter && is_less_than(p_queue->nodes_buffer, small_child_idx+1, small_child_idx)){ small_child_idx++; } 
        if(!is_less_than(p_queue->nodes_buffer, small_child_idx, i)){ break; }
        exchange_nodes(p_queue->nodes_buffer, i, small_child_idx);
        i = small_child_idx;
    }

    if(p_queue->entered_nodes_counter+1 == p_queue->capacity/4){ resize(p_queue, p_queue->capacity/2); }

    return min_n;
}

Node* create_node(int k, char v, Node* l, Node* r)
{
    Node *result = NULL;
    result = malloc(sizeof(*result));
    result->key  = k;
    result->value = v;
    result->left = l;
    result->right = r;

    return result;
}

MinPriorityQueue* create_empty_queue()
{
    MinPriorityQueue *queue = NULL;
    queue = malloc(sizeof(*queue));
    queue->entered_nodes_counter = 0;
    queue->capacity = 30;
    queue->nodes_buffer = malloc(sizeof(*(queue->nodes_buffer)) * queue->capacity);

    return queue;
}
