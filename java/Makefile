SRC_DIR := src
OUT_DIR := out

SRCS := $(shell find $(SRC_DIR) -name "*.java")
CLS := $(SRCS:$(SRC_DIR)/%.java=$(OUT_DIR)/%.class)

JC := javac
J := java
JCFLAGS := -d $(OUT_DIR)/ -cp $(SRC_DIR)/
EXEC := main.Main

.PHONY: all clean

all: $(CLS)
	@echo $(SRCS)

$(CLS): $(OUT_DIR)/%.class: $(SRC_DIR)/%.java
	@mkdir -p $(OUT_DIR)
	$(JC) $(JCFLAGS) $<

run:
	$(J) -cp $(OUT_DIR) $(EXEC)

clean:
	rm -rf $(OUT_DIR)
