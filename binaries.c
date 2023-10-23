#include "binaries.h"

int check_if_file_exists(const char* file_name) {
    FILE *file = fopen(file_name, "r");
    return file != NULL;
}

int save_bytes(const char* file_name, const unsigned char* byte_array, int num_bytes) {
    FILE *file = fopen(file_name, "wb");

    if(file!=NULL) {
        size_t bytes_written = fwrite(byte_array, sizeof(unsigned char), num_bytes, file);
        fclose(file);
        if(bytes_written == num_bytes) return 0;
    }

    // Shouldn't be there, error with opening file or writing bytes
    return -1;
}

int read_integer(const char* file_name, const long start_index, int num_bytes) {
    FILE *file = fopen(file_name, "rb");

    // Checking if file is found or not
    if(file == NULL) return -1;

    // Reading bytes
    int value = -1;
    fseek(file, start_index, SEEK_SET);

    unsigned char *buffer = (unsigned char*)malloc(num_bytes);

    size_t bytes_read = fread(buffer, sizeof(unsigned char), num_bytes, file);
    
    // Incorrect number of bytes read
    if(bytes_read == num_bytes) {   
        for(int i = 0; i < num_bytes; ++i) {
            value = (value << 8) | buffer[i];
        }
    }

    free(buffer);
    fclose(file);
    return value;
}