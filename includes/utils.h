#ifndef _UTILS_
#define _UTILS_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCI_START 32
#define ASCI_END 127
#define NEW_LINE_CHAR '\n'
#define END_LINE_CHAR '\0'
#define INVALID_INPUT "Invalid input try again.\n"

char random_char();
float random_float(const float);
int random_int(const int);
void clean_input_buffer();
void show_message(const char *const);
void read_size_t(size_t *const, const char *const);
void read_float(float *const, const char *const);
void read_unsigned_short(short unsigned int *const, const char *const);
void read_char(char *const, const char *const);
void read_string(char *const, const size_t, const char *const);

#endif /* _UTILS_ */
