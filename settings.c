#include "settings.h"

// The language identifier
int language = ENGLISH;

void save_settings() {
    printf("Saving data...\n");
    const int NUM_SETTINGS_BYTES = 8;
    unsigned char* byte_array = (unsigned char*)malloc(NUM_SETTINGS_BYTES);
    
    // Saving language
    int value = language;
    for(int i = 7; i >= 0; i--) {
        byte_array[i] = (unsigned char)(value & 0xFF);
        value >>= 8;
    }

    if(save_bytes("binaries/settings.bin", byte_array, NUM_SETTINGS_BYTES) == 0) printf("Data saved successfully !\n");
    else printf("Error 101 : couldn't save settings.\n");

    free(byte_array);
}

void init_settings()
{
    const char* FILE_NAME = "binaries/settings.bin";
    if(does_file_exist(FILE_NAME)) {
        language = read_integer(FILE_NAME, 0, 8);
    }
    else {
        save_settings();
    }
}

void set_language(const char* short_language_name) {
    if(are_equal(short_language_name, "en")) language = ENGLISH;
    else if(are_equal(short_language_name, "fr")) language = FRENCH;
    else if(are_equal(short_language_name, "de")) language = GERMAN;
    else if(are_equal(short_language_name, "it")) language = ITALIAN;
    else printf("Error 102 : unknown language.\n");

    save_settings();
}

int get_language() {
    return language;
}