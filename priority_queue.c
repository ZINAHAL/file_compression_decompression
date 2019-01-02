#include <stdlib.h>
#include "priority_queue.h"


//p_queue->capacity is equivalent to (*p_queue).capacity


void insert(PQ *p_queue, Node user_node)
{
    if(p_queue->entered_nodes+1 == p_queue->capacity) { resize(p_queue, p_queue->capacity*2); } 
    
    p_queue->entered_nodes++;
    *(p_queue->nodes + p_queue->entered_nodes) = user_node;
    
    int i = p_queue->entered_nodes;
    while(i > 1 && (*(p_queue->nodes + i)).key < (*(p_queue->nodes + (i/2))).key)
    {
        exchange_nodes(p_queue->nodes, i/2, i);
        i /= 2;
    }
}

void resize(PQ *p_queue, int new_size)
{
    p_queue->nodes = realloc(p_queue->nodes, new_size*sizeof(Node));
    p_queue->capacity = new_size;
}

void exchange_nodes(Node* nds, int parent_i, int child_i)
{
    Node temp = *(nds + parent_i);
    *(nds + parent_i) = *(nds + child_i);
    *(nds + child_i) = temp;
}
