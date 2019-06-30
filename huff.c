#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//if the user input is not valid then the program will be terminated by the exit(0) function. 
void check_user_input_valid(int, char**);
char* get_user_input(char*);
int get_file_size(FILE*);
void free_buffer(char*);


void main(int argc, char **argv)
{
    check_user_input_valid(argc, argv);
    char *user_input_buffer = get_user_input(argv[1]);

    free_buffer(user_input_buffer); 
}


void check_user_input_valid(int argc, char **argv)
{
    if(argc != 2)
    { 
        printf("Enter a single .txt file that you wish to compress\n");  
        exit(0); 
    }
    
    if(strstr(argv[1], ".") == NULL || strcmp(strstr(argv[1], "."), ".txt") != 0){ 
        printf("Only .txt file format is accepted\n");  
        exit(0); 
    }
}

char* get_user_input(char *file_name)
{
    FILE *fptr = fopen(file_name, "r");
    if(fptr == NULL)
    {
        printf("The file entered does not exist\n");
        exit(0);
    }
    int file_size = get_file_size(fptr); 
    char *buffer;
    buffer = malloc(sizeof(buffer)*file_size);
    fread(buffer, sizeof(buffer), file_size, fptr);
    fclose(fptr);
    return buffer;
}

int get_file_size(FILE *fptr)
{
    fseek(fptr, 0, SEEK_END);
    int size = ftell(fptr) + 1;
    rewind(fptr);
    return size;
}

void free_buffer(char *buffer)
{
    free(buffer);
}
