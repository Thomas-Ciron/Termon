#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
/**
 * @brief check if two strings are equal
 * 
 * @param a string a 
 * @param b string b
 * @return 1 if they are equal, 0 otherwise
 */
int are_equal(const char* a, const char* b);


/**
 * @brief copy a string
 * 
 * @param a the string to copy
 * @return the copied value
 */
char* copy(const char* a);

#endif