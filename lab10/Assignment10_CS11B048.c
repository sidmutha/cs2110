/*
maximum cut problem
Algo: 
  Begin with the vertex of the largest degree, put it into setA and all of its neighbours into setB
  Now, from the remaining vertices, select the one with the largest degree. Check the number of neighbours in A and B. Assign this vertex to the set with less no of neighbours.
  Iterate for all.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct nd{
  int deg, set; //setA -> 0; setB -> 1; unassigned -> 2
  int* nbr;
} node;

int n, *matrix;
node* Nodes;

void printMatrix(){
  int i, j;
  for(j = 0; j < n; j++){
    for(i = 0; i < n; i++){
      printf("%d ", matrix[i + n*j]);
    }
    printf("\n");
  }
}

void makeSymmetric(){
  int i, j;
  for(i = 0; i < n; i++){
    for(j = i; j < n; j++){ //optimisation!
      if(i != j){
      matrix[i + n * j] = matrix[j + n * i] = (matrix[i + n * j] || matrix[j + n * i]);
      }
      else{
	matrix[i + n * j] = 0; //remove self loops (no use)
      }
    }
  }
}

int* createMatrix(int n){
  int *matrix = calloc(n * n, sizeof(int));
  return matrix;
}

int findNextMaxDegNode(){
  int i, max = 0, ind = -1;
  for(i = 0; i < n; i++){
    if(Nodes[i].set == 2){
      if(Nodes[i].deg >= max){
	ind = i;
      }
    }
  }
  return ind; //returns -1 if there are no more vertices left to be assigned
}

void assignSet(int vert){
   int a = 0, b = 0, c, d, i;
  if(Nodes[vert].deg != 0){
    //counting the number of nbrs in set A, B
    for(i = 0; i < n; i++){
      if(Nodes[vert].nbr[i] == 1){
	if(Nodes[i].set == 0) a++;
	else if(Nodes[i].set == 1) b++;
      }
    }
    //  printf("a: %d b:%d\n",a, b);
    if(a >= b) {
      c = 0;
      d = 1;
    }
    else {
      c = 1;
      d = 0;
    }
    Nodes[vert].set = d; //if say N(A) >= N(B), vert is then asssigned set B 
      }
  else {
    Nodes[vert].set = 0; //if degree(v) == 0, v is assigned to A
  }
}

int main(int argc, char** argv){
  FILE* fptr;
  int maxDegNode, i, j, k, bridge = 0;
  fptr = fopen(argv[1], "r");
  fscanf(fptr,"%d",&n);
  
  Nodes = calloc(n, sizeof(node));
  matrix = createMatrix(n);
    
  for(i = 0; i < n * n; i++) {
    fscanf(fptr, "%d", &matrix[i]);
  }
  fclose(fptr);
    
  makeSymmetric(matrix, n);
  printMatrix();
  
  //assigning degrees and set to the nodes
  for(j = 0; j < n; j++) {
    Nodes[j].deg = 0;
    Nodes[j].nbr = calloc(n, sizeof(int));
    Nodes[j].set = 2;
    for(k = 0; k < n; k++) {
      Nodes[j].nbr[k] = matrix[k + n*j];
      if(Nodes[j].nbr[k] == 1){
	  Nodes[j].deg++;
	}
      }
    }
  free(matrix);  
  while((maxDegNode = findNextMaxDegNode()) != -1){
    assignSet(maxDegNode);
  }    
 
  for(i = 0; i < n; i++){
    printf("%d\n", Nodes[i].deg);
  }
  
  //printing the final results with the list of bridge edges
  for(i = 0; i < n; i++){
    for(j = i; j < n; j++){
      if(Nodes[i].nbr[j] == 1){
	if(Nodes[j].set != Nodes[i].set){
	  printf("(%d, %d)\n", i, j);
	  bridge++;
	}
      }
    }
  }
  
  printf("No. of Bridges: %d\n", bridge);
  
  return 0;
}
