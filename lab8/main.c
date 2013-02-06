#include<stdio.h>
#include<stdlib.h>

//create a 1-D n*n array
int* createMatrix(int n){
  int *matrix = calloc(n * n, sizeof(int));
  return matrix;
}

void printMatrix(int* matrix, int n){
  int i, j;
  for(j = 0; j < n; j++){
    for(i = 0; i < n; i++){
      printf("%d ", matrix[i + n*j]);
    }
    printf("\n");
  }
}

//Warshall's Algorithm
int* runWarshall(int* matrix, int n){
  int i, j, k;
  for(k = 0; k < n; k++){
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
	matrix[i + n*j] = (matrix[i + n*j]) || (matrix[i + n*k] && matrix[k + n*j]);
      }
    }
  }
  return matrix;
}

int checkReflexive(int* matrix, int n){
  int i, a = 1;
  for(i = 0; i < n; i++){
    if(matrix[i*(n+1)] != 1){ //if m[ii] == 1
      a = 0;
      break;
    }
  }
  if (a==0) printf("\nNot Reflexive");
  return a;
}

int checkSymmetric(int *matrix, int n){
  int i, j, a = 1;
  for(i = 0; i < n; i++){
    for(j = i; j < n; j++){ //optimisation!
      if(matrix[i + n * j] != matrix[j + n * i]){ //if m[ij]=/=m[ji] then exit
	a = 0;
	break;
      }
    }
  }
  if (a==0) printf("\nNot Symmetric\n");
  return a;
}

int checkTransitive(int* matrix, int n){
  int i, j, k, a = 1;
    for(j = 0; j < n; j++){
    for(i = 0; i < n; i++){
      for(k = 0; k < n; k++){
	if(((matrix[i + n*k])&&(matrix[k + j*n]))&&(matrix[i + n*j] != 1)){ // !(m[ik]&&m[kj]-->m[ij]) == m[ik]&&m[kj]&&(!m[ij])
	  a = 0;
	  break;
	}
	/*else{
	  
	  
	  
	    //assigning classes
	  if(!classMatrix[i + n*k] && !classMatrix[k + j*n] && !classMatrix[i + n*j]){//000
	    classNum++;
	    classMatrix[i + n*k] = classMatrix[k + j*n] = classMatrix[i + n*j] = classNum;
	  }
	  else if(!classMatrix[i + n*k] && !classMatrix[k + j*n] && classMatrix[i + n*j]){//001
	    classMatrix[i + k*n] = classMatrix[k + n*j] = classMatrix[i + n*j];
	  }
	  else if(!classMatrix[i + n*k] && classMatrix[k + j*n] && !classMatrix[i + n*j]){//010
	    classMatrix[i + k*n] = classMatrix[i + n*j] = classMatrix[k + n*j];
	  }
	  else if(!classMatrix[i + n*k] && classMatrix[k + j*n] && classMatrix[i + n*j]){//011
	    classMatrix[i + n*k] = classMatrix[i + n*j];
	  }
	  else if(classMatrix[i + n*k] && !classMatrix[k + j*n] && !classMatrix[i + n*j]){//100
	    classMatrix[k + j*n] = classMatrix[i + n*j] = classMatrix[i + n*k];
	  }
	  else if(classMatrix[i + n*k] && !classMatrix[k + j*n] && classMatrix[i + n*j]){//101
	    classMatrix[k + j*n] = classMatrix[i + n*j];
	  }
	  else if(classMatrix[i + n*k] && classMatrix[k + j*n] && !classMatrix[i + n*j]){//110
	    classMatrix[i + n*j] = classMatrix[i + n*k];
	  }
	  else if(classMatrix[i + n*k] && classMatrix[k + j*n] && classMatrix[i + n*j]){//111
	    //do nothing! all are set
	    }
	}*/
      }
    }
  }
    if (a==0){
      printf("\nNot transitive\nTransitive closure:\n");
      printMatrix(runWarshall(matrix, n), n);
} 
 else{
    int* classArray = calloc(n, sizeof(int));
    int i, j, classNum = 0;
    for(i=0; i<n; i++){
      if(classArray[i] == 0){
	classNum++;
	for(j=0;j<n;j++){
	  if(matrix[i + n*j] == 1){
	    classArray[j] = classNum;
	    
	  }
	}
      }
      
    }
    printf("\nEquivalence Classes(in the order of veritices): "); 
    for(i=0;i<n;i++){
      printf("%d ",classArray[i]);
    }
  }
  return a;
}

int checkAntiSymmetric(int* matrix, int n){
  int i, j, a = 1;
  for(j = 0; j < n; j++){
    for(i = j; i < n; i++){ //optimisation!
      if(i != j){ 
	if(matrix[i + n * j] == matrix[j + n * i] == 1){ //if (i =/= j) and (m[ij] == m[ji] == 1)
	  a = 0;
	  break;	
	}
      }
    }
  }
  if (a==0) printf("\nNot AntiSymmetric\n");
  return a;
}

int checkEquivalence(int* matrix, int n){
  int a = 0;
  if(checkReflexive(matrix, n)){
    if(checkSymmetric(matrix, n)){
      if(checkTransitive(matrix, n)){
	a = 1;
      }
    }
  }
  if (a==0) printf("\nNot Equivalence\n");
  return a;
}

int checkPartialOrder(int* matrix, int n){
  int a = 0;
  if(checkReflexive(matrix, n)){
    if(checkAntiSymmetric(matrix, n)){
      if(checkTransitive(matrix, n)){
	a = 1;
      }
    }
  }
  return a;
  if (a==0) printf("\nNot Partial Ordering\n");
}


int main(int argc, char** argv){
  FILE *fptr;
  int *matrix, n, i, j;
  
  //read file
  fptr = fopen(argv[1], "r");
  fscanf(fptr, "%d", &n);
  matrix = createMatrix(n);
  for(i = 0; i < n * n; i++){
    fscanf(fptr, "%d", &matrix[i]);
  }
  fclose(fptr);
  printMatrix(matrix, n);
   
  if(checkEquivalence(matrix, n)){
    printf("\nEquivalence Relation!\n");
  }

  if(checkPartialOrder(matrix, n)){
    printf("Partial Ordering!\n");
  }
  else printf("Not Partial Ordering\n");
  return 0;
}
