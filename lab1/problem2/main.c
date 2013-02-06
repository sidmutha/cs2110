/* 
 * File:   main.c
 * Author: sidmutha
 *
 * Created on 30 July, 2012, 3:42 PM
 */

#include <stdio.h>
#include <stdlib.h>

/* add nos. below N which are multiples of X,Y
 * 
 */
int main(int argc, char** argv) {
    int i, sum = 0, n, x, y;
    
    printf("Enter N, X, Y:\n");
    scanf("%d %d %d", &n, &x, &y);
    
    for (i = 1; i < n; i++) {
        if ((i % x == 0 && i % y != 0) || (i % x != 0 && i % y == 0) || (i % x == 0 && i % y == 0)) {
            sum += i;
        }
    }
    
    printf("Sum: %d", sum);
    
    return (EXIT_SUCCESS);
}

