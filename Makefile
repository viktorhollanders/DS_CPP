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

#  Build the Dll test executable.
dll: $(BIN)/test_dll
	@echo "Running DLL test..."
	@./$(BIN)/test_dll

# Define the target for the DLL test executable.
$(BIN)/test_dll: $(SRC)/test_dll.cpp $(BIN)/dll.o
	@echo "🛠 Building DLL test executable..."
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -o $@ $^

# Build the object file for dll.cpp.
$(BIN)/dll.o: $(SRC)/dll.cpp
	@echo "🛠 Compiling dll.cpp to dll.o..."
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c $(SRC)/dll.cpp -o $(BIN)/dll.o

# Build the Array test executable.
array: $(BIN)/test_array
	@echo "Running Array test..."
	@./$(BIN)/test_array

# Define the target for the Array test executable.
$(BIN)/test_array: $(SRC)/test_array.cpp $(BIN)/array.o
	@echo "🛠 Building Array test executable..."
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -o $@ $^

# Build the object file for array.cpp.
$(BIN)/array.o: $(SRC)/array.cpp
	@echo "🛠 Compiling array.cpp to array.o..."
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c $(SRC)/array.cpp -o $(BIN)/array.o

# Build the Stack test executable.
stack: $(BIN)/test_stack
	@echo "Running Stack test..."
	@./$(BIN)/test_stack

# Define the target for the Stack test executable.
$(BIN)/test_stack: $(SRC)/test_stack.cpp $(BIN)/stack.o $(BIN)/array.o
	@echo "🛠 Building Stack test executable..."
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -o $@ $^

# Build the object file for stack.cpp.
$(BIN)/stack.o: $(SRC)/stack.cpp $(INCLUDE)/stack.h $(INCLUDE)/array.h
	@echo "🛠 Compiling stack.cpp to stack.o..."
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c $(SRC)/stack.cpp -o $(BIN)/stack.o

# Build the object file for array.cpp.
$(BIN)/array.o: $(SRC)/array.cpp $(INCLUDE)/array.h
	@echo "🛠 Compiling array.cpp to array.o..."
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c $(SRC)/array.cpp -o $(BIN)/array.o

deque: $(BIN)/test_deque
	@echo "Running Deque test..."
	@./$(BIN)/test_deque

# Define the target for the Deque test executable.
$(BIN)/test_deque: $(SRC)/test_deque.cpp $(BIN)/deque.o $(BIN)/dll.o
	@echo "🛠 Building Deque test executable..."
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -o $@ $^

# Build the object file for deque.cpp.
$(BIN)/deque.o: $(SRC)/deque.cpp $(INCLUDE)/deque.h $(INCLUDE)/dll.h
	@echo "🛠 Compiling deque.cpp to deque.o..."
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c $(SRC)/deque.cpp -o $(BIN)/deque.o

# Build the object file for array.cpp.
$(BIN)/dll.o: $(SRC)/array.cpp $(INCLUDE)/array.h
	@echo "🛠 Compiling dll.cpp to dll.o..."
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c $(SRC)/dll.cpp -o $(BIN)/dll.o



debug: CXXFLAGS += $(CXXDEBUGFLAGS)
debug: fresh all
	@echo "🔍 Debug build complete!"

clean:
	@echo "🧹 Clearing..."
	-rm -rf $(BIN)/*

fresh: clean all
	@echo "🔄 Fresh build complete!"