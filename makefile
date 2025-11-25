CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Iinclude

# Encontre TODOS os .cpp dentro de src/ e suas subpastas
SRC = $(shell find src -name "*.cpp")

# Converta cada src/xxx.cpp → build/xxx.o
OBJ = $(patsubst src/%.cpp, build/%.o, $(SRC))

TARGET = indice

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Regra para compilar qualquer arquivo src/.../*.cpp
build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build $(TARGET)
