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
    Node* nodes;
} PQ;

// structs are either passed by referance or by value.

void insert(PQ*, Node);  // will insert a node into the PQ. That node could be a leaf node or the root of a tree
Node delete_min(PQ*);    // will delete and return the node with the lowest key
void resize(PQ*, int);
void exchange_nodes(Node*, int, int);


#endif