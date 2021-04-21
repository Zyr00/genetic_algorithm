#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "monkey.h"
#include "knapsack.h"

void monkey(void);
void knapsack(void);
void run_ex(const char *const, void (*f)(void));

/**
 * @brief the main method
 */
int main(void) {
  time_t t;
  srand((unsigned) time(&t));

  run_ex("Run ex1 [y/N]: ", monkey);
  run_ex("Run ex2 [y/N]: ", knapsack);
  return 0;
}

/**
 * @brief function to has a y or n question
 * @param val a string
 * @param f a function to run (no params)
 */
void run_ex(const char *const val, void (*f)(void)) {
  char res;
  read_char(&res, val);
  if (res == 'y' || res == 'Y')
    f();
}

/**
 * @brief the genetic algorithm for the monkey problem
 */
void monkey(void) {
  monkey_solution = MONKEY_DEFAULT_SOLUTION;
  size_t pop_size = MONKEY_DEFAULT_POP_SIZE;
  size_t gen_size = MONKEY_DEFAULT_GEN_SIZE;
  float mutation_value = MONKEY_DEFAULT_MUTATION;

  char res;
  read_char(&res, "Use default values [Y/n]: ");
  if (res == 'n' || res == 'N') {
    char str[250];
    read_string(str, 250, "Enter solution: ");
    monkey_solution = str;
    read_size_t(&pop_size, "Enter population size: ");
    gen_size = strlen(monkey_solution);
    read_float(&mutation_value, "Enter mutation: ");
  }

  printf("\nSolution        -> %s", monkey_solution);
  printf("\nPopulation size -> %lu", pop_size);
  printf("\nGenome size     -> %lu", gen_size);
  printf("\nMutaion value   -> %f", mutation_value);

  int generation = 0;
  float fitness = 0;

  population first_fittest;
  population second_fittest;

  population *pop = generate_population(pop_size, gen_size, monkey_random_genome);
  fitness = calc_fitness(pop, pop_size, gen_size, calc_monkey_fitness);

  while (fitness != 1) {
    generation++;

    selection(pop, pop_size, &first_fittest, &second_fittest);
    crossover(&first_fittest, &second_fittest, gen_size, monkey_crossover);

    if ((rand() % 10) <= mutation_value)
      mutation(&first_fittest, &second_fittest, gen_size, monkey_mutation);

    fittest_offspring(pop, pop_size, &first_fittest, &second_fittest, gen_size, calc_monkey_fitness);
    fitness = calc_fitness(pop, pop_size, gen_size, calc_monkey_fitness);
  }

  printf("\n\nSolution found in generation %d", generation);
  printf("\n(%3d) -> \"%s\" %.3f", generation, ((char *) first_fittest.genes), first_fittest.fitness);
  printf("\nGenes: [");

  size_t i;
  for (i = 0; i < gen_size; i++) {
    printf("'%c'", ((char *) first_fittest.genes)[i]);
    if (i < gen_size - 1)
      printf(", ");
  }
  printf("]\n");

  free(pop);
}

/**
 * @brief the genetic algorithm for the knapsack problem
 */
void knapsack(void) {
  size_t pop_size = KNAPSACK_DEFAULT_POP_SIZE;
  size_t gen_size = KNAPSACK_DEFAULT_GEN_SIZE;
  float mutation_value = KNAPSACK_DEFAULT_MUTATION;

  // int generation = 0;
  // float fitness = 0;

  population *pop = generate_population(pop_size, gen_size, knapsack_random_genome);
  // fitness = calc_fitness(pop, pop_size, gen_size, calc_knapsack_fitness);

  size_t i, j;
  for (i = 0; i < pop_size; i++) {
    printf("\nExpecimen: %lu\n", i);
    for (j = 0; j < gen_size; j++) {
      printf("(%2lu) -> ", j);
      printf("Value: %3f\t", ((item *) pop[i].genes)[j].value);
      printf("Weight: %3f\n", ((item *) pop[i].genes)[j].weight);
    }
  }
}
