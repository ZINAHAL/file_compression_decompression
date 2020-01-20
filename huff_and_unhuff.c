#include "huff_and_unhuff.h"
#include <stdio.h>          // for NULL,
#include <limits.h>

Node* create_huffman_tree(MinPriorityQueue* p_queue)
{
    Node *huffman_node, *node_a, *node_b;
    while(p_queue->entered_nodes_counter != 1)
    {
        node_a = delete_min(p_queue);
        node_b = delete_min(p_queue);
        huffman_node = create_node(node_a->key + node_b->key, '\0', node_a, node_b);
        insert(p_queue, huffman_node);
    }

    return delete_min(p_queue);
}

void create_huffman_codes(Node* root, int* code_table, int code)
{
    // In-order traversal
    // Instead of using 0 for left, I'm going to use 2 for left

    if(root != NULL)
    {
        create_huffman_codes(root->left, code_table, (code*10)+2);
        if(root->value != '\0')
        {
            *(code_table + root->value) = code;
        }
        create_huffman_codes(root->right, code_table, (code*10)+1);
    }
}

void compress_data(char* data, int* huffman_code_table)
{
    FILE *binary_file = fopen("compressed_data.bin", "wb");
    short output = 0;
    int code;
    int d = 0, 
    b = (CHAR_BIT * sizeof(output)) - 1;
    while(*(data + d) != '\0')
    {
        code = *(huffman_code_table + *(data + d));
        fill_byte_and_write(&output, code, &b, binary_file);
        fwrite(&output, sizeof(output), 1, binary_file);
        d++;
    }
}

void fill_byte_and_write(short* output, int huffman_code, int* b, FILE* binary_file)
{
    int temp = huffman_code;

    if(temp != 1 && temp != 2)
    {
        fill_byte_and_write(output, temp/10, b, binary_file);
        temp = temp % 10;
    }

    if(temp == 1)
    {
        *output = *output | (1 << *b);
        //(data|(1 << pos))
    }

    *b--;

    if(*b == -1)
    {
        fwrite(output, sizeof(*output), 1, binary_file);
        *b = (CHAR_BIT * sizeof(*output)) - 1;
        *output = 0;
    }
}
