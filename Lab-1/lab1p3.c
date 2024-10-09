/* By Joshua Pomeroy
 * Program of a simple cipher. 
 * The simple cipher takes in a file named lab1p3in.txt containing a string to be encoded.
 * This string is encoded by reversing the order of the letters within the string while keeping
 * the order of the words and non-alphabetic characters in place. _ are used to denote spaces in
 * the input file and are replaced with an actual space in the output. The encoded message is
 * put into a file named lab1p3out.txt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void reverse(char *string, int start, int end);
void read_file_to_var(char* var);
void create_output_file(char encoded_message[]);
void reverse_full_string(char *string);

// Calls the 3 necessary functions and holds the variable in which the message is stored.
int main(void){
    char message[100];

    read_file_to_var(message);
    reverse_full_string(message);
    create_output_file(message);

    return EXIT_SUCCESS;
}

// Takes a raw string and reverses it. A raw string is one that contains underscores.
void reverse_full_string(char *string){
    int word_length = 0;
    int starting = 0;
    int str_length = strlen(string);
    char *front_ptr;

    front_ptr = string;

    /* While loop to break up the large string by underscores and other non-alphabetic characters
     * into single words which are then reversed with another function call. Ensures the order
     * of words and non-alpha characters is not changed.
    */  
    while(word_length < str_length){
        if (isalpha(*front_ptr)){
            word_length++;
        } else{
            reverse(string, starting, word_length);
            starting = word_length++;
        }
        front_ptr++;
    }
    reverse(string, starting, word_length);
    
    // Cleans up the result by turning underscores to spaces and making everything all caps
    front_ptr = string;
    for (int i = 0; i < str_length; i++){
        if(*front_ptr == '_'){
            *front_ptr = ' ';
        }
        *front_ptr = toupper(*front_ptr);
        front_ptr++;
    }
}

/* Function that reverses a given section of a larger string.
 * The start and end points of what to reverse are given through
 * start and end. *string is a reference to the large string where a 
 * section will be reversed.
*/
void reverse(char *string, int start, int end){
    int length = end - start;
    char *back_ptr, *front_ptr, temp;
    
    back_ptr = string + end - 1;
    front_ptr = string + start;

    // Swaps the values at the front and back of the given range
    for (int i = 0; i < length/2; i++){
        // Skips characters that are non-alphabetic
        if (!isalpha(*front_ptr)){
            front_ptr++;
        }

        if (!isalpha(*back_ptr)){
            back_ptr--;
        }

        temp = *front_ptr;
        *front_ptr = *back_ptr;
        *back_ptr = temp;

        front_ptr++;
        back_ptr--;
    }
}

// Function to read in the file lab1p3in.txt and put its contents into the provided variable
void read_file_to_var(char* var){
    FILE* file_ptr = fopen("lab1p3in.txt", "r");

    if (file_ptr == NULL){
        printf("Could not open file.\n");
        exit(1);
    }
    fscanf(file_ptr, "%s", var);
    fclose(file_ptr);
}

// Function to write the provided string to the output file and create the output file if it does not already exist
void create_output_file(char encoded_message[]){
    FILE* file_ptr = fopen("./lab1p3out.txt", "w");

    if (file_ptr == NULL){
        printf("Could not create file.\n");
        exit(1);
    }

    fputs(encoded_message, file_ptr);
    fclose(file_ptr);
}