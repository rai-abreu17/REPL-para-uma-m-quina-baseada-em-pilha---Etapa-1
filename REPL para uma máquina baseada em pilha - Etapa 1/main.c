#include "list.h"
#include <stdio.h>

int main() {
    List* l = list_create();
    list_add(l, "key1", 10);
    list_add(l, "key2", 20);
    list_print(l);

    int value = list_get(l, "key1");
    printf("Value for key1: %d\n", value);

    list_set(l, "key2", 30);
    list_print(l);

    if (list_exist(l, "key3")) {
        printf("key3 exists\n");
    } else {
        printf("key3 does not exist\n");
    }

    list_destroy(l);
    return 0;
}