/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Description: 
 *                                                                             *
 * Written by *** for COMP9021                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *const input_file = fopen("input.txt", "r");
    if (!input_file) {
        printf("Please create a file named \"input.txt\""
               " in the working directory.\n");
        return EXIT_FAILURE;
    }
    FILE *const output_file = fopen("output.txt", "w");
    /* REPLACE THIS COMMENT WITH YOUR CODE */
    fclose(input_file);
    fclose(output_file);
    return EXIT_SUCCESS;
}
