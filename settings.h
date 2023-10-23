#ifndef SETTINGS_H
#define SETTINGS_H

#include "binaries.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* How to set the language index ? 
 * Go to https://en.wikipedia.org/wiki/List_of_languages_by_total_number_of_speakers
 * The language index is the 2023 ranking of the language */
#define ENGLISH 1
#define FRENCH 5
#define GERMAN 12
#define ITALIAN 29

/**
 * @brief Save user's settings in settings.bin.
 * 
 */
void save_settings();

/**
 * @brief Read user's settings in settings.bin.
 *
 */
void init_settings();

/**
 * @brief Change the language and save it.
 * 
 * @param short_language_name the short language name (e.g. "en" for English)
 */
void set_language(const char* short_language_name);

#endif