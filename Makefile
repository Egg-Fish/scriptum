CC = clang
CFLAGS = -Wall -Wextra -std=c99 -Isrc -Iunity
LDFLAGS = 

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = test
UNITY_DIR = external/unity

TARGET = scriptum

# Recursive wildcard function
rwildcard=$(foreach d,$(wildcard $(1:=*)),$(call rwildcard,$(d)/,$(2))$(filter $(subst *,%,$(2)),$(d)))

# Production Sources
SRCS = $(call rwildcard, $(SRC_DIR)/, *.c)
# Filter out main.c so it doesn't clash with test main() functions
LIB_OBJS = $(filter-out $(OBJ_DIR)/main.o, $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o))
MAIN_OBJ = $(OBJ_DIR)/main.o

# Test Sources
TEST_SRCS = $(call rwildcard, $(TEST_DIR)/, *.c)
# This creates a list of binaries: bin/test/subdir/TestFoo
TEST_BINS = $(TEST_SRCS:$(TEST_DIR)/%.c=$(BIN_DIR)/test/%)

all: $(TARGET)

# Standard Build
$(TARGET): $(LIB_OBJS) $(MAIN_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $(BIN_DIR)/$(TARGET) $(LDFLAGS)

# Test execution: Build and run all test binaries
test: $(TEST_BINS)
	@for test in $(TEST_BINS); do ./$$test; done

# Rule to link each individual test executable
$(BIN_DIR)/test/%: $(OBJ_DIR)/test/%.o $(LIB_OBJS) $(OBJ_DIR)/unity.o
	@mkdir -p $(dir $@)
	$(CC) $^ -o $@ $(LDFLAGS)

# Rule for production objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for test objects
$(OBJ_DIR)/test/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(UNITY_DIR) -c $< -o $@

# Rule for Unity
$(OBJ_DIR)/unity.o: $(UNITY_DIR)/unity.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Run main.c
run: $(TARGET)
	./$(BIN_DIR)/$(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean test
