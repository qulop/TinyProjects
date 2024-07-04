#include "enviroment.h"


void print_result(char** dirs, char* target) {
    if (is_list_empty(dirs)) {
        printf("%s: not found\n", target);
        return;
    }

    printf("%s: ", target);
    for (int i = 0; dirs[i] != NULL; i++) 
        printf("%s/%s ", dirs[i], target);
    printf("\n");
}


int main(int argc, char** argv) {   
    if (argc > 2) {
        printf("locateof: too many arguments\n");
        return EXIT_FAILURE;
    }
    else if (argc == 1) {
        printf("locateof: too few arguments\n");
        return EXIT_FAILURE;
    }

    char* target = argv[1];
    
    char** path_vars = get_path_vars();
    if (is_list_empty(path_vars)) {
        printf("locateof: failed to get PATH variables: path_vars == NULL\n");
        return EXIT_FAILURE;
    }


    u32 cap = 1;
    int i = 0, j = 0; 
    char** dirs_list = (char**)malloc(sizeof(char*) * cap);

    for (i; path_vars[i] != NULL; i++) {
        char* path = path_vars[i];
        
        if (!is_file_exists_in_dir(target, path))
            continue;
        
        dirs_list = append_to_twodim_char_ptr(dirs_list, &cap, j, 2, path);
        j++;
    }
    dirs_list = append_to_twodim_char_ptr(dirs_list, &cap, j, 1, NULL);

  
    print_result(dirs_list, target);

    free_twodim_char_ptr(path_vars);
    free_twodim_char_ptr(dirs_list);

    return EXIT_SUCCESS;
}
