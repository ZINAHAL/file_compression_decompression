#include <stdlib.h>
#include <string.h>
#include "program_input_handler.h"


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
    buffer = malloc(sizeof(*buffer) * (file_size + 1)); // the 1 is for the null '\0' character
    fread(buffer, sizeof(*buffer), file_size, fptr);
    fclose(fptr);
    *(buffer + file_size) = '\0';
    return buffer;
}

int get_file_size(FILE *fptr)
{
    fseek(fptr, 0, SEEK_END); // fseek will fail on files > 4GB
    int size = ftell(fptr);
    rewind(fptr);
    return size;
}

int* get_chars_frequencies(int characters, char *user_input)
{
    int *buffer;
    buffer = calloc(characters, sizeof(*buffer));
    for(int i = 0; *(user_input + i) != '\0'; i++)
    {
        printf("%d\n", *(user_input + i));
        *(buffer + *(user_input + i)) = *(buffer + *(user_input + i)) + 1;
    }
    return buffer;
}


// char* get_chars_and_its_frequencies(char *file_name)
// { 
//     char instruction[strlen("./get_frequencies_of_chars < ") + strlen(file_name) + 1];
//     strcpy(instruction, "./get_frequencies_of_chars < ");
//     strcat(instruction, file_name);
//     FILE *fptr = popen(instruction, "r"); // a stream/pipe is opened
//     if(fptr == NULL)
//     {
//         printf("There is error in the given instruction\n");
//         exit(0);
//     }
//     char *buffer;
//     int buffer_size = 6000;
//     buffer = malloc(sizeof(*buffer)*buffer_size);
//     fread(buffer, sizeof(buffer), buffer_size, fptr);
//     pclose(fptr);
//     return buffer;
// }