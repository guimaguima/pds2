CC = g++
CFLAGS = -std=c++11 -Wall

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

all: vpl_execution

$(BUILD_DIR)/list.o: $(INCLUDE_DIR)/list.hpp $(SRC_DIR)/list.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/list.cpp -o $(BUILD_DIR)/list.o

$(BUILD_DIR)/main.o: $(INCLUDE_DIR)/list.hpp $(SRC_DIR)/main.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

vpl_execution: $(BUILD_DIR)/main.o $(BUILD_DIR)/list.o
	$(CC) $(CFLAGS) $(BUILD_DIR)/main.o $(BUILD_DIR)/list.o -o vpl_execution

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/main
