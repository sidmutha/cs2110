#ifndef FUNC_C_
#define FUNC_C_
int get_order(FILE*);
int** get_matrix_file(FILE*, int);
int determinant(int**, int);
int** findMinor(int**, int, int, int, int**);
int** create_matrix(int);
void free_matrix(int**,int);
#endif 
