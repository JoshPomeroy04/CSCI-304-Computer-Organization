/* By Joshua Pomeroy
 * Simple program to print out 3 different strings.
 * The first string is unchangeable however the second and third
 * string can be changed by changing the numbers in the function call.
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void string_sentance();
void print_difference(int a, int b);
void print_float_division(int a, int b);

// Calls the 3 functions for each output.
int main(void){
    string_sentance();
    print_difference(10, 3);
    print_float_division(1, 3);

    return (EXIT_SUCCESS);
}

// Simple function to just print a specific string
void string_sentance(){
    printf("One half is 50%%\n");
}

// Function that prints the difference of the two given integers
void print_difference(int a, int b){
    int difference = a - b;
    printf("The difference between %d and %d is %d\n", a, b, difference);
}

// Function that does float division on two integers and prints the result
void print_float_division(int a, int b){
    float quotient = (float) a / (float) b;
    printf("%f / %f is %f\n", (float) a, (float) b, quotient);
}