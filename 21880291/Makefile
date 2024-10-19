CC = gcc
CFLAGS = -Iinclude
SRC = src/binary_tree.c src/queue.c src/main.c
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))
EXEC = build/dictionary

all: $(EXEC)

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJ)
	@mkdir -p build
	$(CC) -o $@ $^

clean:
	rm -f build/*.o build/dictionary
