#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

typedef struct it {
  char name[MAX];
  int weight;
  int value;
  float wv;
} item;

//declare global variables
item *items;
int max = 0, *fbit_str, max_wt,*fbit_str_gr, *fgr_bstr ;

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
//recursive quicksort function (descending order)
item *quicksort(item* array, int len){
  if (len <= 1) return array;
  else {
    item *arr_low, *arr_high;
    int i,l=0,h=0, mid = len/2;
    item pivot; 
    arr_low = malloc(len * sizeof(item));
    arr_high = malloc(len * sizeof(item));
    pivot = array[mid];
    for(i=0;i<len;i++){
      if(i!=mid){
	if(array[i].wv <= pivot.wv){
	  arr_low[l] = array[i];
	  l++;
	} 
	else {
	  arr_high[h] = array[i];
	  h++;	
	}
      }
    }
    arr_low = quicksort(arr_low, l);
    arr_high = quicksort(arr_high, h);
   
    for(i = 0; i < l; i++){
      array[i] = arr_low[i];
    }
    array[l] = pivot;
    
    for(i = 0;i < h; i++){
      array[l + i + 1] = arr_high[i];
    }
     
  }
  return array;
}
//greedy algo to maximize value. returns the maximized value
int gr_maximize(int max_w, item* list, int n){
  int i, c_w = max_w, c_v = 0;
  for(i=0;i<n;i++){
    if(list[i].weight <= (float)c_w){
      c_w -= list[i].weight;
      fbit_str_gr[i] = 1;
      c_v += list[i].value;
    }
    else fbit_str_gr[i] = 0;
  }
  return c_v;
}

int main(int argc, char **argv){
  int n, i, *b_str, num_files;
  FILE *fptr;
  char *fstrpre;
  num_files = atoi(argv[1]);
  //for each file of the form "<fstrpre>_<1,2,3,....>.txt" run the whole optimization
  for(i=1;i<=num_files;i++){
    char* fname = malloc(strlen(argv[2]) + 2); //this will be the final name of a file to opened after concatenation
    int j, gr_max;    
    sprintf(fname,"%s_%d.txt",argv[2],i);//concatenation of strings
    fptr = fopen(fname,"r");
    fscanf(fptr, "%d", &max_wt);
    fscanf(fptr, "%d", &n);
    
    items = malloc(n * sizeof(item)); 
    fbit_str = malloc(n * sizeof(int));
    fbit_str_gr = malloc(n * sizeof(int));
    fgr_bstr = malloc(n * sizeof(int));
    b_str = malloc(n * sizeof(int));
  
    //for loop below will parse the txt file and get all the values
    for(j = 0; j < n; j++){
      fscanf(fptr, "%s", &items[j].name);
      fscanf(fptr, "%d", &items[j].weight);
      fscanf(fptr, "%d", &items[j].value);  
      items[j].wv = ((float)items[j].weight)/((float)items[j].value);
  
    }
    enumBinary(0,b_str,n); //brute force
   
    //begin: print out the result in the specified format
    printf("%d",max);
    for(j = 0; j < n; j++){
      if(fbit_str[j] == 1){
	printf(" %s",items[j].name);
      }
    }
    //sort list1
    items = quicksort(items, n);
    
    //the optimization begins!
    gr_max = gr_maximize(max_wt,items,n); //greedy(!) algo
     
    printf(" : ");
    printf("%d",gr_max);
    for(j = 0; j < n; j++){
      if(fbit_str_gr[j] == 1){
	printf(" %s",items[j].name);
      }
    }
    printf("\n");  
    fclose(fptr);
    free(items);
    free(fgr_bstr);
    free(fbit_str_gr);
    free(fbit_str);
    free(b_str);
    max = 0;
  }
  return 0;
}

