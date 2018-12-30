#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H


typedef struct node{
    int key;
    char value;
    struct node* left, right;
} Node;

typedef struct {
    int entered_nodes;
    Node* nodes;
} PQ;


void insert(PQ, Node);  // will insert a node into the PQ. That node could be a leaf node or the root of a tree
Node delete_min(PQ);    // will delete and return the node with the lowest key
void resize(PQ);


#endif