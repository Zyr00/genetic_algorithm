#include "../includes/genetic.h"
#include "../includes/utils.h"
#include "../includes/monkey.h"

/**
 * @brief generate population
 * @param pop_size the size of the population
 * @param chromosome_size the size of the chromosome
 */
POPULATION generate_population(const size_t pop_size, const size_t chromosome_size, void (*g)()) {
  POPULATION pop = { NULL, 0 };

  if (pop_size <= 0 || chromosome_size <= 0) return pop;
  g(&pop.individuals, pop_size, chromosome_size);

  return pop;
}

void free_population(POPULATION *pop, const size_t pop_size) {
  size_t i;
  for (i = 0; i < pop_size; i++)
    free(pop->individuals[i]);
  free(pop->individuals);
}
