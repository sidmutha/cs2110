/*
 * m.c
 *
 *  Created on: 12-Aug-2012
 *      Author: sid
 */

#include <stdio.h>
#include "singly.c"
main(){
  s_list_item* head;
    s_list_item* search_r;
  char sendr[10], rcvr[10], msg[30];
 head =  singly_create_list();
  printf("\nEnter sender: ");
  gets(sendr);  
//scanf("%s",&sendr);
  printf("\nEnter receiver: ");
  //scanf("%s",&rcvr);
  gets(rcvr);  
printf("\nEnter message: ");
//scanf("%s",&msg);
 gets(msg); 

 singly_add_item(head,sendr,rcvr,msg);

 printf("\nEnter sender: ");
  gets(sendr);  
//scanf("%s",&sendr);
  printf("\nEnter receiver: ");
  //scanf("%s",&rcvr);
  gets(rcvr);  
printf("\nEnter message: ");
//scanf("%s",&msg);
 gets(msg); 
 
singly_add_item(head,sendr,rcvr,msg);

 singly_print_all(head);

 printf("\n++++++++++++Search+++++++");

printf("\nEnter sender: ");
  gets(sendr);  
  search_r = singly_search(head, 's', sendr);
  if (!(search_r == 0)){ 
printf("\nReceiver: %s",search_r->next->pckt.receiver);
    }
    else printf("\nSorry, no results\n");
}
