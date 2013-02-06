#include<stdio.h>
#include<stdlib.h>

#define MAX 10
typedef struct it {
  char name[MAX];
  int weight;
  int value;
} item;

int* enumBinary(int len, int* bit_str, n){
  if(len==n) return bit_str;
  else {
    bit_str[len] = 0;
    enumBinary(len + 1, bit_str, n);
    bit_str[len] = 1;
    enumBinary(len + 1, bit_str, n);

  }
}
