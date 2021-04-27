#ifndef _GENETIC_
#define _GENETIC_

#include <stdlib.h>

typedef struct {
  void **individuals;
  double fitness;
} POPULATION;

// POPULATION *generate_population(const size_t pop_size, const size_t gen_size); // , void (*g)(char **, const size_t, const size_t));
POPULATION generate_population(const size_t, const size_t, void (*g)());
void free_population(POPULATION *, const size_t);

#endif /* _GENETIC_ */
