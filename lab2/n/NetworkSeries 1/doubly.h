#ifndef DOUBLY_H_
#define DOUBLY_H_
#include"packet.h"
//definig the structure
struct D_list_item {
  packet pckt;
  struct D_list_item *next;
  struct D_list_item *prev;
};
typedef struct  D_list_item d_list_item;
d_list_item* d_create_list();
void d_add_item(d_list_item*, packet);
void d_send_item(d_list_item* );
d_list_item* d_search(d_list_item*, char, char*);
void d_print_all(d_list_item*);
int d_begin();
void d_perform (int, d_list_item*);

#endif /* DOUBLY_H_ */
