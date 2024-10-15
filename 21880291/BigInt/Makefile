CC = gcc
CFLAGS = -Wall -g -Iinclude
SRC_DIR = src
BUILD_DIR = build
TARGET = BigIntTest

OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/BigInt.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET) $(OBJS)

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c include/BigInt.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/BigInt.o: $(SRC_DIR)/BigInt.c include/BigInt.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/BigInt.c -o $(BUILD_DIR)/BigInt.o

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/$(TARGET)
