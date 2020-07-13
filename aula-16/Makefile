OBJS = main.o Funcionario.o Empresa.o
SOURCE = src/main.cpp src/Funcionario.cpp src/Empresa.cpp
HEADER = include/Funcionario.hpp include/Empresa.hpp
OUT = controle-funcionarios
CC = g++
FLAGS = -g -c -Wall -I include
LFLAGS = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp $(FLAGS)

Funcionario.o: src/Funcionario.cpp
	$(CC) $(FLAGS) src/Funcionario.cpp $(FLAGS)

Empresa.o: src/Empresa.cpp
	$(CC) $(FLAGS) src/Empresa.cpp $(FLAGS)


clean:
	rm -f $(OBJS) $(OUT)
	rm -rf cliente_*