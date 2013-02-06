#include<stdio.h>
#include<stdlib.h>

typedef struct nd{
  int colour; //colour :- 0:blue, 1: red, 2:none
  int *nbr;
  } node;

int bipartite = 1, cyclic = 0, n, *matrix, counter = 1;
node *Node; 

int* createMatrix(int n){
  int *matrix = calloc(n * n, sizeof(int));
  return matrix;
}

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
      matrix[i + n * j] = matrix[j + n * i] = (matrix[i + n * j] || matrix[j + n * i]);
    }
  }
}
/*
void someFunction(int i){
  int j;
  for(j=0; j<n; j++){
    if(matrix[i + n*j] == 1){
      if(colorArray[j] == 2){
	colorArray[j] = !colorArray[i];
	}
      else{
	bipartite = 0;
	
      }
    }
  }
}

*/

void runDFS(int i, int c){ //i = current node to check, c = from where the pointer has come
  int k; 
  for(k = 0; k < n; k++){ //run the loop for every neighbour
    if(k != c){ // skip itself
      if(Node[i].nbr[k] == 1){ //if there is an edge then go ahead
	if(Node[k].colour == 2){ //if uncoloured, colour it with the opposite parity
	  if(Node[i].colour == 0) Node[k].colour = 1;
	  else Node[k].colour = 0;
	  runDFS(k, i); //since it was uncoloured, we now shift our pointer to the next one
	  counter++; //since we have discovered a new (amd unconnected vertex, counter increases
	}
	else{
	  cyclic = 1; //if the next vertex is already coloured, it is also visited, hence cyclic graph
	  if(Node[k].colour == Node[i].colour){
	    bipartite = 0; //if the neighbour is of the same colour, two colouring is not possible and so it is not bipartite
	  }
	}  
      }
    }
  }
}

void decolour(){
  int i = 0;
  for(i = 0; i < n; i++) {
    Node[i].colour = 2;
    Node[i].nbr;//10
  }
}
int main(int argc, char **argv) {
  int  i, j, k;
  FILE* fptr;
  fptr = fopen(argv[1], "r");
  fscanf(fptr,"%d",&n);
  
  Node = calloc(n, sizeof(node)); //declare node array
  decolour(); //set all colours to 2 (no colour)
  matrix = createMatrix(n);
  
  //scan file
  for(i = 0; i < n * n; i++) {
    fscanf(fptr, "%d", &matrix[i]);
  }
  fclose(fptr);
  
  makeSymmetric(matrix, n);
  
  //assign neighbours
  for(j = 0; j < n; j++) {
    Node[j].nbr = calloc(n, sizeof(int));
    for(k = 0; k < n; k++) {
      Node[j].nbr[k] = matrix[k + n*j];
    }
  }
  
  printMatrix(matrix, n);
  
  //running DFS now beginning from every vertex
  for(i=0; i<n; i++){
    counter = 1; //set visited counter to 1
    decolour(); //decolour all
    Node[i].colour = 0; 
    runDFS(i, -1);  
  }
  
  if(cyclic == 1) printf("Cyclic\n");
  else printf("Not Cyclic\n");
  
  if(counter != n){
    printf("Not Connected\n");
    printf("Not Tree\n");
  } 
  else{
    printf("Connected\n");
    if(cyclic == 0) printf("Tree\n");
    else printf("Not Tree\n");
  }
  
  if(bipartite == 1) printf("Bipartite\n");
  else printf("Not Bipartite\n");
    
  free(matrix);
  free(Node);
  
  return 0;
}
