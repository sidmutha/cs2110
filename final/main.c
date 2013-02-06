#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
typedef struct mv {
  char name[20];
  int size;
  int cd;
} movie;

movie *movieArray;
int n, *CD;

void nextFit(){
  int j = 1, i;
  for(i = 0; i < n; i++){
    if(movieArray[i].size <= CD[j]){
      movieArray[i].cd = j;
      CD[j] -= movieArray[i].size;
    }
    else{
      j++;
      movieArray[i].cd = j;
      CD[j] -= movieArray[i].size;
    }
  }
}

void firstFit(){
  int j = 1, i, k;
  for(i = 0; i < n; i++){
    for(k = 1; k <= j; k++){
      if(movieArray[i].size <= CD[k]){
	movieArray[i].cd = k;
	CD[k] -= movieArray[i].size;
	break;
      }
    }
    if(movieArray[i].cd == 0){
	j++;
	movieArray[i].cd = j;
	CD[j] -= movieArray[i].size;
      }
     }
}

void copyAB(movie a, movie b){
  strcpy(a.name, b.name);
  a.size = b.size;
  a.cd = b.cd;
}

void swap(int i, int j){
  movie temp;
  copyAB(temp, movieArray[i]);
  copyAB(movieArray[i], movieArray[j]);
  copyAB(movieArray[j], temp);
}

void selSort(){
  int i, j, max, maxVal;
  for(i = 0; i < n; i++){
    maxVal = movieArray[i].size;
    for(j = i + 1; j < n; j++){
      if(movieArray[j].size > maxVal){
	max = j;
	maxVal = movieArray[j].size;
      }
    }
    swap(i, max);
  }
}

void bestFit(){
  int i, j = 1 , slack, id;
  for(i = 0; i < n; i++){
    slack = 701; id = -1; int k;
    for(k = 1; k <= j; k++){
      if(movieArray[i].size <= CD[k]){
	int s = CD[k] - movieArray[i].size;
	if(slack > s){
	  slack = s;
	  id = k;
	}
      }
    }
  
  if(id == -1){
    j++;
    movieArray[i].cd = j;
    CD[j] -= movieArray[i].size;
  }
  else{
    movieArray[i].cd = id;
    CD[id] -= movieArray[i].size;
  }  
  }
}

int randomize(int a, int b){ //assuming a < b
  int r;
  srand(time(NULL));
  r  = rand();
  return (a + (r % (b - a)));
}
int fact(int num){
  if(num == 0) return 1;
  else return num * fact(num - 1);
}
void randPermute(){
  int i;
  for(i = 0; i < n; i++){
    swap(i, randomize(i, n));
  }  
}
void randBruteForce(){
  int Best = n, i, max;
  do{
    max = 0;
    for(i = 1; i <= 10 * n * n* fact(n); i++){
    randPermute();
    nextFit();
    int j;
    for(j = 0; j < n; j++){
      if(movieArray[i].cd > max){
	max = movieArray[i].cd;
      }
    }
  }
  if(max < Best){
    Best = max;
  }
  }while(max > Best);  
}

int main(int argc, char** argv){
  FILE* fptr;
  int i, totalSize = 0;
  fptr = fopen(argv[2], "r");
  fscanf(fptr, "%d", &n);
  movieArray = malloc(n * sizeof(int));
  
  for(i = 0; i < n; i++){
    fscanf(fptr, "%s", &movieArray[i].name);
    fscanf(fptr, "%d", &movieArray[i].size);
    movieArray[i].cd = 0;
  }
  CD = malloc(n * sizeof(int));
  for(i = 1; i <= n; i++){
    CD[i] = 700;
  }
  
  if(!strcmp(argv[1], "--nf")){
    nextFit();
    printf("Next Fit Algorithm\n");
  }
  else if(!strcmp(argv[1], "--ff")){
    firstFit();
    printf("First Fit Algorithm\n");
  }
  else if(!strcmp(argv[1], "--ffd")){
    selSort();
    firstFit();
    printf("First Fit Decreasing Algorithm\n");
  }
  else if(!strcmp(argv[1], "--bf")){
    bestFit();
    printf("Best Fit Algorithm\n");
  }
  else if(!strcmp(argv[1], "--bfd")){
    selSort();
    bestFit();
    printf("Best Fit Decreasing Algorithm\n");
  }
  else if(!strcmp(argv[1], "--rbf")){
    randBruteForce();
    printf("Randomized Brute Force Algorithm\n");
  }
  
  for(i = 0; i < n; i++){
    printf("%s",movieArray[i].name);
    printf(" : CD%d", movieArray[i].cd);
    printf(" Size : %d\n",movieArray[i].size);
  }
  //selSort();
  return 0; 
}
