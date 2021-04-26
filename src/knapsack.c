#include "../includes/knapsack.h"
#include "../includes/utils.h"

short unsigned int knapsack_weight;
short unsigned int item_max_weight;
short unsigned int item_max_value;
ITEM *items;

/**
 * @brief generate random items with values
 * @param size the size of the array of items
 */
void generate_items(const size_t size) {
  size_t i;

  if (size <= 0) return;

  items = (ITEM *) malloc(sizeof(ITEM) * size);
  if (items == NULL) return;

  for (i = 0; i < size; i++) {
    items[i].value = random_float(item_max_value);
    items[i].weight = random_float(item_max_weight);
  }
}

/**
 * @brief generate random genome for the knapsack problem
 * @param size the number of genomes to create
 * @return a list of items
 */
void *knapsack_random_genome(const size_t size) {
  size_t i;
  KNAPSACK *knap = NULL;

  if(items == NULL) return NULL;
  if (size <= 0) return NULL;

  knap = (KNAPSACK *) malloc(sizeof(KNAPSACK));
  if (knap == NULL) return NULL;

  knap->inside = (short int *) malloc(sizeof(short int) * size);
  if (knap->inside == NULL) return NULL;

  for (i = 0; i < size; i++) knap->inside[i] = random_int(2);

  return knap;
}

/**
 * @brief calculate the fitness of the genome of the knapsack problem
 * @param pop the population
 * @param size the size of the genome
 * @return the new fitness
 */
float calc_knapsack_fitness(const POPULATION pop, const size_t size) {
  size_t i;
  float weight = 0, value = 0;
  KNAPSACK *knap = (KNAPSACK *) pop.genes;

  for (i = 0; i < size; i++) {
    if (knap->inside[i] == 1) {
      value += items[i].value;
      weight += items[i].weight;
      if (weight > knapsack_weight) return 0;
    }
  }

  return value;
}

/**
 * @brief the crossover function of the knapsack problem
 * @param first the pointer of the fittest expecimen
 * @param second the pointer of the second fittest expecimen
 * @param crossover_point the point to crossover
 */
void knapsack_crossover(POPULATION *const first, POPULATION *const second, const int crossover_point) {
  int i;
  short int tmp;
  KNAPSACK *first_knap = ((KNAPSACK *) first->genes);
  KNAPSACK *second_knap = ((KNAPSACK *) second->genes);

  for (i = 0; i < crossover_point; i++) {
    tmp = first_knap->inside[i];
    first_knap->inside[i] = second_knap->inside[i];
    second_knap->inside[i] = tmp;
  }

  first->genes = first_knap;
  second->genes = second_knap;
}

/**
 * @brief the mutation function to mutate the genome
 * @param first a pointer of the fittest expecimen
 * @param second a pointer of the second fittest expecimen
 * @param mutation_point_1 a random position in the array to mutate for the fittest
 * @param mutation_point_2 a random position in the array to mutate for the second fittest
 */
void knapsack_mutation(POPULATION *const first, POPULATION *const second, const int mutation_point_1, const int mutation_point_2) {
  ((KNAPSACK *) first->genes)->inside[mutation_point_1] = 1 - ((KNAPSACK *) first->genes)->inside[mutation_point_1];
  ((KNAPSACK *) second->genes)->inside[mutation_point_2] = 1 - ((KNAPSACK *) second->genes)->inside[mutation_point_2];
}

/**
 * @brief print a single item
 * @param i the pos of the item
 * @param value to sum the value of the item
 * @param weight to sum the weight of the item
 */
void print_item(const size_t i, float *const value, float *const weight) {
  printf("\n%2lu -> Value: %f\tWeight: %f", i + 1, items[i].value, items[i].weight);
  *value += items[i].value;
  *weight += items[i].weight;
}

/**
 * @brief print all items
 * @param size the size of the items array
 * @param knap if the items are in the knapsack
 */
void print_items(const size_t size, const KNAPSACK *const knap) {
  size_t i;
  float value = 0;
  float weight = 0;

  for (i = 0; i < size; i++) {
    if (knap) {
      if( knap->inside[i] == 1)
        print_item(i, &value, &weight);
    } else {
      print_item(i, &value, &weight);
    }
  }
  printf("\n\nTotal Value: %f\nTotal Weight: %f\n", value, weight);
}

/**
 * @brief free memory form a population
 * @param pop the population to free from memory
 */
void knapsack_free(POPULATION * pop) {
  free(((KNAPSACK *) pop->genes)->inside);
  free(pop->genes);
  free(pop);
  free(items);
}
