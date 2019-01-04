#include <stdlib.h>
#include "priority_queue.h"


//p_queue->capacity is equivalent to (*p_queue).capacity


void insert(PQ *p_queue, Node *user_node)
{
    if(p_queue->entered_nodes+1 == p_queue->capacity) { resize(p_queue, p_queue->capacity*2); }
    
    p_queue->entered_nodes++;
    *(p_queue->nodes + p_queue->entered_nodes) = user_node;
    
    int i = p_queue->entered_nodes;      //swim
    while(i > 1 && is_less_than(p_queue->nodes, i, i/2))
    {
        exchange_nodes(p_queue->nodes, i, i/2);
        i /= 2;
    }
}

void resize(PQ *p_queue, int new_size)
{
    p_queue->nodes = realloc(p_queue->nodes, new_size*sizeof(*(p_queue->nodes)));
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

Node* delete_min(PQ *p_queue)
{
    if(p_queue == NULL || p_queue->entered_nodes == 0){ return NULL; }
    Node *min_n = *(p_queue->nodes + 1);  //return an address
    exchange_nodes(p_queue->nodes, p_queue->entered_nodes, 1);
    *(p_queue->nodes + p_queue->entered_nodes) = NULL;
    p_queue->entered_nodes--;

    int i = 1;                  //sink
    int small_child;
    while((2*i) <= p_queue->entered_nodes)
    {
        small_child = 2*i;
        if(is_less_than(p_queue->nodes, small_child+1, small_child)){ small_child++; }
        if(!is_less_than(p_queue->nodes, small_child, i)){ break; }
        exchange_nodes(p_queue->nodes, i, small_child);
        i = small_child;
    }

    if(p_queue->entered_nodes+1 == p_queue->capacity/4){ resize(p_queue, p_queue->capacity/2); }

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
