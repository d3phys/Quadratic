SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
CC = g++
TARGET = quadratic.out

all: out
	./$(TARGET)


out: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) -lm

clean: 
	rm -f $(OBJ) $(TARGET)
