#ifndef HUFF_HEADER
#define HUFF_HEADER

//if the user input is not valid then the program will be terminated by the exit(0) function. 
void check_user_input_valid(int, char**);
char* get_user_input(char*);
int get_file_size(FILE*);
void free_buffer(char*);

char* get_chars_and_its_frequencies(char*);


#endif