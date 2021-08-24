SRC = $(wildcard ./src/*.cpp)
OBJ = $(SRC:.cpp=.o)
CC = g++
TARGET = quadratic.out

all: out
	./$(TARGET)

check: out
	valgrind ./$(TARGET)

out: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) -lm 

bin: $(OBJ)
	$(CC) -o3 -s $(OBJ) -lm -o $(TARGET)
	make clean

clean: 
	rm -f $(OBJ)

fclean: 
	rm -f $(OBJ) $(TARGET)
