#include "list.h"

#include <stdlib.h>
#include <string.h>

#define NODE    struct Node


// --------- UTILS ---------
NODE* __alloc_new_node() {
    NODE* n = (NODE*)malloc(sizeof(NODE));
    return n;
}

LinkedList* __init_edge(LinkedList* list) {
    list->edge = __alloc_new_node();
    list->edge->data = NULL;
    list->edge->next = list->edge;
    list->edge->prev = list->edge;

    return list;
}

void __set_node(NODE* target, NODE* next, NODE* prev) {
    target->next = next;
    target->prev = prev;
}

void __add_to_back(NODE* edge, NODE* prev, NODE* new) {
    prev->next = new;
    edge->prev = new;

    __set_node(new, edge, prev);
}

void __add_to_front(NODE* edge, NODE* front, NODE* new) {
    front->prev = new;
    edge->next = new;

    __set_node(new, front, edge);
}
// --------------------




LinkedList* list_init(void) {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->size = 0;
    list = __init_edge(list);

    return list;
}


struct Node* list_begin(LinkedList* list) {
    return list->edge->next;
}


struct Node* list_next(struct Node* node) {
    return node->next;
}


struct Node* list_end(LinkedList* list) {
    return list->edge;
}


void list_add(LinkedList* list, void* data, size_t data_size, enum ListDirections direct) {
    NODE* new = __alloc_new_node();

    void* new_data = malloc(data_size);
    memcpy_s(new_data, data_size, data, data_size);
    new->data = new_data;

    if (!list->edge) {
        list = __init_edge(list);   // if list created manually(using malloc instead of list_init())
        list->size = 0;
    }

    NODE* edge = list->edge;
    NODE* prev = edge->prev;

    if (direct == BACK)
        __add_to_back(edge, prev, new);
    else
        __add_to_front(edge, edge->next, new);

    list->size += 1;
}


void list_free(LinkedList* list) {
    NODE* n = list->edge->next; // point to the first node

    while (n != list->edge) {
        NODE* next = n->next;

        free(n->data);  // if n->data is NULL no actions occurs
        free(n);

        n = next;
    }

    free(list->edge);
    free(list);
}
