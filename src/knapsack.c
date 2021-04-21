#include "knapsack.h"

/**
 * @brief create a random float
 *  View: https://stackoverflow.com/questions/13408990/how-to-generate-random-float-number-in-c#13409133
 * @param limit is never bigger than the limit
 */
float random_float(const float limit) {
  return ((float) rand() / (float) (RAND_MAX)) * limit;
}

/**
 * @brief generate random genome for the knapsack problem
 * @param size the number of genomes to create
 * @return a list of items
 */
void *knapsack_random_genome(const size_t size) {
  size_t i;
  item *items;

  if (size) {
    items = malloc(sizeof(item) * size);

    if (items) {
      for (i = 0; i < size; i++) {
        items[i].value = random_float(8.0);
        items[i].weight = random_float(6.0);
      }
    }
  }

  return items;
}

/**
 * @brief calculate the fitness of the genome of the knapsack problem
 * @param pop the population
 * @param size the size of the genome
 * @return the new fitness
 */
float calc_knapsack_fitness(const population pop, const size_t size) {
  size_t i;
  float new_fitness = 0;
  item *genes = (item *) pop.genes;

  for (i = 0; i < size; i++) {
    // TODO: calculate fitness for each item.
    new_fitness++;
  }

  return new_fitness / size;
}

void knapsack_crossover(population *const, population *const, const int);
void knapsack_mutation(population *const, population *const, const int, const int);
