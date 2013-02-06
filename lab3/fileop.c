#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include "list.h"
//#include "list.c"

//function to create the list of common words
word_item* i_list(word_item* head1, word_item* head2){
  word_item *crawler = head1, *sim, *i_head;
  i_head = create_list();
  do{
    
    sim = search(head2, crawler->str);
    if(sim == NULL){
      crawler = crawler->next;
    }
    else{
      list_add_word(i_head,crawler->str);
      crawler = crawler->next;
    }
  }while(crawler->next != head1);
  return i_head;
}

//function to count the no of elements in a list
int count(word_item* head){
  word_item* crawler;
  int i = 0;
  crawler = head;
  do{
    crawler=crawler->next;
    i++;
  }  while(crawler->next != head);
  return i;
}

//function to write the contents of a list to a file
void write_to_file(word_item* head, FILE *fptr){
  word_item* crawler;
  crawler = head;
  do{
    crawler=crawler->next;
    fprintf(fptr, "%s ",crawler->str);
  }  while(crawler->next != head);
     
}
