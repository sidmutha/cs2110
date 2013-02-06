#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include "func.h"
//read order of matrix from file
int get_order(FILE *fptr){
  int n;
  fscanf(fptr, "%d", &n);
  return n;
}

//read the array
int **get_matrix_file(FILE *fptr, int n){
  int i = 0, j, el;
  int** matrix;
  matrix = create_matrix(n);
  for(j = 0; j < n; j++){
    for(i = 0; i < n; i++){
      fscanf(fptr, "%d", &el);
      matrix[j][i] = el;
    }
  }
  return matrix;
}

int dell(int i){
  if ((i%2) == 0) return 1;
  else return (-1);
}
//function to calculate the determinant
int determinant(int** matrix, int n){
  int val = 0, i, **mat ;
  if(n==1){
    return matrix[0][0];
  }
  else{
    for(i=0;i < n;i++){
      if(matrix[0][i]==0)continue;
      else {
	mat = create_matrix(n-1);
	val += dell(i) *  matrix[0][i] * determinant(findMinor(matrix,0, i, n-1,mat), n -1);
	free_matrix(mat, n - 1);
      }
    }
    return val;
  }

}



//function to create the minor of the given element of the matrix of order n1
int **findMinor (int** matrix, int x, int y, int n1, int **out_matrix){
  int  i, j, k = 0, l = 0;
  for(j=0; j <= n1; j++){
    if(j != x){
      k=0;
      for(i=0; i <= n1; i++){
	if(i != y){
	  out_matrix[l][k] = matrix[j][i];
	  k++;
	}
	else continue;
      }
      l++;
    }
    else continue;
  }
  return out_matrix;
}

//function to create a square matrix of order n
int** create_matrix(int n){
  int **matrix, i;
  matrix = malloc(n * sizeof(int*)); //allocate memory to array of int* for 2d array
  //loop to allocate memory to each int* in array
  for(i=0; i<n; i++){
    matrix[i] = malloc(n * sizeof(int)); 
  }
  return matrix;
}

//function to free the memory of a matrix
void free_matrix(int** matrix,int n){
  int i;
  for(i = 0; i < n; i++){
    free(matrix[i]);
  }
  free(matrix);
}
