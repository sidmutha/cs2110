/* 
 * File:   main.c
 * Author: sidmutha
 *
 * Created on 30 July, 2012, 4:29 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int GCD(int a, int b) {

    if (a > b) return GCD(a - b, b);
    else if (a < b) return GCD(a, b - a);
    else if (a == b) return a;

}

int main(int argc, char** argv) {
    int num1, num2, gcd;

    printf("Enter num1 and num2: ");
    scanf("%d %d", &num1, &num2);
    if (num1 > 0 && num2 > 0) {
        gcd = GCD(num1, num2);
        printf("\nGCD:%d \nLCM:%d", gcd, (num1 * num2 / gcd));
    } else printf("Error. Check your values.");
    return (EXIT_SUCCESS);
}

