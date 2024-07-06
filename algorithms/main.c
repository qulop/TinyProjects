#include <list.h>

#include <stdlib.h>
#include <stdio.h>


int main() {
    LinkedList* list = list_init();

    int a = 10;
    int b = 20;

    int* pa = &a;
    int* pb = &b;

    list_add(list, pa, sizeof(int), BACK);
    list_add(list, pb, sizeof(int), BACK);

    for (struct Node* node = list_begin(list); node != list_end(list); node = list_next(node)) {
        printf("%d\n", *((int*)node->data));
    }

    list_free(list);

    return 0;
}