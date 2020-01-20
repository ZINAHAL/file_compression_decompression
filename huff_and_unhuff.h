#ifndef HUFF_AND_UNHUFF_HEADER
#define HUFF_AND_UNHUFF_HEADER

#include <stdio.h>
#include "priority_queue.h"

Node* create_huffman_tree(MinPriorityQueue*);
void create_huffman_codes(Node*, int*, int);

void compress_data(char*, int*); // will produce a binary file (.bin)
void fill_byte_and_write(short*, int, int*, FILE*); // will fill a byte with bits that correspond to the Huffman code. If it's full, then it will be written to the file, else nothing will happen.

#endif