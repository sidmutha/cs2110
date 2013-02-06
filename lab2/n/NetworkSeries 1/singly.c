/*
 * singly.c
 *
 *  Created on: 12-Aug-2012
 *      Author: sid
 */
#include "packet.h"
#include <stddef.h>
#include<stdlib.h>
//#include <malloc.h>
#include <string.h>

//********functions*****************************************

//function to create the list; return the head element
s_list_item* singly_create_list() {  
  s_list_item* head = NULL;
  head = malloc(sizeof(s_list_item));
  head->next = NULL;
  //head1=head;	
  return head;
      
}
 
//function to add item to the list
void singly_add_item(s_list_item* head, char* sender, char* receiver,
		     char* message) {
  s_list_item* new = NULL;
  new = malloc(sizeof(s_list_item));
	
  new->next = head->next;
  head->next = new;
  strncpy(new->pckt.sender, sender, 10);
  strncpy(new->pckt.receiver, receiver, 10);
  strncpy(new->pckt.message, message, 30);
  //new->pckt.receiver = receiver;
  //new->pckt.message = message;
  //printf("Testing this");
  //singly_print_all(head1);
}


//function to send(delete) an item from the list 
//needs the pointer to the *previous* item

void singly_send_item(s_list_item* previous_item){
  s_list_item* temp = NULL;
  //  printf("blah : %s\n",previous_item->next->pckt.message);

  printf("\n....Sending....\nSender: %s\nReceiver: %s\nMessage: %s",
	 previous_item->next->pckt.sender,
	 previous_item->next->pckt.receiver,
	 previous_item->next->pckt.message);
  temp = previous_item->next;
  previous_item->next = previous_item->next->next;
  // singly_print_all(head1);
  free(temp);
}

//function to search for a query (sender, rcvr, msg) 

s_list_item* singly_search(s_list_item* head, char type, char* query) {
  s_list_item* p_crawler; //crawler will point to the PREVIOUS item but will 
  p_crawler = head; //compare the query with values in the current one, ie 'next' of previous
  switch (type){case 's':
	  	
      while (p_crawler->next != NULL && (strcmp(p_crawler->next->pckt.sender, query))) {
	p_crawler = p_crawler->next;
      }
      break;
  case 'r':

    while (p_crawler->next != NULL && strcmp(p_crawler->next->pckt.receiver, query)) {
      p_crawler->next = p_crawler->next;
    }
    break;
  case 'm':

    while (p_crawler->next != NULL && strcmp(p_crawler->next->pckt.message, query)) {
      p_crawler = p_crawler->next;
    }
    break;
  }
  if (p_crawler->next != NULL) {
    return p_crawler;
  } else {
    return NULL;
  }
}

void singly_print_all(s_list_item* head){
  s_list_item* crawler;
  crawler = head;
  do{
    crawler=crawler->next;
    printf("\n Sender: %s",crawler->pckt.sender);
    printf("\n Receiver: %s",crawler->pckt.receiver);
    printf("\n Message: %s",crawler->pckt.message);
    printf("\n----------------------------");
 
  }  while(crawler->next != NULL);

}

//functions for the user interaction
int s_begin(){
  int choice;
  printf("\n======Singly linked list======\nWhat would you like to do?");
  printf("\n(1)Receive a packet\n(2)Send a packet\n(3)Send all the messages from a sender\n(4)Send all messages from a receiver\n(5)Print all messages in the buffer\nYour choice: ");
  scanf("%d",&choice);
  if(!(choice>=1&&choice<=5)){
    printf("Sorry, Invalid choice");
  }    
  else
    return choice;
}

void s_perform (int choice, s_list_item* head){
     
  s_list_item* prev_item;
   
  char sndr[10];
  s_list_item* Pp_crawler = head;	 
   
  char rcv[10];
  s_list_item* Pr_crawler = head;
   
  switch(choice){
  case 1:;      
    int i, num; 
    char sendr[10],rcvr[10],msg[30], mesg[30]; 
    printf("\nReceive packet\nHow many packets?: ");
    scanf("%d",&num);
    getchar();
    for(i=1;i<=num;i++){
      printf("\nEnter sender: ");
      fgets(sendr,10,stdin);  
      printf("\nEnter receiver: ");
      fgets(rcvr,10,stdin);  
      printf("\nEnter message: ");
      fgets(msg,30,stdin); 
      singly_add_item(head,sendr,rcvr,msg);      
      printf("---------------------------");
    }
    break;     
  case 2:
     
    printf("\nSearch and send a particular message");
    printf("\nEnter message: ");
    getchar();
    fgets(mesg,30,stdin);
    prev_item = singly_search(head,'m',mesg);
    if(prev_item == NULL){
      printf("Sorry, no results");
    }
    else {
      // printf("blah!! %s",prev_item->pckt.message);
      singly_send_item(prev_item);
    }	 
    break;
  case 3:
     
    printf("\nSend all messages from a sender");
    printf("\nEnter sender: ");
    getchar();
    fgets(sndr,10,stdin);
    do{
      Pp_crawler = singly_search(Pp_crawler,'s',sndr);
      if (Pp_crawler != NULL){
	singly_send_item(Pp_crawler);
      }
    }while(Pp_crawler != NULL);
    break;
  case 4:
     
    printf("\nSend all messages from a receiver");
    printf("\nEnter receiver: ");
    getchar();     
    fgets(rcv,10,stdin);
    do{
      Pr_crawler = singly_search(Pr_crawler,'s',rcv);
      if (Pr_crawler != NULL){
	singly_send_item(Pr_crawler);
      }
    }while(Pr_crawler != NULL);
    break;
  case 5:
    singly_print_all(head);
    break;
  }	 
  printf("\n+++++++++++++++++++++++++++++");
  printf("\nPress any key to continue...");
  getchar();
  s_perform(s_begin(),head);
   
   
   
   
}
