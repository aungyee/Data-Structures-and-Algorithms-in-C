CC = gcc
BUILD_DIR = build
SRC_DIR = src
INCLUDES_DIR = includes
TEST_DIR = tests
FLAGS = -Wall -g -I$(INCLUDES_DIR)

.PHONY: all clean build

# Default target
all: build $(BUILD_DIR)/test-static-sequence

# Ensure the build directory exists
build:
	mkdir -p $(BUILD_DIR)

# Compile object file for static-sequence.c
$(BUILD_DIR)/static-sequence.o: $(SRC_DIR)/static-sequence.c $(INCLUDES_DIR)/static-sequence.h
	$(CC) $(FLAGS) -c $< -o $@

# Compile object file for test-static-sequence.c
$(BUILD_DIR)/test-static-sequence.o: $(TEST_DIR)/test-static-sequence.c $(INCLUDES_DIR)/static-sequence.h
	$(CC) $(FLAGS) -c $< -o $@

# Link the test executable
$(BUILD_DIR)/test-static-sequence: $(BUILD_DIR)/static-sequence.o $(BUILD_DIR)/test-static-sequence.o
	$(CC) $^ -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

