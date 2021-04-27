package main;

import genetic.GeneticAlgorithm;
import genetic.Population;
import problems.Monkey;

import java.util.List;

public class Main {
    public static final int MAX_POP = 20;
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

        Population pop = Population.init_populations(MAX_POP, CHOMOSOME_SIZE, new Monkey());
        fitness = Population.calc_fitness(pop);

        System.out.println("###############################################");
        System.out.println("##############   BEFORE  CROSSOVER #############");
        System.out.println("###############################################");
        pop.getIndividuals().forEach(i -> System.out.println(i.toString()));

        while (fitness < 1) {
            Population p = GeneticAlgorithm.selection(pop, ELITISM);
            p = GeneticAlgorithm.crossover(pop, p, ELITISM, CROSSOVER_FREQ, CROSSOVER_UNIFORM);
            fitness = Population.calc_fitness(p);
            p = GeneticAlgorithm.mutation(p, MUTATION_FREQ);
            fitness = Population.calc_fitness(p);
            pop = p;
            generation++;
            System.out.println(generation);
        }

        // pop.getIndividuals().forEach(i -> System.out.println(i.toString()));
    }
}
