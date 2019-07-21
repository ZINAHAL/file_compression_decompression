#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H


typedef struct node{
    int key;
    char value;
    struct node *left, *right;    // always put the star with the name, not with the type
} Node;

typedef struct {
    int entered_nodes_counter;
    int capacity;
    Node **nodes_buffer;
} MinPriorityQueue;

// structs are either passed by referance or by value.

void insert(MinPriorityQueue*, Node*);  // will insert a node into the MinPriorityQueue. That node could be a leaf node or the root of a tree
Node* delete_min(MinPriorityQueue*);    // will delete and return the node with the lowest key
void resize(MinPriorityQueue*, int);   // if the MinPriorityQueue is completly full, then its size will be doubled, else if the MinPriorityQueue is quarterly full, then its size will be halved
void exchange_nodes(Node**, int, int);
int is_less_than(Node **, int, int);
Node* create_node(int, char, Node*, Node*);
MinPriorityQueue* create_empty_queue();


#endif