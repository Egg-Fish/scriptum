#include "core/list/List.h"

#include <stddef.h>
#include <stdlib.h>

#define LIST_DEFAULT_CAPACITY 8

struct List {
    size_t length;
    size_t capacity;
    void **items;
};

List List_create() {
    List l;
    size_t capacity = LIST_DEFAULT_CAPACITY;

    l = malloc(sizeof(struct List));
    l->length = 0;
    l->capacity = capacity;
    l->items = (void **)calloc(capacity, sizeof(void *));

    return l;
}

void List_destroy(List l) {
    if (l == NULL) {
        return;
    }

    free(l->items);
    free(l);

    return;
}

size_t List_getLength(List l) { return l->length; }

void *List_getItemAtIndex(List l, size_t index) {
    return l->items[index]; // TODO add bounds check
}

void List_appendItem(List l, void *item) {
    if (l->length == l->capacity) {
        size_t newCapacity = l->capacity * 2;
        l->items = (void **)realloc(l->items, newCapacity * sizeof(void *));
        l->capacity = newCapacity;
    }

    l->items[l->length++] = item;

    return;
}
