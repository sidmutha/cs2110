#include<stdlib.h>
#include<stddef.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include "list.h"
/*
  struct Word_item {
  char str[20];
  struct Word_item *next;
  struct Word_item *prev;
  };
  typedef struct Word_item word_item;
*/
//function to create the list
word_item* create_list(){
  word_item* head = NULL;
  head = malloc(sizeof(word_item));
  head->next = head;
  head->prev = head;
  return head;
}
/*char* find_next_word(FILE fptr){
  int ch, i = 0;
  char n_word[20];
  while(((ch = fgetc(fptr)) != isspace(ch)) && isalnum(ch) && ch != EOF){
  n_word[i] = (char)ch;
  i++;  
  }
  if(fptr == EOF){
  return EOF;
  }  
  else 
  return n_word;
  }
*/

//function to find words from the the text file and add them to the list if not already present
void find_and_add(FILE* fptr, word_item *head){
  int ch, i = 0;
  char n_word[20];
  do{
    strcpy(n_word,"");i=0;
    //while loop to extract a word from the stream char-by-char into a string n_word
    while(((ch = fgetc(fptr)) != isspace(ch) ) && (isalpha(ch) || (ch == 27/*apostrophe*/)) && ch != EOF){
      n_word[i] = (char)ch;
      i++;  
    }
    n_word[i] = '\0';
    clean_str(n_word); //clean the string 
    { //search for the string in the list. if not present, add it.
      if(search(head, n_word) == NULL && strcmp("",n_word)){
	list_add_word(head, n_word);
      }
    }
  }while(ch != EOF);
}

//function to search for a string on the list
word_item* search(word_item* head, char* query) {
  word_item* crawler = NULL;
  crawler = head->next;
  
  while (crawler != head && strcmp(crawler->str, query)) {
    crawler = crawler->next;
  }
   
  if (crawler != head) {
    return crawler;
  } 
  else {
    return NULL;
  }
  
}

//function to add a word to the linked list
void list_add_word(word_item* head, char *str){
  word_item* new_word = NULL;
  new_word = malloc(sizeof(word_item));
  head->next->prev = new_word;   
  new_word->next = head->next;
  head->next = new_word;
  new_word->prev = head;
  strcpy(new_word->str, str);
}

//function to convert to convert to lower case and also remove any kinf of punctuations
char* clean_str(char str[]) {
  int i;
  int len = strlen(str);
  for (i = 0; i < len; i++)
    if (str[i] >= 65 && str[i] <= 90) str[i] += 32;
    else if (str[i] >= 97 && str[i] <= 122) {} 
    else {
      int j;
      for (j = i + 1; j < len - 1; j++) {
	char temp;
	temp = str[j];
	str[j] = str [j + 1];
	str[j - 1] = temp;
        
      }
      len--;
    }
  str[len] = '\0';
  return str;
}

void free_all(word_item *head){
  word_item* crawler;
  crawler = head;
  do{
    crawler = crawler->next;
    free(crawler);
    
  }  while(crawler->next != head);
  free(head);
}
void print_all(word_item* head){
  word_item* crawler;
  crawler = head;
  do{
    crawler=crawler->next;
    printf("\n%s",crawler->str);
    //printf("\n----------------------------");
 
  }  while(crawler->next != head);
}

/*
  main(){
  word_item* head1 = NULL;
  head1 = create_list();
  }
*/
