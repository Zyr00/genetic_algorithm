#ifndef _UTILS_
#define _UTILS_

#include <stdio.h>
#include <string.h>

#define NEW_LINE_CHAR '\n'
#define END_LINE_CHAR '\0'
#define INVALID_INPUT "Invalid input try again."

void clean_input_buffer();
void show_message(const char *const);
void read_size_t(size_t *const, const char *const);
void read_float(float *const, const char *const);
void read_char(char *const, const char *const);
void read_string(char *const, const size_t, const char *const);

#endif /* _UTILS_ */
