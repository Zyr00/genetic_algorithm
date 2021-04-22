#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../includes/utils.h"
#include "../includes/monkey.h"
#include "../includes/knapsack.h"

void monkey_fun(void);
void knapsack_fun(void);
void run_ex(const char *const, void (*f)(void));

/**
 * @brief the main method
 */
int main(void) {
  time_t t;
  srand((unsigned) time(&t));

  run_ex("Run monkey problem [y/N]: ", monkey_fun);
  run_ex("\n\nRun knapsack problem [y/N]: ", knapsack_fun);
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
void monkey_fun(void) {
  population *pop, first_fittest, second_fittest;
  clock_t time;
  size_t pop_size, gen_size;
  float mutation_value, fitness;
  char res;
  int generation;

  read_char(&res, "Use default values [Y/n]: ");
  if (res == 'n' || res == 'N') {
    char str[250];
    read_string(str, 250, "Enter solution: ");
    monkey_solution = str;
    read_size_t(&pop_size, "Enter population size: ");
    gen_size = strlen(monkey_solution);
    read_float(&mutation_value, "Enter mutation: ");
  } else {
    monkey_solution = MONKEY_DEFAULT_SOLUTION;
    mutation_value = MONKEY_DEFAULT_MUTATION;
    pop_size = MONKEY_DEFAULT_POP_SIZE;
    gen_size = MONKEY_DEFAULT_GEN_SIZE;
  }

  generation = 0;

  printf("\nSolution        -> %s", monkey_solution);
  printf("\nPopulation size -> %lu", pop_size);
  printf("\nGenome size     -> %lu", gen_size);
  printf("\nMutaion value   -> %f", mutation_value);

  time = clock();
  pop = generate_population(pop_size, gen_size, monkey_random_genome);
  fitness = calc_fitness(pop, pop_size, gen_size, calc_monkey_fitness);

  while (fitness != 1) {
    generation++;

    selection(pop, pop_size, &first_fittest, &second_fittest);
    crossover(&first_fittest, &second_fittest, gen_size, monkey_crossover);

    if (random_float(2) <= mutation_value)
      mutation(&first_fittest, &second_fittest, gen_size, monkey_mutation);

    fittest_offspring(pop, pop_size, &first_fittest, &second_fittest, gen_size, calc_monkey_fitness);
    fitness = calc_fitness(pop, pop_size, gen_size, calc_monkey_fitness);
  }

  time = clock() - time;

  printf("\n\nIt took %f seconds", ((double) time)/CLOCKS_PER_SEC);
  printf("\nSolution found in generation %d", generation);
  printf("\n(%3d) -> \"%s\" %.3f", generation, ((char *) first_fittest.genes), first_fittest.fitness);

  free(pop);
}

/**
 * @brief the genetic algorithm for the knapsack problem
 */
void knapsack_fun(void) {
  population *pop, first_fittest, second_fittest;
  clock_t time;
  size_t pop_size, gen_size, i;
  float mutation_value;
  char res;
  int generation;

  read_char(&res, "Use default values [Y/n]: ");
  if (res == 'n' || res == 'N') {
    read_size_t(&pop_size, "Enter population size: ");
    read_size_t(&gen_size, "Enter genome size: ");
    read_float(&mutation_value, "Enter mutation: ");
    read_unsigned_short(&knapsack_weight, "Knapsack weight: ");
    read_unsigned_short(&item_max_value, "Enter max value of item: ");
    read_unsigned_short(&item_max_weight, "Enter max weight of item: ");
  } else {
    mutation_value = KNAPSACK_DEFAULT_MUTATION;
    pop_size = KNAPSACK_DEFAULT_POP_SIZE;
    gen_size = KNAPSACK_DEFAULT_GEN_SIZE;
    knapsack_weight = KNAPSACK_DEFAULT_WEIGHT;
    item_max_weight = ITEM_MAX_WEIGHT;
    item_max_value = ITEM_MAX_VALUE;
  }

  generation = 0;

  items = generate_items(gen_size);
  print_items(gen_size, NULL);
  time = clock();
  pop = generate_population(pop_size, gen_size, knapsack_random_genome);
  calc_fitness(pop, pop_size, gen_size, calc_knapsack_fitness);

  while (generation < 100) {
    generation++;

    selection(pop, pop_size, &first_fittest, &second_fittest);
    crossover(&first_fittest, &second_fittest, gen_size, knapsack_crossover);

    if (random_float(2) <= mutation_value)
      mutation(&first_fittest, &second_fittest, gen_size, knapsack_mutation);

    fittest_offspring(pop, pop_size, &first_fittest, &second_fittest, gen_size, calc_knapsack_fitness);
    calc_fitness(pop, pop_size, gen_size, calc_knapsack_fitness);
  }

  time = clock() - time;
  printf("\nIt took %f seconds", ((double) time)/CLOCKS_PER_SEC);
  printf("\nGeneration: (%3d) -> Fitness: %.3f\n", generation, first_fittest.fitness);
  printf("The fittest: \t [");
  for (i = 0; i < gen_size; i++) printf("%hu", ((knapsack *) first_fittest.genes)->inside[i]);
  printf("]\n");
  print_items(gen_size, ((knapsack *) first_fittest.genes));

  knapsack_free(pop);
}
