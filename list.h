#ifndef LIST_H
#define LIST_H

typedef struct list List;

List* list_create();
void list_add(List* l, char* key, int value);
int list_get(List* l, char* key);
void list_set(List* l, char* key, int value);
int list_exist(List* l, char* key);
void list_print(List* l);
void list_destroy(List* l);


void list_push(List* l, char* key, int value);

#endif