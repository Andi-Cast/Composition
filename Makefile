CXX = g++

CXXFLAGS = -std=c++11

EXE = assignment2

SRC = driver.cpp

OBJ = $(SRC:.cpp=.o)

all: $(EXE)

Test: driver.o
	g++ -std=c++11 -o driver.o Test

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ) $(EXE)

# Run the executable
run: $(EXE)
	./$(EXE)