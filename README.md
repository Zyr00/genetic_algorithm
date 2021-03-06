# Genetic Programming in java

## Introduction

This is an implementation of a genetic algorithm in java

## Problems

### The infinite monkey theorem

The infinite monkey theorem says that a monkey randomly hitting keys on a typewriter will eventually type out one of William Shakespeare's works.

### The knapsack problem

Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.

### The timetable problem

This problem consists in a creating a timetable with the following rules:
  - Classes can only be carried out in rooms that are free in a time frame;
  - A teacher can only teach a lesson un at a time;
  - The rooms should be large enough to accommodate a class.
To the solution there are a few considerations that you need to have in mind:
  - You need rooms;
  - Teachers;
  - Curricular units;
  - Class;
  - Hour Block <2h>;
  - Lessons composed of (Class, Curricular unit, Teacher, Hour Block, Room).

# Compiling and running Java version

## Configuring build

```Makefile

JC := javac
J := java
JCFLAGS := -d $(OUT_DIR)/ -cp $(SRC_DIR)/
EXEC := main.Main # The name and package of the main class

```

### Linux

- Compile with the `make` command: `make -j$(nproc)` or just `make`
- Run `make run` to run the program.

### Windows and Mac

- Windows Instruction [here](https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows#54086635)
- Mac Instruction [here](https://stackoverflow.com/questions/1469994/using-make-on-os-x)


# Compiling and running C version

## Configuring build

In the make file the `CC` variable contains the compiler, this can be changed to `clang` instead of `gcc`

```Makefile

CC = gcc
CFLAGS := -g -Wall -Wextra -pedantic

```

To change the executable name in the makefile there is a variable called `EXEC` that controls the name.

```Makefile

...
EXEC := main
...

```

### Linux

- Compile with the `make` command: `make -j$(nproc)` or just `make`
- Run `./main` or the name specified in the Makefile

### Windows and Mac

- Windows Instruction [here](https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows#54086635)
- Mac Instruction [here](https://stackoverflow.com/questions/1469994/using-make-on-os-x)

# References

## Article
 - [Introduction to Genetic Algorithms ??? Including Example Code](https://towardsdatascience.com/introduction-to-genetic-algorithms-including-example-code-e396e98d8bf3)

## Youtube
 - [Genetic Algorithms Explained By Example](https://www.youtube.com/watch?v=uQj5UNhCPuo)
 - [Genetic Algorithm from Scratch in Python (tutorial with code)](https://www.youtube.com/watch?v=nhT56blfRpE)

## Code
 - [Memento Gitalb](https://github.com/memento/GeneticAlgorithm)
 - [Kie Codes](https://github.com/kiecodes/genetic-algorithms)
