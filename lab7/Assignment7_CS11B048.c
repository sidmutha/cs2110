#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct pt{
  int x;
  int y;
} point;

//declarations
float pi = 3.141592;
int *sel_array, *sel_list_array, curSel = 0, len, rightmostX, direction;
point* pt_array;

float slope(point pt1, point pt2){
  float m;
  m = (pt1.y - pt2.y)/(pt1.x - pt2.x);
  return m;
}
//quicksort (works)
point *quicksort(point* array, int len){
  if (len <= 1) return array;
  else {
    point *arr_low, *arr_high;
    int i,l=0,h=0, mid = len/2;
    point pivot; 
    arr_low = malloc(len * sizeof(point));
    arr_high = malloc(len * sizeof(point));
    pivot = array[mid];
    for(i=0;i<len;i++){
      if(i!=mid){
	if(array[i].x <= pivot.x){
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
//mergesort (not working)
point* mergesort(point* pt_array, int len){
  if(len==1){
    return pt_array;
  }
  else{
    point *ar1, *ar2;
    int i, j;
    ar1 = malloc((len/2) * sizeof(point));
    ar2 = malloc((len - len/2) * sizeof(point));
    for(i = 0; i < len/2; i++){
      ar1[i] = pt_array[i];
    }
    for( j = 0; i < len; i++, j++){
      ar2[j] = pt_array[i];
    }
    ar1 = mergesort(ar1, len/2);
    ar2 = mergesort(ar2, len - len/2);
    for(i = 0; i < len; i++){}

    int k1 = 0, k2 = 0;
    if(ar1[k1].x <= ar2[k2].x){
      pt_array[i] = ar1[k1];
      k1++;
    }
    else{
      pt_array[i] = ar2[k2];
      k2++;
    }
    //free(ar1);
    //free(ar2);
    return pt_array;
  }
}

/*
  float lValue(float m, point pt1, point pt2){
  float val = (pt1.y - pt2.y) - (m * (pt1.x - pt2.x));
  return val;
  }

  point findNext(point currPoint){
  int i, j, k, a = 1;
  float m, val1, val2;
  for(i = 0; i < len; i++){
  if(pt_array[i].x == rightmostX){
  sel_array[i] = 1;
  return pt_array[i];
  }
  else{
  m = slope(currPoint, pt_array[i]);
  for(j = 0; j < len; j++){
  if(a == 1){
  for(k = 0; k < len; k++){
  val1 = lValue(m, currPoint, pt_array[j]);
  val2 = lValue(m, currPoint, pt_array[k]);
  if(val1 * val2 > 0){
  a = a*1; 
  }
  else{
  a = 0;
	 	
  }
  }
  }
  }
  if(a == 1){
  sel_array[i] = 1;
  return pt_array[i];
  }
  else continue;
  }
  }
  }
*/

//find the next point for the fence
int find_next(int curr_pt){
  float max_slope = (-1) * pi;
  int i, k;
  if(direction == 0){
    for(i = curr_pt + 1; i < len; i++){
      if(sel_array[i] != 1){
	if(pt_array[i].x == rightmostX && pt_array[i].x == pt_array[curr_pt].x){
	  k = i;
	  sel_array[k] = 1;
	  direction = 1;
	  return k;
	}
	else{
	  float sl_atan;
	  sl_atan = atanf(slope(pt_array[curr_pt], pt_array[i]));
	  if(sl_atan > max_slope){
	    max_slope = sl_atan;
	    k = i;
	    if(pt_array[k].x == rightmostX) direction = 1;
	  }
	}
      }
      else continue;
    }
  }
  else{
    /* if((pt_array[curr_pt].x == rightmostX) && !(pt_array[curr_pt - 1].x == rightmostX)){
      max_slope = atanf(slope(pt_array[curr_pt], pt_array[curr_pt - 1]));
      k = curr_pt - 1;
      }*/
    max_slope = (-1) * pi;
      for(i = curr_pt - 1; i >= 0; i--){
	if(sel_array[i] != 1){
	  if(pt_array[i].x == rightmostX  && pt_array[i].x == pt_array[curr_pt].x){
	    k = i;
	    sel_array[k] = 1;
	    direction = 1;
	    return k;
	  }
	  else{
	    float sl_atan;
	    sl_atan = atanf(slope(pt_array[curr_pt], pt_array[i]));
	    if(sl_atan > max_slope){
	      max_slope = sl_atan;
	      k = i;
	      if(pt_array[k].x == rightmostX) direction = 1;
	    }
	  }
	}
	else continue;
      } 
    }
    sel_array[k] = 1;
    return k;
  }

  int main(int argc, char **argv){
  
    /*get the data from the file into an array of points in pt_array, length = len, sel_array, sel_list_array and its length also */
    
    FILE* fptr = fopen(argv[1], "r");
    char buff[10];
  
    fscanf(fptr,"%s",&buff);
    fscanf(fptr,"%s",&buff);

    int l = 0, i = 0, cur = 0;

    do{
      pt_array = malloc(10 * sizeof(point));
      sel_array = malloc(10 * sizeof(int));
      sel_list_array = malloc( 10 * sizeof(int));
      int s;
      for( s = 0; s < 10; s++){
	sel_array[s] = 0;
	 
      }
      do{
	//realloc(pt_array, ((l + 1) * sizeof(point)));
	//realloc(sel_array, ((l + 1) * sizeof(int)));
	//realloc(sel_list_array, ((l + 1) * sizeof(int)));
	if(strcmp("NewCase", buff) != 0){
	  pt_array[l].x = atoi(buff);
	}
	else {
	  fscanf(fptr, "%s", &buff);
	  pt_array[l].x = atoi(buff);
	} 
	 
	fscanf(fptr, "%s", &buff);
	pt_array[l].y = atoi(buff);
	fscanf(fptr, "%s", &buff);
	 
	l++;
      }while(((strcmp("NewCase", buff) != 0) && (strcmp("TheEnd", buff) != 0))/**/);
	
      len = l;
      pt_array = quicksort(pt_array, len);
      rightmostX = pt_array[len-1].x;
      direction = 0;//top
      i = cur = 0; 
      do{
	cur = find_next(cur);
	sel_list_array[curSel] = cur;
	curSel++;
      }while(cur != 0);
	
      for(i = 0; i < curSel; i++){
	printf("%d %d ", pt_array[sel_list_array[i]].x, pt_array[sel_list_array[i]].y);
      }
      printf("\n");
      free(sel_array);
      free(sel_list_array);
      curSel = 0;
      free(pt_array);
      l = 0;
    }while(strcmp("TheEnd", buff) != 0);
    return 0;  
  }
