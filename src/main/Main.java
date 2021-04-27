package main;

import genetic.GeneticAlgorithm;
import genetic.Population;
import problems.Monkey;

public class Main {
    public static final int MAX_POP = 100;
    public static final int ELITISM = 3;
    public static final float CROSSOVER_FREQ = 0.95f;
    public static final float CROSSOVER_UNIFORM = 0.50f;
    public static final float MUTATION_FREQ = 0.01f;

    public static final String SOLUTION = "IA e a melhor UC do curso.";
    public static final int CHOMOSOME_SIZE = SOLUTION.length();

    public static void main(String[] args) {
        Monkey.solution = SOLUTION.toCharArray();
        float fitness;
        int generation = 0;

        long start = System.nanoTime();
        GeneticAlgorithm ga = new GeneticAlgorithm(ELITISM, CROSSOVER_FREQ, CROSSOVER_UNIFORM, MUTATION_FREQ);
        Population pop = Population.init_populations(MAX_POP, CHOMOSOME_SIZE, new Monkey());
        fitness = Population.calc_fitness(pop);

        while (fitness < 1) {
            ga.selection(pop);
            ga.crossover(pop);
            ga.mutation(pop);
            fitness = Population.calc_fitness(pop);
            generation++;
        }
        double elapsedTime = (System.nanoTime() - start) / 1_000_000_000.0;

        Population.sort_population(pop);
        System.out.printf("\nIt took %f\n", elapsedTime);
        System.out.printf("Solução encontrada:\t(%d) -> %s\n\n", generation, pop.getIndividuals().get(0).toString());
    }
}
