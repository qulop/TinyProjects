#ifndef __C_LINKED_LIST_H
#define __C_LINKED_LIST_H

#include "base.h"
#include <stdbool.h>


LinkedList* list_init(void);

struct Node* list_begin(LinkedList* list);
struct Node* list_rbegin(LinkedList* list);

struct Node* list_next(struct Node* node);
struct Node* list_rnext(struct Node* node);

struct Node* list_end(LinkedList* list);
struct Node* list_rend(LinkedList* list);

// if index equal to <-1>, then last node will returned(if it exists)
struct Node* list_at_index(LinkedList* list, int index);

void list_add(LinkedList* list, void* data, size_t data_size, enum ListDirections direct);
bool list_insert_data(LinkedList* list, void* data, size_t data_size, uint32_t index);
bool list_insert_node(LinkedList* list, struct Node* node, uint32_t index);

void list_free(LinkedList* list);

#endif