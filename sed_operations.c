#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include "regex_util.h"

void replace_text(const char *file_path, const char *regex_pattern, const char *new_text) {
    char *con = read_file(file_path);
    if (!con) return;

    regex_t regex;
    regcomp(&regex, regex_pattern, REG_EXTENDED);

    char *res = malloc(strlen(con) + 1);
    res[0] = '\0';

    char *line = strtok(con, "\n");

    while (line) {
        regmatch_t match;
        if (regexec(&regex, line, 1, &match, 0) == 0) {
            char *prefix = strndup(line, match.rm_so);
            char *suffix = strdup(line + match.rm_eo);

            strcat(res, prefix);
            strcat(res, new_text);
            strcat(res, suffix);
            strcat(res, "\n");

            free(prefix);
            free(suffix);
        } else {
            strcat(res, line);
            strcat(res, "\n");
        }

        line = strtok(NULL, "\n");
    }

    regfree(&regex);
    write_file(file_path, res);
    free(res);
}

void delete_lines(const char *file_path, const char *regex_pattern) {
    char *con = read_file(file_path);
    if (!con) return;

    regex_t regex;
    regcomp(&regex, regex_pattern, REG_EXTENDED);

    char *res = malloc(strlen(con) + 1);
    res[0] = '\0';

    char *line = strtok(con, "\n");
    while (line) {
        if (regexec(&regex, line, 0, NULL, 0) != 0) {
            strcat(res, line);
            strcat(res, "\n");
        }

        line = strtok(NULL, "\n");
    }

    regfree(&regex);
    write_file(file_path, res);
    free(res);
}

void text_start(const char *file_path, const char *text) {
    char *con = read_file(file_path);
    if (!con) return;

    char *res = malloc(strlen(con) + strlen(text) * 2 + 1);
    res[0] = '\0';

    char *line = strtok(con, "\n");
    while (line) {
        strcat(res, text);
        strcat(res, line);
        strcat(res, "\n");
        line = strtok(NULL, "\n");
    }

    write_file(file_path, res);
    free(res);
}

void text_end(const char *file_path, const char *text) {
    char *con = read_file(file_path);
    if (!con) return;

    char *res = malloc(strlen(con) + strlen(text) * 2 + 1);
    res[0] = '\0';

    char *line = strtok(con, "\n");
    while (line) {
        strcat(res, line);
        strcat(res, text);
        strcat(res, "\n");
        line = strtok(NULL, "\n");
    }

    write_file(file_path, res);
    free(res);
}



