#ifndef _MONKEY_
#define _MONKEY_

#include <stdlib.h>
#include <string.h>
#include "genetic.h"

#define MONKEY_DEFAULT_SOLUTION "IA e a melhor UC do curso."
#define MONKEY_DEFAULT_POP_SIZE 50
#define MONKEY_DEFAULT_GEN_SIZE strlen(MONKEY_DEFAULT_SOLUTION)
#define MONKEY_DEFAULT_MUTATION 0.01

extern char *monkey_solution;

char random_char();
void *monkey_random_genome(const size_t);
float calc_monkey_fitness(const POPULATION, const size_t);
void monkey_crossover(POPULATION *const, POPULATION *const, const int);
void monkey_mutation(POPULATION *const, POPULATION *const, const int, const int);
void monkey_free(POPULATION *);

#endif /* _MONKEY_ */
