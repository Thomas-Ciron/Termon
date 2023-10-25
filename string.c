#include "string.h"

int are_equal(const char* a, const char* b) {
    int index = 0;
    while(a[index] != '\0' && b[index] != '\0') {
        if(a[index] != b[index]) return 0;
        ++index;
    }

    if(a[index] != b[index]) return 0;
    return 1;
}

char * copy(const char* a) {
    // step 1 : how long is the string ?
    int string_length = 0;
    while(a[string_length] != '\0') {
        ++string_length;
    }

    // step 2 : create and fill the new string
    char* result = (char*)malloc(sizeof(char) * string_length);
    for(int i = 0; i < string_length; ++i) {
        result[i] = a[i];
    }

    return result;
}