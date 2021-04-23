#include "../includes/genetic.h"
#include "../includes/utils.h"

/**
 * @breif function to generate a population
 * @param pop_size the size of the population
 * @param values the values to store in population genes
 * @return a pointer with the new population
 */
POPULATION *generate_population(const size_t pop_size, void *values) {
  POPULATION *pop;
  size_t i;

  if (pop_size < 0) return NULL;

  pop = malloc(sizeof(POPULATION) * pop_size);
  if (pop == NULL) return NULL;
      for (i = 0; i < pop_size; i++) {
        pop[i].genes = values;
        pop[i].fitness = 0;
      }
  return pop;
}

/**
 * @brief a function to calculate the fitness of a population
 * @param pop a pointer to the population
 * @param pop_size the size of the population
 * @param genome_size the size of the genome
 * @param (*c)(population, size_t) a function that return the fitness
 * @return the biggest fitness
 */
float calc_fitness(POPULATION *const pop, const size_t pop_size, const size_t genome_size,
    float (*c)(const POPULATION, const size_t)) {

  size_t i;
  float prev = 0, fitness = 0;

  for (i = 0; i < pop_size; i++) {
    pop[i].fitness = c(pop[i], genome_size);
    if (prev <= fitness)
      fitness = pop[i].fitness;
  }
  return fitness;
}

/**
 * @brief a function to selec the fittest and the second fittest
 * @param pop a pointer to the population
 * @param size the size of the population
 * @param fittest a pointer for the fittest expecimen
 * @param second_fittest a pointer for the second fittest expecimen
 */
void selection(POPULATION *const pop, const size_t size, POPULATION *fittest, POPULATION *second_fittest) {
  size_t maxIndex = 0, maxFit1 = 0, maxFit2 = 0, i;
  float max = 0;

  for (i = 0; i < size; i++) {

    if (max <= pop[i].fitness) {
      max = pop[i].fitness;
      maxIndex = i;
    }

    if (pop[i].fitness > pop[maxFit1].fitness) {
      maxFit2 = maxFit1;
      maxFit1 = i;
    } else if (pop[i].fitness > pop[maxFit2].fitness) {
      maxFit2 = i;
    }
  }

  *fittest = pop[maxIndex];
  *second_fittest = pop[maxFit2];
}

/**
 * @brief a function that calls another function to do the crossover
 * @param first_fittest a pointer to the fittest expecimen
 * @param second_fittest a pointer to the second expecimen
 * @param size the size of the genome
 * @param (*c)(population *, population *, int) the function that does the crossover
 */
void crossover(POPULATION *first_fittest, POPULATION *second_fittest, const size_t size,
    void (*c)(POPULATION *, POPULATION *, const int)) {
  c(first_fittest, second_fittest, rand() % size);
}

/**
 * @brief a function that calls another function to do the mutation
 * @param first a pointer to the fittest expecimen
 * @param second a pointer to the second expecimen
 * @param size the size of the genome
 * @param mutation_value the frequency of the mutation
 * @param (*c)(population *, population *, int, int) the function that does the mutation
 */
void mutation(POPULATION *first, POPULATION *second, const size_t size, const float mutation_value,
    void (*m)(POPULATION *, POPULATION *, const int, const int)) {
  if (random_float(2) <= mutation_value)
    m(first, second, rand() % size, rand() % size);
}

/**
 * @brief the smallest fittnes on the population
 * @param pop a pointer of the population
 * @param size the size of the population
 * @return the index of the smallest fittnes
 */
size_t smallest_fittnes(POPULATION *const pop, const size_t size) {
  size_t i, index = 0;
  float fitness = 1;

  for (i = 0; i < size; i++) {
    if (fitness >= pop[i].fitness) {
      fitness = pop[i].fitness;
      index = i;
    }
  }

  return index;
}

/**
 * @brief get the offspring bassed on the fittness
 * @param pop a pointer of the POPULATION
 * @param pop_size the size of the POPULATION
 * @param first a pointer to the fittest expecimen
 * @param second a pointer to the second expecimen
 * @param genome_size the size of the genome
 * @param (*c)(POPULATION, size_t) the function to calculat the fitness of a expecimen
 */
void fittest_offspring(POPULATION *const pop, const size_t pop_size, POPULATION *first, POPULATION *second,
    const size_t genome_size, float (*c)(const POPULATION, const size_t)) {

  first->fitness = c(*first, genome_size);
  second->fitness = c(*second, genome_size);

  if (first->fitness > second->fitness) {
    pop[smallest_fittnes(pop, pop_size)] = *first;
    return;
  }
  pop[smallest_fittnes(pop, pop_size)] = *second;
}
