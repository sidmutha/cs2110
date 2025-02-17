#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include"func.c"

int main(int argc, char **argv){
  FILE *fptr;
  int i,j, n, **matrix, det, **mino;
  fptr = fopen(argv[1],"r");
  n = get_order(fptr);
  matrix = get_matrix_file(fptr, n);
  for(j = 0; j < n; j++){//print the matrix
    for(i = 0; i < n; i++){
      printf("%d ", matrix[j][i]);
      
    }
    printf("\n");  
  }
  
  det = determinant(matrix, n);
  printf("Determinant: %d\n", det);
  free_matrix(matrix, n);
  fclose(fptr);
  return 0;
}
