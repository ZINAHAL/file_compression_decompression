#ifndef PROGRAM_INPUT_HANDLER_HEADER
#define PROGRAM_INPUT_HANDLER_HEADER

#include <stdio.h>


//if the user input is not valid then the program will be terminated by the exit(0) function. 
void check_user_input_valid(int, char**);
char* get_user_input(char*);
int get_file_size(FILE*);

char* get_chars_and_its_frequencies(char*);


#endif