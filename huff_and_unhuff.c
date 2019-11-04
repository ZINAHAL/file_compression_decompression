#include "huff_and_unhuff.h"
#include <stdio.h>          // for NULL,

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

void traverse_huffman_tree(Node* root, int* code_table, int code)
{
    // In-order traversal
    // Instead of using 0 for left and 1 for right, I'm going to use 1 for left and 2 for right
    if(root != NULL)
    {
        traverse_huffman_tree(root->left, code_table, (code*10)+1);
        if(root->value != '\0')
        {
            *(code_table + root->value) = code;
        }
        traverse_huffman_tree(root->right, code_table, (code*10)+2);
    }
}
