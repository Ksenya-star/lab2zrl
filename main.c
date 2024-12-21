#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sed_operations.h"

void usage() {
    printf("Usage:\n");
    printf("./sed_simplified input.txt -r 'old text' 'new text'\n");
    printf("./sed_simplified input.txt -d 'text to delete'\n");
    printf("./sed_simplified input.txt -i 'insert text front'\n");
    printf("./sed_simplified input.txt -b 'insert text back'\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        usage();
        return 1;
    }

    const char *path = argv[1];
    const char *opt = argv[2];

    if (strcmp(opt, "-r") == 0 && argc == 5) {
        replace_text(path, argv[3], argv[4]);
    } else if (strcmp(opt, "-d") == 0 && argc == 4) {
        delete_lines(path, argv[3]);
    } else if (strcmp(opt, "-i") == 0 && argc == 4) {
	text_start(path, argv[3]);
    } else if (strcmp(opt, "-b") == 0 && argc == 4) {
	text_end(path, argv[3]);
    } else {
        usage();
        return 1;
    }

    return 0;
}



