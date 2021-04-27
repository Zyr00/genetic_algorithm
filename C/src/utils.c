#include "../includes/utils.h"

/**
 * @brief create a random character from the asci table.
 * @return a random char
 */
char random_char() {
  return (char) ((rand() % (ASCI_END - ASCI_START)) + ASCI_START);
}

/**
 * @brief create a random float
 *  View: https://stackoverflow.com/questions/13408990/how-to-generate-random-float-number-in-c#13409133
 * @param limit is never bigger than the limit
 */
float random_float(const float limit) {
  return ((float) rand() / (float) (RAND_MAX)) * limit;
}

/**
 * @brief create a random int
 * @param limit is never bigger than the limit
 */
int random_int(const int limit) {
  return rand() % limit;
}

/**
 * @brief clean the input buffer
 */
void clean_input_buffer() {
  char c;
  while((c = getchar()) != NEW_LINE_CHAR && c != EOF);
}

/**
 * @brief print a message to the cli
 * @param message the message to print to the cli
 */
void show_message(const char *const message) {
  printf("%s", message);
}

/**
 * @brief read a size_t from the cli
 * @param value the pointer to the value
 * @param message a message to show to de user
 */
void read_size_t(size_t *const value, const char *const message) {
  show_message(message);
  while (scanf("%lu", value) != 1) {
    printf(INVALID_INPUT);
    clean_input_buffer();
    show_message(message);
  }
  clean_input_buffer();
}

/**
 * @brief read a float from the cli
 * @param value the pointer to the value
 * @param message a message to show to de user
 */
void read_float(float *const value, const char *const message) {
  show_message(message);
  while (scanf("%f", value) != 1) {
    printf(INVALID_INPUT);
    clean_input_buffer();
    show_message(message);
  }
  clean_input_buffer();
}

/**
 * @brief read a short from the cli
 * @param value the pointer to the value
 * @param message a message to show to de user
 */
void read_unsigned_short(short unsigned int *const value, const char *const message) {
  show_message(message);
  while (scanf("%hu", value) != 1) {
    printf(INVALID_INPUT);
    clean_input_buffer();
    show_message(message);
  }
  clean_input_buffer();
}

/**
 * @brief read a char from the cli
 * @param value the pointer to the value
 * @param message a message to show to de user
 */
void read_char(char *const value, const char *const message) {
  show_message(message);
  *value = getchar();
  if (*value != NEW_LINE_CHAR)
    clean_input_buffer();
}

/**
 * @brief read a string from the cli
 * @param string a pointer where the string will be stored
 * @param size the size of the string
 * @param message a message to show the user
 */
void read_string(char *const value, const size_t size, const char *const message) {
  show_message(message);
  if (fgets(value, size, stdin) != NULL) {
    const size_t s_size = strlen(value) - 1;
    if (value[s_size] == NEW_LINE_CHAR)
      value[s_size] = END_LINE_CHAR;
    else
      clean_input_buffer();
  }
}
