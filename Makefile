CXX = g++
CXXFLAGS = -std=c++17 -Iincludes

SRC = main.cpp src/*.cpp
TARGET = arcturus

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
