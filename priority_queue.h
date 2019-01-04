#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H


typedef struct node{
    int key;
    char value;
    struct node *left, *right;    // always put the star with the name, not with the type
} Node;

typedef struct {
    int entered_nodes;
    int capacity;
    Node **nodes;
} PQ;

// structs are either passed by referance or by value.

void insert(PQ*, Node*);  // will insert a node into the PQ. That node could be a leaf node or the root of a tree
Node* delete_min(PQ*);    // will delete and return the node with the lowest key
void resize(PQ*, int);   // if the PQ is completly full, then its size will be doubled, else if the PQ is quarterly full, then its size will be halved
void exchange_nodes(Node**, int, int);
int is_less_than(Node **, int, int);
Node* create_node(int, char, Node*, Node*);



#endif