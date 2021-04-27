#ifndef _MONKEY_
#define _MONKEY_

#include <stdlib.h>
#include <string.h>
#include "genetic.h"

#define MONKEY_DEFAULT_SOLUTION "IA e a melhor UC do curso."
#define MONKEY_DEFAULT_POP_SIZE 5
#define MONKEY_DEFAULT_GEN_SIZE strlen(MONKEY_DEFAULT_SOLUTION)
#define MONKEY_DEFAULT_MUTATION 0.01
#define MONKEY_DEFAULT_CROSSOVER 0.95
#define MONKEY_DEFAULT_ELITISM 3

extern char *monkey_solution;

void monkey_random_genome(void ***, const size_t, const size_t);

#endif /* _MONKEY_ */
