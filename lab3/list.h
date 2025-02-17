#ifndef LIST_H_
#define LIST_H_
struct Word_item {
  char str[20];
  struct Word_item *next;
  struct Word_item *prev;
};
typedef struct Word_item word_item;
word_item* create_list();
void find_and_add(FILE*, word_item*);
word_item* search(word_item*, char*);
void list_add_word(word_item*, char*);
char* clean_str(char*);
#endif /* LIST_H_ */
