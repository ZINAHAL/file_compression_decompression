#include <stdlib.h>
#include "program_input_handler.h"
#include "priority_queue.h"
#include "cJSON/cJSON.h"
#include "huff_and_unhuff.h"
#define ASCII_CHARACTERS 128


void main(int argc, char **argv)
{
    check_user_input_valid(argc, argv);
    char *user_input_buffer = get_user_input(argv[1]);
    char *json_buffer = get_chars_and_its_frequencies(argv[1]);

    MinPriorityQueue *p_queue = create_empty_queue(); 
    Node *node;

    cJSON *json_data = cJSON_Parse(json_buffer); 
    if(json_data == NULL)
    {
       printf("Could not parse the json buffer\n");
       exit(0);
    }

    const cJSON *char_freq_entries = cJSON_GetObjectItemCaseSensitive(json_data, "chars_and_frequencies");
    const cJSON *entry = NULL;
    cJSON_ArrayForEach(entry, char_freq_entries)
    {
        cJSON *character = cJSON_GetObjectItemCaseSensitive(entry, "character");
        cJSON *frequency = cJSON_GetObjectItemCaseSensitive(entry, "frequency");

        node = create_node((int)frequency->valuedouble, *(character->valuestring), NULL, NULL);
        insert(p_queue, node);
    }

    Node *huffman_tree_root = create_huffman_tree(p_queue);
    int *code_table = NULL;
    code_table = malloc(ASCII_CHARACTERS * sizeof(*code_table));
    traverse_huffman_tree(huffman_tree_root, code_table, 0);

    free(code_table)
    free(node);
    cJSON_Delete(json_data);
    free(p_queue);
    free(json_buffer);
    free(user_input_buffer);
}