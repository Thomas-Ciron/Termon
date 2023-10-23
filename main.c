#include<stdio.h>
#include <string.h>
#include "settings.h"

const char* VERSION = "1.00";

void help() {
    printf("TERMON\n\n");
    printf("Usage: termon [OPTION]...\n");
    printf("Play Pokemon on terminal.\n\n");

    printf("With no OPTION, play Pokémon.\n\n");

    printf("\t-l, --language\tset the language\n");
    printf("\t-h, --help\tdisplay this help and exit\n");
    printf("\t-v, --version\toutput version information and exit\n");
}

void main(int argc, char** argv) {
    if(argc == 1) {
        init_settings();
    }
    else if(argc == 2) {
        if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) help();
        if(strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0) printf("Termon %s", VERSION);
        else printf("Error 000 : unknown command.");
    }
    else if(argc == 3) {
        if(strcmp(argv[1], "--language") == 0 || strcmp(argv[1], "-l") == 0) set_language(argv[2]);
        else printf("Error 001 : unknown command.");
    }
}