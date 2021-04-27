package genetic;

import utils.Utils;

import java.util.List;

public class GeneticAlgorithm {
    public GeneticAlgorithm() {}

    /**
     * Select the best from the population
     * @param pop the population
     * @param elitism the number to select from the population
     * @return a new population list
     */
    public static Population selection(Population pop, final int elitism) {
        Population.sort_population(pop);
        return Population.elitism(pop.getIndividuals(), elitism);
    }

    /**
     * Crossover the population
     * @param pop the population
     * @param elist the elits from the population
     * @param elitism the number of elits
     * @param freq the frequency of the crossover
     * @param uniform the uniform value for the crossover
     * @return a new population with the elits and the crossover results
     */
    public static Population crossover(Population pop, Population elits, final int elitism, final float freq, final float uniform) {
        List<IIndividual> pop_individuals = pop.getIndividuals();
        List<IIndividual> elit_individuals = elits.getIndividuals();
        int pop_size = pop.getIndividuals().size();
        for (int i = elitism -1; i < pop_size; i++) {
            if (Math.random() < freq)  {
                IIndividual A = pop_individuals.get(i);
                IIndividual B = pop_individuals.get(Utils.generate_int(pop_size));
                IIndividual C = A.crossover(A, B, uniform);
                elit_individuals.add(C);
            } else {
                elit_individuals.add(pop_individuals.get(i));
            }
        }
        return new Population(elit_individuals);
    }

    public static Population mutation(Population elits, final float mutation_freq) {
        List<IIndividual> elit_individuals = elits.getIndividuals();
        int size = elit_individuals.size();
        for (int i = 0; i < size; i++) {
            elit_individuals.get(i).mutate(mutation_freq);
        }
        return new Population(elit_individuals);
    }
}
