#include <stdlib.h>
#include "program_input_handler.h"
#include "priority_queue.h"
#include "huff_and_unhuff.h"
#define CHARACTERS 256


void main(int argc, char **argv)
{
    printf("IM HERE 1\n");
    check_user_input_valid(argc, argv);
    char *user_input_buffer = get_user_input(argv[1]);
    int *chars_freqs = get_chars_frequencies(CHARACTERS, user_input_buffer);
    
    MinPriorityQueue *p_queue = create_empty_queue(); 
    Node *node;
        printf("*******************%d\n", *(chars_freqs + 145));
                printf("*******************%s\n", user_input_buffer);

    for(int i = 0; i < CHARACTERS; i++)
    {
        if(*(chars_freqs + i))
        {
            node = create_node(*(chars_freqs + i), i, NULL, NULL);
            insert(p_queue, node);
            printf("char %c :: freq %d\n", i, *(chars_freqs + i));
        }
    }
    
    // char *json_buffer = get_chars_and_its_frequencies(argv[1]);
    // cJSON *json_data = cJSON_Parse(json_buffer); 
    // if(json_data == NULL)
    // {
    //    printf("Could not parse the json buffer\n");
    //    exit(0);
    // }
    // const cJSON *char_freq_entries = cJSON_GetObjectItemCaseSensitive(json_data, "chars_and_frequencies");
    // const cJSON *entry = NULL;
    // cJSON_ArrayForEach(entry, char_freq_entries)
    // {
    //     cJSON *character = cJSON_GetObjectItemCaseSensitive(entry, "character");
    //     cJSON *frequency = cJSON_GetObjectItemCaseSensitive(entry, "frequency");

    //     node = create_node((int)frequency->valuedouble, *(character->valuestring), NULL, NULL);
    //     insert(p_queue, node);
    // }

    //***************************

    // Node *huffman_tree_root = create_huffman_tree(p_queue);
    // int *code_table = NULL;
    // code_table = calloc(CHARACTERS, sizeof(*code_table));
    // create_huffman_codes(huffman_tree_root, code_table, 0);

    //***************************
    
    
    // for(int i = 0; i < CHARACTERS; i++)
    // {
    //     printf("%c = %i\n", i, *(code_table + i));
    // }

    //char *buf_test = get_user_input("zinah.txt");
    // FILE *f_test = fopen("test.txt", "w");
    // int i = 0;
    // while(*(user_input_buffer + i) != '\0')
    // {
    //     printf("char is %c\n", *(user_input_buffer + i));
    //     fprintf(f_test, "%i", *(code_table + *(user_input_buffer + i)));
    //     i++;
    // }
    // fclose(f_test);
    
    // char *code_test = get_user_input("test.txt");
    // i = 0;
    // Node *temp = huffman_tree_root;
    // while(*(code_test + i) != '\0')
    // {
    //     if(*(code_test + i) == '1')
    //     {
    //         temp = temp->right;
    //     }else{
    //         temp = temp->left;
    //     }

    //     if(temp->value != '\0')
    //     {
    //         printf("%c", temp->value);
    //         temp = huffman_tree_root;
    //     }

    //     i++;
    // }

    // printf("\nuser input buffer = %s\n", user_input_buffer);
    // printf("\n sizeis %d\n", (int)strlen(user_input_buffer));





    //compress_data(user_input_buffer, code_table);



    free(chars_freqs);
    //free(code_table);
    free(node);
    //cJSON_Delete(json_data);
    //free(json_buffer);
    free(p_queue);
    free(user_input_buffer);
}