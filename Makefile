CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

SRC_DIR  := .
INC_DIR  := include
CLI_DIR  := cli
TEST_DIR := tests
BUILD_DIR := build

TARGET := point-plane-cpp

SRC := Main.cpp

INCLUDES := -I$(INC_DIR) -I$(CLI_DIR)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
	rm -rf $(BUILD_DIR)

.PHONY: all run clean