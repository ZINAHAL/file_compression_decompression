#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//if the user input is not valid then the program will be terminated by the exit(0) function. 
//If valid, then the 3rd argument will be initialized to the memory address of the given user file 
void check_user_input_valid(int, char**, FILE**);



void main(int argc, char **argv)
{
    FILE *user_file_ptr;
    check_user_input_valid(argc, argv, &user_file_ptr);
}


void check_user_input_valid(int argc, char **argv, FILE **fptr)
{
    if(argc != 2)
    { 
        printf("Enter a single .txt file that you wish to compress\n");  
        exit(0); 
    }
    //strstr func: if ".txt" is found in the character array pointed to by argv[1], then 
    //the address of the first character of the first occurance of that substring in that array will be returned. Else NULL will be returend.  
    if(strstr(argv[1], ".txt") == NULL || strcmp(strstr(argv[1], ".txt"), ".txt") != 0){ 
        printf("Only .txt file format is accepted\n");  
        exit(0); 
    }
    if((*fptr = fopen(argv[1], "r")) == NULL)
    {
        printf("The file entered does not exist\n");
        exit(0);
    }
}
