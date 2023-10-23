#include "text.h"

int MAX_CHARACTERS_NUM_IN_TEXTS = 255;

char* get_nth_line(const char* file_name, const int n) {
    FILE* file = fopen(file_name, "r");

    if(file == NULL) return NULL;

    char* line = (char*)malloc(MAX_CHARACTERS_NUM_IN_TEXTS * sizeof(char));
    int len=MAX_CHARACTERS_NUM_IN_TEXTS*sizeof(char);
    int current_line = -1;

    while(current_line < n) {
        if(fgets(line, len, file) == NULL) {
            fclose(file);
            return NULL;
        }
        ++current_line;
    }
    fclose(file);
    return line;
}

void display_text(const int location_id, const int language_id, const int message_id) {
    char file_name[100];
    sprintf(file_name, "texts/%d/%d.txt", language_id, location_id);

    char* line = get_nth_line(file_name, message_id);
    if(line == NULL) {
        if(language_id == 1) printf("Error 200 : file not found or file too short.");
        else display_text(location_id, 1, message_id); // try in English
        return;
    }
    printf("%s", line);
}

void display_text_with_variable(const int location_id, const int language_id, const int message_id, const char* variable) {
    char file_name[100];
    sprintf(file_name, "texts/%d/%d.txt", language_id, location_id);

    char* line = get_nth_line(file_name, message_id);
    if(line==NULL) {
        if(language_id == 1) printf("Error 200 : file not found or file too short.\n");
        else display_text_with_variable(location_id, 1, message_id, variable); // try in English
        return;
    }

    char* result = (char*)malloc(MAX_CHARACTERS_NUM_IN_TEXTS * sizeof(char));
    int index = 0;
    int index_variable = 0;
    while(line[index] != '\0') {
        if(line[index] == '%' && line[index+1] == 'v' && line[index+2] == 'a' && line[index+3] == 'r') {
            while(variable[index_variable] != '\0') {
                result[index + index_variable] = variable[index_variable];
                ++index_variable;
            }
            index+=4;
        }
        else{
            if(index_variable > 0) {
                result[index + index_variable - 4] = line[index];
            }
            else {
                result[index + index_variable] = line[index];
            }
            ++index;
        }
    }
    result[index + index_variable - 4] = '\0';
    printf("%s", result);
    free(result);
}