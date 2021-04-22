#ifndef _KNAPSACK_
#define _KNAPSACK_

#include <stdio.h>
#include <stdlib.h>
#include "genetic.h"

#define KNAPSACK_DEFAULT_WEIGHT 37
#define KNAPSACK_DEFAULT_POP_SIZE 20
#define KNAPSACK_DEFAULT_GEN_SIZE 15
#define KNAPSACK_DEFAULT_MUTATION 0.02
#define ITEM_MAX_WEIGHT 8.0
#define ITEM_MAX_VALUE 6.0

typedef struct {
  float weight;
  float value;
} item;

typedef struct {
  item *items;
  short int *inside;
} knapsack;

extern short unsigned int knapsack_weight;
extern short unsigned int item_max_weight;
extern short unsigned int item_max_value;
extern item *items;

item *generate_items(const size_t);
void *knapsack_random_genome(const size_t);
float calc_knapsack_fitness(const population, const size_t);
void knapsack_crossover(population *const, population *const, const int);
void knapsack_mutation(population *const, population *const, const int, const int);

void print_item(const size_t, float *const, float *const);
void print_items(const size_t size, const knapsack *const knap);

void knapsack_free(population *const);
#endif /* _KNAPSACK_ */
