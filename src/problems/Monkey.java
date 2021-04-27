package problems;

import genetic.IIndividual;
import utils.Utils;

public class Monkey implements IIndividual {
    public static char[] solution;
    private char[] chromosomes;
    private float fitness;

    public Monkey() {
        this.chromosomes = null;
        this.fitness = 0;
    }

    public Monkey(char[] chromosomes) {
        this.chromosomes = chromosomes;
        this.fitness = 0;
    }

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
    public IIndividual crossover(final IIndividual A, final IIndividual B, final float uniform) {
        Monkey ma = (Monkey) A;
        Monkey mb = (Monkey) B;
        char[] newchromosomes = new char[mb.getChromosomes().length];
        for (int i = 0; i < this.chromosomes.length; i++) {
            if (Math.random() < uniform)
                newchromosomes[i] = ma.getChromosomes()[i];
            else
                newchromosomes[i] = mb.getChromosomes()[i];
        }
        return new Monkey(newchromosomes);
    }

    @Override
    public IIndividual mutate(final float mutaion_freq) {
        for (int i = 0; i < chromosomes.length; i++) {
            if (Math.random() < mutaion_freq) {
                this.chromosomes[i] = Utils.generate_char();
            }
        }
        return new Monkey(this.chromosomes);
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < chromosomes.length; i++) {
            b.append(chromosomes[i]);
        }
        b.append("\t").append(fitness);
        return b.toString();
    }
}
