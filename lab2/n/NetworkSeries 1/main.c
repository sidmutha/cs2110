#include<stdlib.h>
#include<stddef.h>
#include<stdio.h>
#include"singly.h"
#include"doubly.h"
#include"singly.c"
#include"doubly.c"
#include"packet.h"

main(){
  int list_type;
  
  printf("\n****************************************");
  printf("\n*              Welcome!                *");
  printf("\n****************************************");
  printf("\nSelect the method you would like to use:");
  printf("\n(1)Singly linked list\n(2)Doubly linked list\nYour choice: ");
  scanf("%d",&list_type);
  if(list_type == 1){
    s_list_item* head;  
    head = singly_create_list();
    s_perform(s_begin(),head);
  }
  else if(list_type == 2){
    d_list_item* head;  
    head = d_create_list();
    d_perform(d_begin(),head);
  }
  else 
    printf("Sorry, invalid choice");
}
