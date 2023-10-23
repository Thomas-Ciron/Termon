#ifndef TEXT_H
#define TEXT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Get the nth line of a text
 * 
 * @param file_name the file name
 * @param n the number of the line to get
 * @return the nth line
 */
char* get_nth_line(const char* file_name, const int n);

/**
 * @brief Display a message in the terminal.
 * 
 * @param location_id the id of the location
 * @param language_id the language identifier
 * @param message_id the row where the message is in the text
 */
void display_text(const int location_id, const int language_id, const int message_id);


/**
 * @brief Display a message in the terminal, with a variable in it.
 * 
 * @param location_id the id of the location
 * @param language_id the language identifier
 * @param message_id the row where the message is in the text
 * @param variable the variable to put instead of %var
 */
void display_text_with_variable(const int location_id, const int language_id, const int message_id, const char* variable);
#endif