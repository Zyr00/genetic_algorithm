package problems;

import genetic.IIndividual;
import utils.Utils;
import java.util.Arrays;

public class Monkey implements IIndividual {
    public static char[] solution;
    private char[] chromosomes;
    private float fitness;

    public Monkey() {
        this.chromosomes = null;
        this.fitness = -1;
    }

    public Monkey(char[] chromosomes) {
        this.chromosomes = chromosomes;
        this.fitness = -1;
    }

    /**
     * Getter for chromosomes
     * @return the chromosomes array
     */
    public char[] getChromosomes() { return this.chromosomes; }

    @Override
    public float getFitness() { return this.fitness; }

    @Override
    public float fitness() {
        float fitness = 0;
        for (int i = 0; i < chromosomes.length; i++)
            if (chromosomes[i] == solution[i])
                fitness++;
        fitness = fitness / chromosomes.length;
        this.fitness = fitness;
        return this.fitness;
    }

    @Override
    public IIndividual generate(final int size) {
        char[] chromosomes = new char[size];
        for (int i = 0; i < size; i++)
            chromosomes[i] = Utils.generate_char();
        return new Monkey(chromosomes);
    }

    @Override
    public IIndividual crossover(final IIndividual B, final float uniform) {
        Monkey m = (Monkey) B;
        char[] c = new char[m.getChromosomes().length];
        for (int i = 0; i < this.chromosomes.length; i++) {
            if (Math.random() < uniform) {
                c[i] = this.chromosomes[i];
            } else {
                c[i] = m.getChromosomes()[i];
            }
        }
        return new Monkey(c);
    }

    @Override
    public IIndividual mutate(final float mutaion_freq) {
        for (int i = 0; i < chromosomes.length; i++) {
            if (Math.random() < mutaion_freq)
                this.chromosomes[i] = Utils.generate_char();
        }
        return new Monkey(this.chromosomes);
    }

    @Override
    public String toString() {
        return Arrays.toString(chromosomes);
    }
}
