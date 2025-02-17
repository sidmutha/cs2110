#include<stdio.h>
#include<stdlib.h>
#include "list.c"
#include "fileop.c"

int main(int argc, char **argv){
  FILE *file1, *file2, *file_out;
  word_item *head1 = NULL,* head2 = NULL, *i_head = NULL;
  int n1, n2,n_i, n_u;
  float s;
  
  file1 = fopen(argv[1],"r");
  file2 = fopen(argv[2],"r");
  if(file1 == NULL || file2 == NULL){
    printf("Sorry, file(s) not found\n");
  }
  else {
    head1 = create_list();
    head2 = create_list();
    find_and_add(file1, head1);
    find_and_add(file2, head2);
    //print_all(head1);
    //print_all(head2);
    i_head = i_list(head1, head2);
    n1 = count(head1);
    n2 = count(head2);
    n_i = count(i_head);
    n_u = n1 + n2 - n_i;
    s = (float)n_i/(float)n_u;
    file_out = fopen("output.txt", "w");
    fprintf(file_out, "I:%d U:%d S:%f\n",n_i, n_u, s);
    printf("I:%d U:%d S:%f\n",n_i, n_u, s);
    write_to_file(i_head, file_out);
    free_all(head1);
    free_all(head2);
    free_all(i_head);
    fclose(file1);
    fclose(file2);
  }
  
  return 0;
}
