#ifndef __LOCATEOF_ENVIROMENT_H
#define __LOCATEOF_ENVIROMENT_H

#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>

#include "utils.h"



int is_file_exists_in_dir(const char* filename, const char* path) {
    struct dirent* dir;
    DIR* d = opendir(path);
    if (!d) 
        return false;

    while ((dir = readdir(d)) != NULL)
        if (strcmp(filename, dir->d_name) == 0) 
            return true;

    closedir(d);
    return false;
}


char** get_path_vars(void) {
    char* source = getenv("PATH");
    if (!source)
        return NULL;

    u32 cap = 4;
    int i = 0;
    char** tokens = (char**)malloc(sizeof(char*) * cap);

    char* tok = strtok(source, ":");
    for (i; tok != NULL; i++) {
        tokens = append_to_twodim_char_ptr(tokens, &cap, i, 4, tok);

        tok = strtok(NULL, ":");
    }
    tokens = append_to_twodim_char_ptr(tokens, &cap, i, 1, NULL);

    return tokens;
}

#endif