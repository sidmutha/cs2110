/* 
 * File:   main.c
 * Author: sidmutha
 *
 * Created on 30 July, 2012, 2:44 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define LENGTH 20
/*
 * 
 */
int main(int argc, char** argv) {
    float fl;
    int in;
    char ch;
    char str[LENGTH];
    int hexa;
    
    printf("enter float, int, char, str, hex\n");
    //scanf("%f %d %c %20s %x ",&a,&b,&c,&d,&e);
    scanf("%f",&fl);
    scanf("%d",&in);
    getchar();
    scanf("%c",&ch);
    getchar();
    gets(str);
    
    scanf("%x",&hexa);
    
    printf("\nReverse:");
    printf("%x %s %c %d %f",hexa,str,ch,in,fl);
    
    return (EXIT_SUCCESS);
}

