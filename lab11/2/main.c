//currently the program only works for S = {0, 1}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char** argv){
  int n, *gen, *arr_2, *bin_arr, num, num1 ,nn,  i;
  FILE *fptr;
  fptr = fopen(argv[1], "r");
  fscanf(fptr, "%d", &n);
  gen = malloc(n * sizeof(int)); // gen = generator set
  
  for(i = 0; i < n; i++){
    fscanf(fptr, "%d", &gen[i]);
  }
  fscanf(fptr, "%d", &num);
  arr_2 = malloc((nn = (int)(1 + log2(num)))*sizeof(int));
  bin_arr = malloc(nn * sizeof(int));
  num1 = num;
  i = 0;
  while(num1 != 0){
    arr_2[i] = num1%2;
    i++;
    num1 = num1/2;
  }
  bin_arr[0] = 1;
  for(i = 1; i < nn; i++){
    bin_arr[i] = bin_arr[i - 1] * 2;
    printf("%d + %d = %d\n", bin_arr[i - 1], bin_arr[i - 1], bin_arr[i]);
  }
  
  for(i = 0; i < nn; i++){
    if(arr_2[i] == 1){
     	printf("%d ", bin_arr[i]);
	
	if(i != nn - 1){
	  printf("+ ");
	}
    }
  }
  printf("= %d\n", num);
  int sum1 = 0;
  for(i = 0; i < nn - 1; i++){
    if(arr_2[i] == 1) sum1 += 1; 
  }

    printf("No. of '+' = %d\n", nn - 1 + sum1);
 
}
