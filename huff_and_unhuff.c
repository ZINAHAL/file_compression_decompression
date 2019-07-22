#include "huff_and_unhuff.h"

Node* create_huffman_tree(MinPriorityQueue* p_queue)
{
    Node *huffman_node, *node_a, *node_b;
    while(p_queue->entered_nodes_counter != 1)
    {
        node_a = delete_min(p_queue);
        node_b = delete_min(p_queue);
        huffman_node = create_node(node_a->key + node_b->key, NULL, node_a, node_b);
        insert(p_queue, huffman_node);
    }

    return delete_min(p_queue);
}