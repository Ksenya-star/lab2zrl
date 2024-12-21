#ifndef SED_OPERATIONS_H
#define SED_OPERATIONS_H

void replace_text(const char *file_path, const char *regex_pattern, const char *new_text);
void delete_lines(const char *file_path, const char *regex_pattern);
void text_start(const char *file_path, const char *text);
void text_end(const char *file_path, const char *text);

#endif
 
