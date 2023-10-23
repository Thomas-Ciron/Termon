#include "text.h"

void display_text(const int location_id, const int language_id, const int message_id) {
    char file_name[100];
    sprintf(file_name, "texts/%d/%d.txt", language_id, location_id);

    FILE* file = fopen(file_name, "r");

    if(file == NULL) {
        if(language_id == 1) printf("Error 200 : text file not found.");
        else display_text(location_id, 1, message_id); // text not found in the language, try in English
        return;
    }

    char line[255];
    int len = sizeof(line);
    int current_line = -1;

    while(current_line < message_id) {
        if(fgets(line, len, file) == NULL) {
            fclose(file);
            //free(line);
            if(language_id == 1) printf("Error 201 : message not found in text.");
            else display_text(location_id, 1, message_id); // try in English
            return;
        }
        ++current_line;
    }
    fclose(file);
    printf("%s", line);
    //free(line);
}