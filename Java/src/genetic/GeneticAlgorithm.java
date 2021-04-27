package genetic;

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
     */
    public void selection(Population pop) {
        Population.sort_population(pop);
        pop = Population.elitism(pop.getIndividuals(), elitism);
    }

    /**
     * Crossover the population
     * @param pop the population
     * @param elitism the number of elits
     * @param freq the frequency of the crossover
     * @param uniform the uniform value for the crossover
     */
    public void crossover(Population pop) {
        List<IIndividual> pop_individuals = pop.getIndividuals();
        int pop_size = pop.getIndividuals().size();
        for (int i = elitism - 1; i < pop_size; i++) {
            IIndividual parentA = pop_individuals.get(0);
            if (Math.random() < crossover_freq) {
                IIndividual parentB = selectParent(pop_individuals, pop_size, pop.getTotalFitness());
                pop_individuals.set(i, parentA.crossover(parentB, crossover_uniform));
            } else {
                pop_individuals.set(i, parentA);
            }
        }
    }

    /**
     * Select parent with the wheel method
     * @param individuals the {@link IIndividual} of the population
     * @param size the size of the individuals
     * @param total_fitness the total fitness of the individuals
     * @return the {@link IIndividual}
     */
    public IIndividual selectParent(List<IIndividual> individuals, final int size, final double total_fitness) {
        final double roulettWheelPosition = Math.random() * total_fitness;
        double wheel = 0;
        for (int i = 0; i < size; i++) {
            wheel += individuals.get(i).getFitness();
            if (wheel >= roulettWheelPosition) return individuals.get(i);
        }
        return individuals.get(size - 1);
    }

    /**
     * Mutate the population
     * @param pop the population
     */
    public void mutation(Population pop) {
        List<IIndividual> individuals = pop.getIndividuals();
        final int size = individuals.size();
        for (int i = 0; i < size; i++)
            individuals.get(i).mutate(mutation_freq);
    }
}
