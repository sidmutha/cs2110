#ifndef SINGLY_H_
#define SINGLY_H_
#include"packet.h"
struct S_list_item { //the struct holding an item of the singly linked list
  packet pckt;
  struct S_list_item* next;
};


typedef struct S_list_item s_list_item;

s_list_item* singly_create_list();
void singly_add_item(s_list_item* , char*, char*, char*);
void singly_send_item(s_list_item* );
s_list_item* singly_search(s_list_item*, char, char*);
void singly_print_all(s_list_item*);
int s_begin();
void s_perform (int, s_list_item*);

#endif /* SINGLY_H_ */
