#include<stdio.h>
#include<stdlib.h>

#define MAX 50

typedef struct it {
  char name[MAX];
  int weight;
  int value;
} item;

//declare global variables
item *items;
int max = 0, *fbit_str, max_wt;

//function for binary enumeration of subsets and also calculate the max amt
void enumBinary(int len, int *bit_str,int n){
  if(len==n) {
    int i, val = 0, tot_wt = 0;
    for(i=0;i<n;i++){ /*calculate the value and weight of collection corresponding to the bit string*/
      val += items[i].value * bit_str[i];
      tot_wt += items[i].weight * bit_str[i];
    }      
    if((val > max) && (tot_wt <= max_wt)){ /*compare the current value with the max value and also the total weight with the max weight*/
      max = val;
      for(i = 0; i < n; i++){
	fbit_str[i] = bit_str[i]; /*copy the bit string to a global array*/
      }
    }
  }

  else {
    bit_str[len] = 0;
    enumBinary(len + 1, bit_str, n);
    bit_str[len] = 1;
    enumBinary(len + 1, bit_str, n);    
  }
}

int main(int argc,char **argv){
  int n, i, *b_str;
  FILE *fptr;

  fptr = fopen(argv[1], "r"); /*scan the files and get values*/
  fscanf(fptr, "%d", &max_wt);
  fscanf(fptr, "%d", &n);
  items = malloc(n * sizeof(item)); 
  fbit_str = malloc(n * sizeof(int));
  b_str = malloc(n * sizeof(int));
  for(i = 0; i < n; i++){
    fscanf(fptr, "%s", &items[i].name);
    fscanf(fptr, "%d", &items[i].weight);
    fscanf(fptr, "%d", &items[i].value);  
  }
  enumBinary(1,b_str,n);
  printf("%d",max);
  for(i = 0; i < n; i++){
    if(fbit_str[i] == 1){
      printf(" %s",items[i].name);
    }
  }
  fclose(fptr);
  free(fbit_str);
  free(items);
  free(b_str);
  return 0;
}
