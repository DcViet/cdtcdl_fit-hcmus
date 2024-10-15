CC = gcc
CFLAGS = -Iinclude
SRC = src/binary_tree.c src/queue.c src/main.c
OBJ = $(SRC:.c=.o)
EXEC = dictionary

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJ) $(EXEC)
