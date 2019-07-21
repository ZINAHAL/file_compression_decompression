#include "program_input_handler.h"


void main(int argc, char **argv)
{
    check_user_input_valid(argc, argv);
    char *user_input_buffer = get_user_input(argv[1]);
    char *json_buffer = get_chars_and_its_frequencies(argv[1]);

    free_buffer(json_buffer);
    free_buffer(user_input_buffer); 
}