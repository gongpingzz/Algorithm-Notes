#include "common_header.h"


int compare_char(const void* _a, const void* _b) {
    char *a = (char*)_a;
    char *b = (char*)_b;
    return (*a - *b);
}

bool isAnagram(char * s, char * t){
    int len_s = strlen(s);
    int len_t = strlen(t);
    if (len_s != len_t) {
        return false;
    }

    qsort(s, len_s, sizeof(char), compare_char);
    qsort(t, len_s, sizeof(char), compare_char);
    return strcmp(s, t) == 0;
}



