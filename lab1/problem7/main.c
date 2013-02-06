/* 
 * File:   main.c
 * Author: sid
 *
 * Created on 5 August, 2012, 8:20 PM
 */

#include <stdio.h>
#include <stdlib.h>
//recursive algo for reversing string
//take the string, its len, and the begining position
//then swap the elements corresp to the position
//and then request recursively for swapping elements at pos-1
//till you reach the middle of the str
//finally return the str
char* invert_str(char str[], int len, int pos) {
    if (pos == len / 2) return str;
    else {
        char tmp;
        tmp = str[pos - 1];
        str[pos - 1] = str[len - pos];
        str[len - pos] = tmp;
        return (invert_str(str, len, pos - 1));
    }
}

int main(int argc, char** argv) {
    char my_str[100];
    //my_str = (char*)malloc(100*sizeof(char));
    gets(my_str);
    puts(invert_str(my_str, strlen(my_str), strlen(my_str)));
    return (EXIT_SUCCESS);
}

