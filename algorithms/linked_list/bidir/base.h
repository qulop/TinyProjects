#ifndef C_LL_BASE_H
#define C_LL_BASE_H

#include <stdint.h>


struct Node {
    void* data;

    struct Node* next;
    struct Node* prev;
};

typedef struct {
    struct Node* edge;

    uint32_t size;
} LinkedList;


enum ListDirections {
    FRONT, BACK
};

#endif