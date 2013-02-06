/* 
 * File:   main.c
 * Author: sid
 *
 * Created on 5 August, 2012, 7:17 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*compute nCr
 * 
 */
int C(int n, int r){
    if(n==r)return 1; //base cases for recursive func
    else if(r==1) return n;
    else if(r==0) return 1;
    else return (C(n-1,r)+C(n-1,r-1));    
}

int main(int argc, char** argv) {
    int n,r;
    printf("Compute nCr");
    printf("\nEnter n and r: ");
    scanf("%d %d",&n,&r);
    if (n<r || n<0) printf("\nPlease check your values.");
    else printf("\nAns: %d",C(n,r));
    return (EXIT_SUCCESS);
}

