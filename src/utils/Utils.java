package utils;

import java.util.Random;

public class Utils {
    private final static short MIN_ACSII = 32;
    private final static short MAX_ACSII = 126;

    /**
     * Generate random char betwween char 32 and char 126
     * @param max the max number to generate to
     */
    public static char generate_char() {
        Random r = new Random();
        return (char) (r.nextInt(MAX_ACSII - MIN_ACSII) + MIN_ACSII);
    }

    /**
     * Generate random number betwween 0(inclusive) and max(exclusive)
     * @param max the max number to generate to
     */
    public static int generate_int(final int max) {
        Random r = new Random();
        return r.nextInt(max);
    }
}
