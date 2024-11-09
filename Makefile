CC=gcc
BIN_DIR=bin
FLAGS=-Wall -g

all: bin static-sequence

bin:
		mkdir -p $(BIN_DIR)

static-sequence: static-sequence.c
		$(CC) -o $(BIN_DIR)/static-sequence $(FLAGS) static-sequence.c

clean:
		rm -rf $(BIN_DIR)

