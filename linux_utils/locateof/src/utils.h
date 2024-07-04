#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

typedef uint32_t u32;

void printarr(char** p) {
    for (int i = 0; p[i] != NULL; i++) 
        printf("%s\n ", p[i]);
}


int is_list_empty(char** l) {
    return !l || l[0] == NULL;
}


char** append_to_twodim_char_ptr(char** ptr, u32* cap, u32 i, u32 inc, char* target) {
    if ((i + 1) > (*cap)) {
        *cap += inc;
        ptr = (char**)realloc(ptr, sizeof(char*) * (*cap));
    }

    ptr[i] = (target != NULL) ? strdup(target) : NULL;

    return ptr;
}


void free_twodim_char_ptr(char** ptr) {
    for (int i = 0; ptr[i] != NULL; i++)
        free(ptr[i]);
    free(ptr);
}
