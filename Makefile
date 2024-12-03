CC = gcc
BUILD_DIR = build
SRC_DIR = src
INCLUDES_DIR = includes
TEST_DIR = tests
FLAGS = -Wall -g -I$(INCLUDES_DIR)

.PHONY: all clean build

# Default target
all: build $(BUILD_DIR)/test-static-sequence $(BUILD_DIR)/test-stack $(BUILD_DIR)/test-queue

# Ensure the build directory exists
build:
	mkdir -p $(BUILD_DIR)

# Pattern rule for compiling object files from source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES_DIR)/data_structures.h
	$(CC) $(FLAGS) -c $< -o $@

# Pattern rule for compiling test object files from test files
$(BUILD_DIR)/test-%.o: $(TEST_DIR)/test-%.c $(INCLUDES_DIR)/data_structures.h
	$(CC) $(FLAGS) -c $< -o $@

# Link rule for static-sequence test executable
$(BUILD_DIR)/test-static-sequence: $(BUILD_DIR)/static-sequence.o $(BUILD_DIR)/test-static-sequence.o
	$(CC) $^ -o $@

# Link rule for stack test executable
$(BUILD_DIR)/test-stack: $(BUILD_DIR)/stack.o $(BUILD_DIR)/test-stack.o
	$(CC) $^ -o $@

# Link rule for queue test executable
$(BUILD_DIR)/test-queue: $(BUILD_DIR)/queue.o $(BUILD_DIR)/test-queue.o
	$(CC) $^ -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

