/* 
 * File:   main.c
 * Author: sidmutha
 *
 * Created on 30 July, 2012, 4:01 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* power of 2 nearest to N
 * 
 */
int main(int argc, char** argv) {

    int n, d;

    printf("Enter N: ");
    scanf("%d", &n);

    d = floor(log2(n));
    
    printf("\nvalue of d+1 is: %d",(d+1));
    
    return (EXIT_SUCCESS);
}

