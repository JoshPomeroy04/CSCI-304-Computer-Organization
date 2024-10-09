/* By Joshua Pomeroy
 * Simple program for input practice. The user is asked three different prompts,
 * entering 2 integers to be added, entering 2 floats to be multiplied, and entering a word
 * to be printed twice.
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void integer_addition();
void float_multiplication();
void duplicate_word();

// Calls the 3 functions for each prompt
int main(void){
    integer_addition();
    float_multiplication();
    duplicate_word();

    return EXIT_SUCCESS;
}

// Asks the user for two integers and prints out the sum of them
void integer_addition(){
    int first, second;
    printf("Give two integers: ");
    scanf("%d %d", &first, &second);
    printf("You entered %d and %d, their sum is: %d\n", first, second, first+second);
}

// Asks the user for two flots and prints out the product of them
void float_multiplication(){
    float first, second;
    printf("Give two floats: ");
    scanf("%f %f", &first, &second);
    printf("You entered %f and %f, their product is: %f\n", first, second, first*second);
}

// Asks the user for a word and prints out that word twice
void duplicate_word(){
    char word_input[100];
    printf("Give a word: ");
    scanf("%s", word_input);
    printf("%s %s\n", word_input, word_input);
}