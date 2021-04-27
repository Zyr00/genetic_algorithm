package genetic;

import utils.Utils;
import java.util.List;

public class GeneticAlgorithm {
    private int elitism;
    private float crossover_freq, crossover_uniform, mutation_freq;

    public GeneticAlgorithm(final int elitism, final float crossover_freq, final float crossover_uniform, final float mutation_freq) {
        this.elitism = elitism;
        this.crossover_freq = crossover_freq;
        this.crossover_uniform = crossover_uniform;
        this.mutation_freq = mutation_freq;
    }

    /**
     * Select the best from the population
     * @param pop the population
     * @param elitism the number to select from the population
     * @return a new population list
     */
    public Population selection(Population pop) {
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
    public Population crossover(Population pop, Population elits) {
        List<IIndividual> pop_individuals = pop.getIndividuals();
        List<IIndividual> elit_individuals = elits.getIndividuals();

        int pop_size = pop.getIndividuals().size();
        for (int i = elitism -1; i < pop_size; i++) {
            if (Math.random() < crossover_freq)  {
                IIndividual A = pop_individuals.get(i);
                IIndividual B = pop_individuals.get(Utils.generate_int(pop_size));
                IIndividual C = A.crossover(A, B, crossover_uniform);
                elit_individuals.add(C);
            } else {
                elit_individuals.add(pop_individuals.get(i));
            }
        }
        return new Population(elit_individuals);
    }

    /**
     * Mutate the population
     * @param elits the population elits
     */
    public Population mutation(Population elits) {
        List<IIndividual> elit_individuals = elits.getIndividuals();
        int size = elit_individuals.size();
        for (int i = 0; i < size; i++)
            elit_individuals.get(i).mutate(mutation_freq);
        return new Population(elit_individuals);
    }
}
