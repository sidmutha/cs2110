#include <stdio.h>
#include "doubly.c"
#include "packet.h"
main(){
d_list_item* head;
d_list_item* search_r;
char sendr[10], rcvr[10], msg[30];
strcpy(sendr,"");  
packet pcket;

head =  d_create_list();

printf("\nEnter sender: ");
fgets(sendr,10,stdin);  
printf("\nEnter receiver: ");
gets(pcket.receiver);  
  printf("\nEnter message: ");
  gets(pcket.message); 
  strcpy(pcket.sender,sendr);
  d_add_item(head,pcket);
  strcpy(sendr,"");
  printf("\nEnter sender: ");
  fgets(sendr,10,stdin);  
  printf("\nEnter receiver: ");
  gets(pcket.receiver);  
  printf("\nEnter message: ");
  gets(pcket.message); 
  strcpy(pcket.sender,sendr);
  d_add_item(head,pcket);
  strcpy(sendr,"");
  d_print_all(head);
 
 printf("\n++++++++++++Search+++++++");
  
  printf("\nEnter sender: ");
fgets(sendr,10,stdin);
search_r = d_search(head, 's', sendr);
if (!(search_r == 0)){ 
  printf("\nReceiver: %s",search_r->pckt.receiver);
  }
else printf("\nSorry, no results\n");
 
}
