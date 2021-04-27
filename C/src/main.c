#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../includes/utils.h"
#include "../includes/monkey.h"

void monkey_fun(void);
void run_ex(const char *const, void (*f)(void));

/**
 * @brief the main method
 */
int main(void) {
  time_t t;
  srand((unsigned) time(&t));

  // run_ex("Run monkey problem [y/N]: ", monkey_fun);
  monkey_fun();
  return 0;
}

/**
 * @brief the genetic algorithm for the monkey problem
 */
void monkey_fun(void) {
  POPULATION pop;
  clock_t time;
  size_t pop_size, gen_size;
  float mutation_value, fitness;
  char res;
  int generation;

  pop_size = MONKEY_DEFAULT_POP_SIZE;
  gen_size = MONKEY_DEFAULT_GEN_SIZE;
  monkey_solution = MONKEY_DEFAULT_SOLUTION;
  mutation_value = MONKEY_DEFAULT_MUTATION;

  time = clock();

  pop = generate_population(pop_size, gen_size, monkey_random_genome);

  size_t i;
  for (i = 0; i < pop_size; i++) {
    printf("%s\n", (char *) pop.individuals[i]);
  }

  time = clock() - time;

  printf("\n\nIt took %f seconds", ((double) time)/CLOCKS_PER_SEC);
  // printf("\nSolution found in generation %d", generation);
  free_population(&pop, pop_size);
}

/**
 * @brief function to has a y or n question
 * @param val a string
 * @param f a function to run (no params)
 */
void run_ex(const char *const val, void (*f)(void)) {
  char res;
  read_char(&res, val);
  if (res == 'y' || res == 'Y') {
    f();
    putchar('\n');
  }
}
