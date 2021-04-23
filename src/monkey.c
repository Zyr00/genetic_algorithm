#include "../includes/monkey.h"
#include "../includes/utils.h"

char *monkey_solution;

/**
 * @brief generate random genome for the monkey problem
 * @param length the length of the string for the monkey problem
 * @return a void pointer of the string
 */
void *monkey_random_genome(const size_t length) {
  char *randomString;
  size_t n;

  if (length) {
    randomString = malloc(sizeof(char) * (length + 1));

    if (randomString) {
      for (n = 0; n < length; n++) {
        randomString[n] = random_char();
      }
      randomString[length] = '\0';
    }
  }
  return randomString;
}

/**
 * @brief calculate the fitness of the genome of the monkey problem
 * @param pop the population
 * @param size the size of the genome
 * @return the new fitness
 */
float calc_monkey_fitness(const POPULATION pop, const size_t size) {
  size_t i;
  float new_fitness = 0;
  char *genes = (char *) pop.genes;

  for (i = 0; i < size; i++) {
    if (genes[i] == monkey_solution[i])
      new_fitness++;
  }

  return new_fitness / size;
}

/**
 * @brief the crossover function of the monkey problem
 * @param first the pointer of the fittest expecimen
 * @param second the pointer of the second fittest expecimen
 * @param crossover_point the point to crossover
 */
void monkey_crossover(POPULATION *const first, POPULATION *const second, const int crossover_point) {
  int i;
  char *first_genes = first->genes;
  char *second_genes = second->genes;

  char tmp;
  for (i = 0; i < crossover_point; i++) {
    tmp = first_genes[i];
    first_genes[i] = second_genes[i];
    second_genes[i] = tmp;
  }

  first->genes = first_genes;
  second->genes = second_genes;
}

/**
 * @brief the mutation function to mutate the genome
 * @param first a pointer of the fittest expecimen
 * @param second a pointer of the second fittest expecimen
 * @param mutation_point_1 a random position in the array to mutate for the fittest
 * @param mutation_point_2 a random position in the array to mutate for the second fittest
 */
void monkey_mutation(POPULATION *const first, POPULATION *const second, const int mutation_point_1, const int mutation_point_2) {
  char *first_genes = first->genes;
  char *second_genes = second->genes;

  if (first_genes[mutation_point_1] != monkey_solution[mutation_point_1])
    first_genes[mutation_point_1] = random_char();

  if (second_genes[mutation_point_2] != monkey_solution[mutation_point_2])
    first_genes[mutation_point_2] = random_char();

  first->genes = first_genes;
  second->genes = second_genes;
}

/**
 * @brief free memory from the monkey problem
 * @param pop the population
 */
void monkey_free(POPULATION *pop) {
  free(pop->genes);
  free(pop);
}
