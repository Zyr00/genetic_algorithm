CC = gcc
CFLAGS := -g -Wall -Wextra -pedantic -O0

OBJDIR = obj
SRCDIR = src
INCDIR = includes

EXEC := main
HDRS := $(shell find $(INCDIR) -name "*.h")
SRCS := $(shell find $(SRCDIR) -name "*.c")
OBJS := $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(EXEC)

$(OBJDIR)/%.o: %.c
	@echo "COMPILING SOURCE $< INTO OBJECT $@"
	@mkdir -p '$(@D)'
	@$(CC) -c $(CFLAGS) $< -o $@

$(EXEC): $(OBJS) $(HDRS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

valgrind:
	valgrind --leak-check=full -s --track-origins=yes ./$(EXEC)


clean:
	rm -rf $(EXEC) $(OBJDIR)

.PHONY: all clean
