#ifndef __C_LINKED_LIST_H
#define __C_LINKED_LIST_H

#include "base.h"


LinkedList* list_init(void);

struct Node* list_begin(LinkedList* list);
struct Node* list_next(struct Node* node);
struct Node* list_end(LinkedList* list);

void list_add(LinkedList* list, void* data, size_t data_size, enum ListDirections direct);

void list_free(LinkedList* list);

#endif