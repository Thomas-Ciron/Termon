#ifndef BINARIES_H
#define BINARIES_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Check if the file exists.
 * 
 * @param file_name the name of the file
 * @return 0 if exists, ??? otherwise
 */
int check_if_file_exists(const char* file_name);

/**
 * @brief Save bytes in a binary file.
 * 
 * @param file_name the name of the binary file
 * @param byte_array the bytes to save
 * @param num_bytes the number of bytes to save
 * @return 0 if successful, -1 otherwise
 */
int save_bytes(const char* file_name, const unsigned char* byte_array, int num_bytes);

/**
 * @brief Read integer form a binary file in a specific position
 * 
 * @param file_name the name fo the binary file
 * @param start_index the number of the first byte of the integer to read
 * @param num_bytes the number of bytes to read to build the integer
 * @return the integer
 */
int read_integer(const char* file_name, const long start_index, int num_bytes);

/**
 * @brief Read the flag and return it.
 * 
 * @param flag the flag to check
 * @return 0 if the flag is checked, 1 otherwise
 */
int check_flag(int flag);

/**
 * @brief Release all the flags.
 * 
 * @param num_flags the number of flags
 */
void init_flags(int num_flags);

#endif