package genetic;

import java.util.List;
import java.util.ArrayList;

public class Population {
    private List<IIndividual> individuals;
    public List<IIndividual> getIndividuals() { return individuals; }

    public Population() {
        this.individuals = new ArrayList<>();
    }

    public Population(IIndividual in) {
        this.individuals.add(in);
    }

    public Population(List<IIndividual> individuals) {
        this.individuals = individuals;
    }

    /**
     * Total fitness of the population
     * @return the total fitness
     */
    public double getTotalFitness() {
        return individuals.stream().mapToDouble((a) -> a.getFitness()).sum();
    }

    /**
     * Generate a population of {@link IIndividual}
     * @param p_size the size of the population
     * @param chromosome_size the size of the chromosome
     * @param individual the type of {@link IIndividual}
     * @return a new population
     */
    public static Population init_populations(final int p_size, final int chromosome_size, IIndividual individual) {
        Population p = new Population();
        for (int i = 0; i < p_size; i++)
            p.getIndividuals().add(individual.generate(chromosome_size));
        return p;
    }

    /**
     * Calculate the fitness of every {@link IIndividual} and return the max fitness
     * @param pop the population list
     * @return the best fitness
     */
    public static float calc_fitness(Population pop) {
        List<IIndividual> individuals = pop.getIndividuals();
        float f, fitness = 0;
        int size = individuals.size();
        for (int i = 0; i < size; i++) {
            f = individuals.get(i).fitness();
            if (fitness < f) fitness = f;
        }
        return fitness;
    }

    /**
     * Select the best from the population
     * @param individuals the list of {@link IIndividual} from the population
     * @param elitism the max number of elits to chouse
     * @return a new population with the elists
     */
    public static Population elitism(List<IIndividual> individuals, final int elitism) {
        List<IIndividual> in = new ArrayList<>();
        for (int i = 0; i < elitism; i++)
            in.add(individuals.get(i));
        return new Population(in);
    }

    /**
     * Sort population
     * @param pop the population list
     */
    public static void sort_population(Population pop) {
        pop.getIndividuals().sort((i1, i2) -> {
            if (i1.fitness() < i2.fitness()) return 1;
            if (i1.fitness() > i2.fitness()) return -1;
            return 0;
        });
    }
}
