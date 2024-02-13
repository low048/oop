# Define compiler
CXX=g++

# Define compiler flags
CXXFLAGS=-Wall -std=c++11

# Define the target executable
TARGET=main.exe

# Default target
all: $(TARGET)

# Rule to compile the source file directly into an executable
$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

# Clean target
clean:
	rm -f $(TARGET)
