#include "genetic.h"
#include <stdio.h>

/**
 * @breif function to generate a population
 * @param pop_size the size of the population
 * @param genome_size the size of the genome
 * @param (*f)(size_t) a function that return a void pointer
 * @return a pointer with the new population
 */
population *generate_population(const size_t pop_size, const size_t genome_size,
    void *(*f)(const size_t)) {

  population *pop;
  size_t i;

  if (pop_size) {
    pop = malloc(sizeof(population) * pop_size);
    if (pop) {
      for (i = 0; i < pop_size; i++) {
        pop[i].genes = f(genome_size);
        pop[i].fitness = 0;
      }
    }
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
float calc_fitness(population *const pop, const size_t pop_size, const size_t genome_size,
    float (*c)(const population, const size_t)) {

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
void selection(population *const pop, const size_t size, population *fittest, population *second_fittest) {
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
void crossover(population *first_fittest, population *second_fittest, const size_t size,
    void (*c)(population *, population *, const int)) {
  c(first_fittest, second_fittest, rand() % size);
}

/**
 * @brief a function that calls another function to do the mutation
 * @param first a pointer to the fittest expecimen
 * @param second a pointer to the second expecimen
 * @param size the size of the genome
 * @param (*c)(population *, population *, int, int) the function that does the mutation
 */
void mutation(population *first, population *second, const size_t size,
    void (*m)(population *, population *, const int, const int)) {
  m(first, second, rand() % size, rand() % size);
}

/**
 * @brief the smallest fittnes on the population
 * @param pop a pointer of the population
 * @param size the size of the population
 * @return the index of the smallest fittnes
 */
size_t smallest_fittnes(population *const pop, const size_t size) {
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
 * @param pop a pointer of the population
 * @param pop_size the size of the population
 * @param first a pointer to the fittest expecimen
 * @param second a pointer to the second expecimen
 * @param genome_size the size of the genome
 * @param (*c)(population, size_t) the function to calculat the fitness of a expecimen
 */
void fittest_offspring(population *const pop, const size_t pop_size, population *first, population *second,
    const size_t genome_size, float (*c)(const population, const size_t)) {

  first->fitness = c(*first, genome_size);
  second->fitness = c(*second, genome_size);

  if (first->fitness > second->fitness) {
    pop[smallest_fittnes(pop, pop_size)] = *first;
  } else {
    pop[smallest_fittnes(pop, pop_size)] = *second;
  }
}
