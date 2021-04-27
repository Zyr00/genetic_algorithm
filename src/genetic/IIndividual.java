package genetic;

public interface IIndividual {
    public float getFitness();
    public float fitness();
    public IIndividual generate(final int size);
    public IIndividual crossover(final IIndividual B, final float uniform);
    public IIndividual mutate(final float mutaion_freq);
}
