#ifndef TEXT_H
#define TEXT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Display a message in the terminal.
 * 
 * @param location_id the id of the location
 * @param language_id the language identifier
 * @param message_id the row where the message is in the text
 */
void display_text(const int location_id, const int language_id, const int message_id);

#endif