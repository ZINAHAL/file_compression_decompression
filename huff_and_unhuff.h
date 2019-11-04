#ifndef HUFF_AND_UNHUFF_HEADER
#define HUFF_AND_UNHUFF_HEADER

#include "priority_queue.h"

Node* create_huffman_tree(MinPriorityQueue*);
void traverse_huffman_tree(Node*, int*, int);

#endif