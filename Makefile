CC = gcc
CFLAGS = -Iinclude
SRC = src/makeSvg.c src/main.c
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))
EXEC = build/svg_program

all: $(EXEC)

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJ)
	@mkdir -p build
	$(CC) -o $@ $^ -lm  


clean:
	rm -f build/*.o build/svg_program 
