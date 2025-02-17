CXX = g++
CXXFLAGS = -Wall -std=c++98
CXXDEBUGFLAGS = -fsanitize=address -fsanitize=undefined -g

BIN     := bin
SRC     := src
INCLUDE := include
LIB     := lib
LIBRARIES   :=
EXECUTABLE  := main

# Define the source files manually (only compile what you explicitly list)
CXXFILES := dll.cpp test_dll.cpp

# Convert filenames to full paths
OBJ_FILES := $(patsubst %.cpp, $(BIN)/%.o, $(CXXFILES))



.PHONY: all run debug clean fresh test

all: $(BIN)/$(EXECUTABLE)

run: clean all
	@clear
	@echo "🚀 Executing..."
	@./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJ_FILES)
	@echo "🚧 Building..."
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

$(BIN)/%.o: $(SRC)/%.cpp
	@echo "🛠 Compiling $<..."
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c $< -o $@

# Test target: explicitly compiles only the test file and necessary sources
TEST_FILE ?= test_dll.cpp

test: $(BIN)/test_exec
	@echo "🧪 Running Tests..."
	@./$(BIN)/test_exec

$(BIN)/test_exec: $(SRC)/$(TEST_FILE) $(BIN)/dll.o
	@echo "🛠 Building test executable..."
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -o $@ $^

debug: CXXFLAGS += $(CXXDEBUGFLAGS)
debug: fresh all
	@echo "🔍 Debug build complete!"

clean:
	@echo "🧹 Clearing..."
	-rm -rf $(BIN)/*

fresh: clean all
	@echo "🔄 Fresh build complete!"
