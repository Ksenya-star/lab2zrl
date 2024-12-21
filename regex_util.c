#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_file(const char *path) {
    FILE *file = fopen(path, "r");

    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long len = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *con = malloc(len + 1);
    fread(con, 1, len, file);
    con[len] = '\0';

    fclose(file);
    return con;
}

void write_file(const char *path, const char *con) {
    FILE *file = fopen(path, "w");

    if (!file) {
        perror("Error opening file");
        return;
    }

    fwrite(con, 1, strlen(con), file);
    fclose(file);
}




