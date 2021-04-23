#ifndef _GENETIC_
#define _GENETIC_

#include <stdlib.h>

typedef struct {
  void *genes;
  double fitness;
} POPULATION;

POPULATION *generate_population(const size_t, void *);
float calc_fitness(POPULATION *, const size_t, const size_t, float (*c)(const POPULATION, const size_t));
void selection(POPULATION *, const size_t, POPULATION *, POPULATION *);
void crossover(POPULATION *, POPULATION *, const size_t, void (*c)(POPULATION *, POPULATION *, const int));
void mutation(POPULATION *, POPULATION *, const size_t, const float, void (*m)(POPULATION *, POPULATION *, const int, const int));
size_t smallest_fittnes(POPULATION *pop, const size_t size);
void fittest_offspring(POPULATION *, const size_t, POPULATION *, POPULATION *, const size_t, float (*c)(const POPULATION, const size_t));

#endif /* _GENETIC_ */
