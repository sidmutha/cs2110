#include"packet.h"
#include<stdlib.h>
#include<stddef.h>

//definig the structure
/*struct D_list_item {
  packet pckt;
  struct D_list_item *next;
  struct D_list_item *prev;
  };
  typedef struct  D_list_item d_list_item;
*/
//function create the list
d_list_item* g_head;
d_list_item* d_create_list(){
  d_list_item* head = NULL;
  head = malloc(sizeof(d_list_item));
  head->next = head;
  head->prev = head;
  g_head = head;
}

//function to add item

void d_add_item(d_list_item* head, packet pcket){
  d_list_item* new = NULL;
  new = malloc(sizeof(d_list_item));
  /* if(head->next == NULL){
     new->next = head;
     new->prev = head;
     head->next = new;
     head->prev = new;
     }
     else{*/
  head->next->prev = new;   
  new->next = head->next;
  head->next = new;
  new->prev = head;
  // }
  new->pckt = pcket;
}

//function to print all 

void d_print_all(d_list_item* head){
  d_list_item* crawler;
  crawler = head;
  do{
    crawler=crawler->next;
    printf("\n Sender: %s",crawler->pckt.sender);
    printf("\n Receiver: %s",crawler->pckt.receiver);
    printf("\n Message: %s",crawler->pckt.message);
    printf("\n----------------------------");
 
  }  while(crawler->next != head);
}
//function to send(delete) item
void d_send_item(d_list_item* item){
  printf("\n....Sending....");
  printf("\n Sender: %s",item->pckt.sender);
  printf("\n Receiver: %s",item->pckt.receiver);
  printf("\n Message: %s",item->pckt.message);
  item->prev->next = item->next;
  item->next->prev = item->prev;
  free(item);
}

d_list_item* d_search(d_list_item* head, char type, char* query) {
  d_list_item* crawler=NULL;
  crawler = g_head->next;
  
  switch (type){
  case 's':	
    while (crawler != g_head && strcmp(crawler->pckt.sender, query)) {
      crawler = crawler->next;
    }
    break;
  case 'r':	
    while (crawler->next != g_head && strcmp(crawler->pckt.receiver, query)) {
      crawler = crawler->next;
    }
    break;
  case 'm':	
    while (crawler->next != g_head && strcmp(crawler->pckt.message, query)) {
      crawler = crawler->next;
    }
    break;
  }
	
  if (crawler != g_head) {
    return crawler;
  } 
  else {
    return NULL;
  }
}

//functions for the user interaction
int d_begin(){
  int choice;
  printf("\n======Doubly linked list======\nWhat would you like to do?");
  printf("\n(1)Receive a packet\n(2)Send a packet\n(3)Send all the messages from a sender\n(4)Send all messages from a receiver\n(5)Print all messages in the buffer\nYour choice: ");
  scanf("%d",&choice);
  if(!(choice>=1&&choice<=5)){
    printf("Sorry, Invalid choice");
  }    
  else
    return choice;
}

void d_perform (int choice, d_list_item* head){ 
  switch(choice){
  case 1:;
    int i, num; 
    char mesg[30];
    packet pcket; 
    printf("\nReceive packet\nHow many packets?: ");
    scanf("%d",&num);
    getchar();
    for(i=1;i<=num;i++){
      printf("\nEnter sender: ");
      fgets(pcket.sender,10,stdin);  
      printf("\nEnter receiver: ");
      fgets(pcket.receiver,10,stdin);  
      printf("\nEnter message: ");
      fgets(pcket.message,30,stdin); 
       
      d_add_item(head,pcket);      
      printf("---------------------------");
    }
    break;     
  case 2:;
    d_list_item* item;
    printf("\nSearch and send a particular message");
    printf("\nEnter message: ");
    getchar();
    fgets(mesg,30,stdin);
    item = d_search(head,'m',mesg);
    if(item == NULL){
      printf("\nSorry, no results");
    }
    else {
      d_send_item(item);
    }	 
    break;
  case 3:;
    char sndr[10];
    d_list_item* Pp_crawler = head;	 
 
    printf("\nSend all messages from a sender");
    printf("\nEnter sender: ");
    getchar();
    fgets(sndr,10,stdin);
    do{ //crawler to search for the next instance of query
      Pp_crawler = d_search(Pp_crawler,'s',sndr); 
      if (Pp_crawler != g_head && Pp_crawler != NULL){
	d_send_item(Pp_crawler);
      }
    }while(Pp_crawler != g_head && Pp_crawler != NULL);
    break;
  case 4:;
    char rcv[10];
    d_list_item* Pr_crawler = head;
     
    printf("\nSend all messages from a receiver");
    printf("\nEnter receiver: ");
    getchar();     
    fgets(rcv,10,stdin);
    do{//crawler to search for the next instance of query
      Pr_crawler = d_search(Pr_crawler,'r',rcv);
      if (Pr_crawler != g_head && Pr_crawler != NULL){
	d_send_item(Pr_crawler);
      }
    }while(Pr_crawler != g_head && Pr_crawler != NULL);
    break;
  case 5:
    d_print_all(head);
    break;
  }	 
  printf("\n+++++++++++++++++++++++++++++");
  printf("\nPress any key to continue...");
  getchar();
  d_perform(d_begin(),head);   
}
