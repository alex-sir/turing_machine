# Alex Carbajal
# CPT_S 322, Spring 2025
# Turing Machine

# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -Wextra
# Debugging flag
LDFLAGS = -g

# Directory names
SRC_DIR = src
BUILD_DIR = build
# Executable name
BIN = tm

# Source & object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(notdir $(SRCS)))

# Default target produced by entering "make" alone
.PHONY: default
default: $(BIN)

# Compile *.cpp into *.o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link *.o files into an executable
$(BIN): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

# Remove *.o files, but leave executable
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# Remove all files that can be reconstructed through "make"
.PHONY: immaculate
immaculate: clean
	rm -f $(BIN)
