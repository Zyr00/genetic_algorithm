#include "../includes/monkey.h"
#include "../includes/utils.h"

char *monkey_solution;

/**
 * @brief generate random chromosomes for the monkey problem
 * @param size the length of the string for the monkey problem
 */
void monkey_random_genome(void ***p, const size_t pop_size, const size_t gen_size) {
  size_t i, j;

  *p = malloc(sizeof(char **) * pop_size);
  if (p == NULL) { printf("P is NULL in random_genome"); return; }

  for (i = 0; i < pop_size; i++) {
    char *string = (char *) malloc(sizeof(char *) * (gen_size - 1));
    for (j = 0; j < gen_size; j++) {
      string[j] = random_char();
    }
    string[gen_size] = '\0';
    (*p)[i] = string;
  }
}
