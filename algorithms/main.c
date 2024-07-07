#include <bidir/list.h>

#include <stdlib.h>
#include <stdio.h>


int main() {
    LinkedList* list = list_init();

    int* a = (int*)malloc(sizeof(int));
    int* b = (int*)malloc(sizeof(int));
    int* c = (int*)malloc(sizeof(int));
    int* d = (int*)malloc(sizeof(int));

    *a = 10;
    *b = 20;
    *c = 30;
    *d = 40;

    list_add(list, a, sizeof(int), BACK);
    list_add(list, b, sizeof(int), FRONT);
    list_insert_data(list, c, sizeof(int), 1);
    list_add(list, d, sizeof(int), BACK);

    struct Node* d_node = list_at_index(list, -1);
    list_insert_node(list, d_node, 2);

    uint32_t i = 0;
    struct Node* node = list_begin(list);
    for (; node != list_end(list); node = list_next(node), i++) {
        printf_s("%d: %d\n", i, *((int*)node->data));
    }
    printf_s("--------\n");

    i = list->size;
    node = list_rbegin(list);
    for (; node != list_rend(list); node = list_rnext(node), i--) {
        printf_s("%d: %d\n", i, *((int*)node->data));
    }

    list_free(list);

    free(a);
    free(b);
    free(c);
    free(d);

    return 0;
}