/* 
 * File:   main.c
 * Author: sid
 *
 * Created on 5 August, 2012, 11:57 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char* clean_str(char str[]) { //function to clean the string. remove the non-alphabetic char and convert to small case
    int i;
    int len = strlen(str);
    for (i = 0; i < len; i++) {
        if (str[i] >= 65 && str[i] <= 90) str[i] += 32;
        else if (str[i] >= 97 && str[i] <= 122) {
        } else {
            int j;

            for (j = i + 1; j < len - 1; j++) {
                char temp;
                temp = str[j];
                str[j] = str [j + 1];
                str[j - 1] = temp;
                
            }
            i--;
            len--;
        }
    }
    str[len] = '\0';
    return str;
}

int check_if_palindrome(char str[]) { //func to check palindrome
    int len = strlen(str);
    int i, a = 1;
    for (i = 0; i <= len / 2; i++) {
        if (str[i] == str[len - i - 1]) a *= 1;
        else {
            a *= 0;
            break;
        }
    }
    return a;
}

int main(int argc, char** argv) {
    char my_str[100], *cStr;
    int result;
    printf("Enter a string (max len = 100):\n");
    gets(my_str);
    cStr = clean_str(my_str);
    //puts(cStr);
    printf("%d", strlen(cStr));
    result = check_if_palindrome(cStr);
    printf("\nResult: %d", result);

    return (EXIT_SUCCESS);
}

