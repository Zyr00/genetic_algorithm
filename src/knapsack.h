#ifndef _KNAPSACK_
#define _KNAPSACK_

#include <stdio.h>
#include <stdlib.h>
#include "genetic.h"

#define KNAPSACK_DEFAULT_SOLUTION "test"
#define KNAPSACK_DEFAULT_POP_SIZE 20
#define KNAPSACK_DEFAULT_GEN_SIZE 15
#define KNAPSACK_DEFAULT_MUTATION 0.02

typedef struct {
  float weight;
  float value;
} item;

extern item *knapsack_solution;

void *knapsack_random_genome(const size_t);
float calc_knapsack_fitness(const population, const size_t);
void knapsack_crossover(population *const, population *const, const int);
void knapsack_mutation(population *const, population *const, const int, const int);

#endif /* _KNAPSACK_ */
