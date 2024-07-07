#include "list.h"

#include <stdlib.h>
#include <string.h>

#define NODE    struct Node


// --------- UTILS ---------
NODE* __alloc_new_node(void) {
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

void* __copy_data(void* data, size_t size) {
    void* new_data = malloc(size);
    memcpy_s(new_data, size, data, size);

    return new_data;
}

bool __is_node_present_in_list(LinkedList* list, NODE* node) {
    NODE* n = list_begin(list);

    for (n; n != list_end(list); n = list_next(n))
        if (n == node)
            return true;
    return false;
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

struct Node* list_rbegin(LinkedList* list) {
    return list->edge->prev;
}


struct Node* list_next(struct Node* node) {
    return node->next;
}


struct Node* list_rnext(struct Node* node) {
    return node->prev;
}


struct Node* list_end(LinkedList* list) {
    return list->edge;
}


struct Node* list_rend(LinkedList* list) {
    return list_end(list);
}


struct Node* list_at_index(LinkedList* list, int index) {
    if (index == -1)
        return (list->size) ? list->edge->prev : NULL;

    NODE* n = list_begin(list);
    size_t i = 0;

    for (; n != list_end(list); n = list_next(n), i++)
        if (i == index)
            return n;

    return NULL;
}


void list_add(LinkedList* list, void* data, size_t data_size, enum ListDirections direct) {
    NODE* new = __alloc_new_node();
    new->data = __copy_data(data, data_size);

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


bool list_insert_data(LinkedList* list, void* data, size_t data_size, uint32_t index) {
    NODE* target = list_at_index(list, index);
    if (!target)
        return false;

    NODE* new = __alloc_new_node();
    new->data = __copy_data(data, data_size);

    __add_to_front(target->prev, target, new);
    return true;
}


bool list_insert_node(LinkedList* list, struct Node* node, uint32_t index) {
    NODE* target = list_at_index(list, index);
    if (!target)
        return false;

    if (__is_node_present_in_list(list, node)) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    __add_to_front(target->prev, target, node);
    return true;
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
