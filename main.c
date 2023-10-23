#include<stdio.h>
#include <string.h>
#include <dirent.h>
#include "text.h"
#include "settings.h"

const char* VERSION = "1.00";

// save data
int location_id = 0;
char name[16];

void help() {
    printf("TERMON\n\n");
    printf("Usage: termon [OPTION]...\n");
    printf("Play Pokemon on terminal.\n\n");

    printf("With no OPTION, play Pokemon.\n\n");

    printf("    -l, --language\tset the language and exit\n");
    printf("    -h, --help\t\tdisplay this help and exit\n");
    printf("    -v, --version\toutput version information and exit\n");

    printf("Examples :\n");
    printf("    termon\t\tPlay Pokemon\n");
    printf("    termon -l en\tSwitch language to English\n");
}

void message(int message_id) {
    display_text(location_id, get_language(), message_id);
}

void message_with_variable(int message_id, const char* variable) {
    display_text_with_variable(location_id, get_language(), message_id, variable);
}

void start_new_game() {
    message(0);
    message(1);
    message(2);
    message(3);
    scanf("%s",name);
    message_with_variable(4, name);
    message_with_variable(5, name);
}

void start_game() {
    DIR* dir;
    struct dirent *entry;
    dir = opendir("saves");
    if(dir==NULL) {
        printf("Error 002 : unable to read saves repository.\n");
        return;
    }

    int num_files = 0;

    while((entry = readdir(dir)) != NULL) {
        if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            ++num_files;
        }
    }

    if(num_files == 0) {
        printf("No data found. A new game will start.\n");
        start_new_game();
        return;
    }

    // TODO : display all the files found 
    // and let the user select a save, or begin a new one.
    closedir(dir);
}

void main(int argc, char** argv) {
    if(argc == 1) {
        init_settings();
        start_game();
    }
    else if(argc == 2) {
        if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) help();
        else if(strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0) printf("Termon %s", VERSION);
        else printf("Error 000 : unknown command.");
    }
    else if(argc == 3) {
        if(strcmp(argv[1], "--language") == 0 || strcmp(argv[1], "-l") == 0) set_language(argv[2]);
        else printf("Error 001 : unknown command.");
    }
}