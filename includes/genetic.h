#ifndef _GENETIC_
#define _GENETIC_

#include <stdlib.h>

typedef struct {
  void *genes;
  double fitness;
} population;

population *generate_population(const size_t, void *);
float calc_fitness(population *, const size_t, const size_t, float (*c)(const population, const size_t));
void selection(population *, const size_t, population *, population *);
void crossover(population *, population *, const size_t, void (*c)(population *, population *, const int));
void mutation(population *, population *, const size_t, void (*m)(population *, population *, const int, const int));
size_t smallest_fittnes(population *pop, const size_t size);
void fittest_offspring(population *, const size_t, population *, population *, const size_t, float (*c)(const population, const size_t));

#endif /* _GENETIC_ */
