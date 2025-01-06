#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

struct node {
    char key[15];
    int value;
    struct node* next;
};

struct list {
    struct node* first;
};

// Função auxiliar para encontrar um nó pela chave
static struct node* list_find(List* l, char* key) {
    struct node* current = l->first;
    while(current){
        if(strcmp(current->key, key) == 0){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Cria uma nova lista
List* list_create() {
    List* l = calloc(1, sizeof(List));
    if (!l) {
        perror("Failed to create list");
        exit(EXIT_FAILURE);
    }
    l->first = NULL;
    return l;
}

// Adiciona um novo nó à lista
void list_add(List* l, char* key, int value) {
    struct node* node = malloc(sizeof(struct node));
    if (!node) {
        perror("Failed to add node");
        exit(EXIT_FAILURE);
    }
    strncpy(node->key, key, sizeof(node->key) - 1);
    node->key[sizeof(node->key) - 1] = '\0';
    node->value = value;
    node->next = l->first;
    l->first = node;
}

// Obtém o valor associado a uma chave
int list_get(List* l, char* key) {
    struct node* n = list_find(l, key);
    if (n != NULL) {
        return n->value;
    }
    return -1;
}

// Define o valor para uma chave existente
void list_set(List* l, char* key, int value) {
    struct node* n = list_find(l, key);
    if (n != NULL) {
        n->value = value;
    }
}

// Verifica se uma chave existe na lista
int list_exist(List* l, char* key){
    return list_find(l, key) != NULL;
}

// Imprime todos os elementos da lista
void list_print(List* l) {
    struct node* current = l->first;
    while(current){
        printf("%s -> %d\n", current->key, current->value);
        current = current->next;
    }
}


void list_destroy(List* l) {
    struct node* current = l->first;
    struct node* next_node;
    while(current != NULL){
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(l);
}


void list_push(List* l, char* key, int value) {
    list_add(l, key, value);
}