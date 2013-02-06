/* 
 * File:   main.c
 * Author: sidmutha
 *
 * Created on 30 July, 2012, 5:02 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int i, j, k, size;
    char a = 'A';

    printf("Enter no of alphabets:");
    scanf("%d", &size);
    
    for (i = 0; i <= (size - 1); i++) { //for the first line
        printf("%c", (a + i));
    }
    for (i = 0; i <= (size - 2); i++) { //first line reverse part
        printf("%c", (a + size - 2 - i));
    }

    for (j = 1; j <= size - 1; j++) { //for rest of the lines
        printf("\n");
        for (k = 0; k <= size - j - 1; k++) { //for the first part
            printf("%c", (a + k));
        }
        for (k = 1; k <= (2 * j - 1); k++) { //for the spaces
            printf(" ");
        }
        for (k = 0; k <= size - 1 - j; k++) { //for the reverse part
            printf("%c", (a + size - 1 - k - j));
        }

    }

    return (EXIT_SUCCESS);
}

