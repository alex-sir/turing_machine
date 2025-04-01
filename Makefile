# Alex Carbajal
# CPT_S 322, Spring 2025
# Turing Machine Implementation

# Compiler
CXX = g++

# Setting the flags
CXXFLAGS = -g -Wall

# Link in support for debugging
LDFLAGS = -g

# Name of executable
BIN = tm

# Name of object files
OBJS = src/tm.o src/utilities.o src/commands.o

# Default target produced by entering "make" alone
.PHONY: default
default: $(BIN)

# Compile *.cpp into *.o
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link *.o files into an executable
$(BIN): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

# Remove *.o files, but leave executable
.PHONY: clean
clean:
	rm -f core* src/*.o *~

# Remove all files that can be reconstructed through "make"
.PHONY: immaculate
immaculate: clean
	rm -f $(BIN)
